#include <glog/logging.h>
#include <exception>
#include "openssl/ssl.h"

#include "sslConnection.h"

using namespace std;

SslConnection::SslConnection(const string& connectionTupple, const string& certPemFile)
	: m_connectoinTupple(connectionTupple)
	, m_certPemFile(certPemFile)
	, m_ssl_bio(nullptr)
	, m_ssl_ctx(nullptr)
	, m_ssl(nullptr)
{
	// Initializing OpenSSL
	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();

	if(false == initSslCtx())
	{
	    throw runtime_error("SslConnection::SslConnection - was unable to initialize the SSL ctx object");
	}

	if(false == initSslBio())
	{
	    throw runtime_error("SslConnection::SslConnection - was unable to initialize the SSL bio object");
	}

	LOG(INFO) << "SslConnection::SslConnection - successfully opend a connection to:" << m_connectoinTupple;
}

SslConnection::~SslConnection()
{
	freeAllSslRelatedObjects();
	LOG(INFO) << "SslConnection::~SslConnection - successfully closed a connection to:" << m_connectoinTupple;
}

bool SslConnection::initSslCtx()
{
	/* Set up the SSL context */
	m_ssl_ctx = SSL_CTX_new(SSLv23_client_method());

	/* Load the certification PEM file */
	if(!SSL_CTX_load_verify_locations(m_ssl_ctx, m_certPemFile.c_str(), nullptr))
	{
		LOG(ERROR) << "SslConnection::initSslCtx - error loading the certification PEM file:" << m_certPemFile;
	    SSL_CTX_free(m_ssl_ctx);
	    return false;
	}

	return true;
}

bool SslConnection::initSslBio()
{
	/* Setup the connection */
	m_ssl_bio = BIO_new_ssl_connect(m_ssl_ctx);

    /* Set the SSL_MODE_AUTO_RETRY flag */
    BIO_get_ssl(m_ssl_bio, &m_ssl);
    SSL_set_mode(m_ssl, SSL_MODE_AUTO_RETRY);

    /* Create and setup the connection */
    BIO_set_conn_hostname(m_ssl_bio, m_connectoinTupple.c_str());
    if(BIO_do_connect(m_ssl_bio) <= 0)
    {
        LOG(ERROR) << "SslConnection::initSslBio -Error attempting to connect";
        freeAllSslRelatedObjects();
        return false;
    }

    /* Check the certificate */
    if(SSL_get_verify_result(m_ssl) != X509_V_OK)
    {
    	LOG(ERROR) << "SslConnection::initSslBio - Certificate verification error:" << SSL_get_verify_result(m_ssl);
    	freeAllSslRelatedObjects();
        return false;
    }

    return true;
}

/*
 * BIO_free_all does just what it says: it frees the internal structure and releases all associated
 * memory, including closing the associated socket. If the BIO is embedded in a class, this
 * would be used in the class' destructor.
 */
void SslConnection::freeAllSslRelatedObjects()
{
    BIO_free_all(m_ssl_bio);
    SSL_CTX_free(m_ssl_ctx);
    LOG(INFO) << "SslConnection::freeAllSslRelatedObjects";
}

