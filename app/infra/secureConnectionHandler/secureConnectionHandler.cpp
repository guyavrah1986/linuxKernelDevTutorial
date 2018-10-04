#include <glog/logging.h>
#include <sys/stat.h>

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"

#include "secureConnectionHandler.h"
	
using namespace std;

SecureConnectionsHandler::SecureConnectionsHandler()
{
	LOG(INFO) << "SecureConnectionsHandler::SecureConnectionsHandler";

	// Initializing OpenSSL
	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();
}

SecureConnectionsHandler::~SecureConnectionsHandler()
{
	LOG(INFO) << "SecureConnectionsHandler::~SecureConnectionsHandler";
}

bool SecureConnectionsHandler::AddConnection(const string& ip, const unsigned short port, const string& certPemFile)
{
	// verify paramters
	if(false == validateSslConnectionParamters(ip, port))
	{
		/* Handle invlaid SSL connection parameters */
	    throw runtime_error("SecureConnectionsHandler::AddConnection - invalid SSL connection parameters (port and/or IP address)");
	}

	const string connectionTupple = ip + ":" + to_string(port);	// hostname:port
	SslConnection sslConnection(connectionTupple, certPemFile);

	// we use the [] operator and not the insert method, cause we can be sure that
	// no two connections to the same ip:port will be present simultancely.
	m_connectionsMap[connectionTupple] = sslConnection;
	LOG(INFO) << "SecureConnectionsHandler::AddConnection - added connection:" << connectionTupple;
	return true;
}

bool SecureConnectionsHandler::validateSslConnectionParamters(const string& ip, const unsigned short port) const
{
	if (ip.empty())
	{
		LOG(ERROR) << "SslConnection::validateConnectionParamters - got invlaid IP address and/or port number";
		return false;
	}

	/*
	struct stat buffer;
	if (stat(m_certPemFile.c_str(), &buffer) != 0)
	{
		LOG(ERROR) << "SslConnection::validateConnectionParamters - certification file does not exsit OR invalid";
		return false;
	}
	*/

	return true;
}



