#include <glog/logging.h>
#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"

#include "secureConnectionHandler.h"
	
using namespace std;

SecureConnectionHandler::SecureConnectionHandler()
{
	LOG(INFO) << "SecureConnectionHandler::SecureConnectionHandler";

	// Initializing OpenSSL
	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();
}

SecureConnectionHandler::~SecureConnectionHandler()
{
	LOG(INFO) << "SecureConnectionHandler::~SecureConnectionHandler";
}

