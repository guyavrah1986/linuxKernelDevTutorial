#include <glog/logging.h>
#include <fstream>

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"

#include "secureConnectionHandler.h"
#include "bioWriteOperation.h"
	
using namespace std;

SecureConnectionsHandler::SecureConnectionsHandler()
{
	LOG(INFO) << "SecureConnectionsHandler::SecureConnectionsHandler";
}

SecureConnectionsHandler::~SecureConnectionsHandler()
{
	LOG(INFO) << "SecureConnectionsHandler::~SecureConnectionsHandler";
}

bool SecureConnectionsHandler::CreateConnection(const string& ip, const unsigned short port, const string& certPemFile)
{
	// verify paramters
	if(false == validateSslConnectionParamters(ip, port, certPemFile))
	{
		/* Handle invlaid SSL connection parameters */
	    LOG(ERROR) << "SecureConnectionsHandler::AddConnection - invalid SSL connection parameters"
	    		" port and/or IP address";
	    return false;
	}

	const string connectionTupple = ip + ":" + to_string(port);	// hostname:port
	m_conneciton = unique_ptr<SslConnection>(new SslConnection(connectionTupple, certPemFile));
	LOG(INFO) << "SecureConnectionsHandler::AddConnection - added connection:" << connectionTupple;
	return true;
}

bool SecureConnectionsHandler::validateSslConnectionParamters(const string& ip, const unsigned short port, const string& certPemFile) const
{
	if (ip.empty() || certPemFile.empty())
	{
		LOG(ERROR) << "SecureConnectionsHandler::validateConnectionParamters - got an empty IP address or cert PEM file name";
		return false;
	}

	ifstream f(certPemFile.c_str());
	if (false == f.good())
	{
		LOG(ERROR) << "SecureConnectionsHandler::validateConnectionParamters - certification file:"
				<< certPemFile << " does not exist";
		return false;
	}

	return true;
}

int SecureConnectionsHandler::SendData(const std::string& dataToSend)
{
	LOG(INFO) << "SecureConnectionsHandler::SendData";
	int writeRes = m_conneciton->Write(dataToSend);

	return writeRes;
}

int SecureConnectionsHandler::ReceiveData(vector<unsigned char>& dataToRecive)
{
	LOG(INFO) << "SecureConnectionsHandler::ReceiveData";
	int readRes = m_conneciton->Read(dataToRecive);

	return readRes;
}



