#pragma once

#include <memory>

#include "globalInclude.h"
#include "sslConnection.h"

/*
 * This class holds an SSL connection in a "RAII fashion".
 * It's main tasks are:
 * 1) Initialize the usage in the OpenSSL libray.
 * 2) Hold the SslConnection of the application.
 *
 * NOTE: It does not responsbile of "opening" NOR "closing" (terminating) the connections, it
 * is the task of the "encapsulated" std::unique_ptr<SslConnection> member.
 */
class SecureConnectionsHandler
{
	NO_COPY(SecureConnectionsHandler);

public:
	SecureConnectionsHandler();
	~SecureConnectionsHandler();

	bool CreateConnection(const std::string& ip, const unsigned short port, const std::string& certPemFile);
	int SendData(const std::string& dataToSend);
	int ReceiveData(std::string& dataToRecive);

private:
	bool validateSslConnectionParamters(const std::string& ip , const unsigned short port, const std::string& certPemFile) const;

// members
// -------
private:
	std::unique_ptr<SslConnection> m_conneciton;
};
