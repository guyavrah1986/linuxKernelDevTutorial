#pragma once

#include <map>

#include "globalInclude.h"
#include "sslConnection.h"

/*
 * This class holds all the SSL connections that are current living in the system.
 * It's main tasks are:
 * 1) Initialize the usage in the OpenSSL libray.
 * 2) Hold all the SslConnections of the application.
 */
class SecureConnectionsHandler
{
	NO_COPY(SecureConnectionsHandler);

public:
	SecureConnectionsHandler();
	~SecureConnectionsHandler();

	bool AddConnection(const std::string& ip, const unsigned short port);

private:
	std::map<std::string, SslConnection> m_connectionsMap;

};
