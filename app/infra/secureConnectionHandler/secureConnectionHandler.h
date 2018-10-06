#pragma once

#include <memory>

#include "globalInclude.h"
#include "sslConnection.h"

/*
 * This class holds all the SSL connections that are current living in the system.
 * It's main tasks are:
 * 1) Initialize the usage in the OpenSSL libray.
 * 2) Hold all the SslConnections of the application.
 *
 * NOTE: It does not responsbile of "opening" NOR "closing" (terminating) the connections.
 */
class SecureConnectionsHandler
{
	NO_COPY(SecureConnectionsHandler);

public:
	SecureConnectionsHandler();
	~SecureConnectionsHandler();

	bool CreateConnection(const std::string& ip, const unsigned short port, const std::string& certPemFile);

private:
	bool validateSslConnectionParamters(const std::string& ip , const unsigned short port, const std::string& certPemFile) const;

// members
// -------
private:
	std::unique_ptr<SslConnection> m_conneciton;
};
