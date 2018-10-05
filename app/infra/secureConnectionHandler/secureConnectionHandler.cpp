#include <glog/logging.h>
#include <fstream>

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
	if(false == validateSslConnectionParamters(ip, port, certPemFile))
	{
		/* Handle invlaid SSL connection parameters */
	    throw runtime_error("SecureConnectionsHandler::AddConnection - invalid SSL connection parameters (port and/or IP address)");
	}

	const string connectionTupple = ip + ":" + to_string(port);	// hostname:port

	// we use the insert method to verify that no "new connection with the same
	// IP & port values is made, so that no two connections to the same ip:port
	// will be present simultancely.
	auto it = m_connectionsMap.insert(make_pair<string, SslConnection>(string(ip + ":" + to_string(port)), SslConnection(connectionTupple, certPemFile)));
	if (false == it.second)
	{
		LOG(ERROR) << "SecureConnectionsHandler::AddConnection - trying to add a new connection"
				" to an already hostname:port:" << connectionTupple << " exsiting connection";
		return false;
	}

	LOG(INFO) << "SecureConnectionsHandler::AddConnection - added connection:" << connectionTupple;
	return true;
}

bool SecureConnectionsHandler::validateSslConnectionParamters(const string& ip, const unsigned short port, const string& certPemFile) const
{
	if (ip.empty() || certPemFile.empty())
	{
		LOG(ERROR) << "SslConnection::validateConnectionParamters - got an empty IP address or cert PEM file name";
		return false;
	}

	ifstream f(certPemFile.c_str());
	if (false == f.good())
	{
		LOG(ERROR) << "SslConnection::validateConnectionParamters - certification file:"
				<< certPemFile << " does not exist";
		return false;
	}

	return true;
}



