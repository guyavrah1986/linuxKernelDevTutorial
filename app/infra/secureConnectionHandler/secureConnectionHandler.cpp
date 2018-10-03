#include <glog/logging.h>

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
	SslConnection sslConnection(ip, port, "some_cert_file_path");
	//TODO: LOG(INFO) << "SecureConnectionsHandler::AddConnection - added connection:";
	return true;
}


