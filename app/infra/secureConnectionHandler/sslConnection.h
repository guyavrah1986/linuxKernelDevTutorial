#pragma once

#include <string>
#include <openssl/bio.h>

#include "globalInclude.h"

/*
 * This class is a simple RAII-style wrapper for the Bio object from the OpenSSL libray.
 * It task is to hold (and "maintain") a SSL connection. --> the only ctor of the class
 * 1) Ctor:performs all the required operations needed to open the connection.
 * - Verify that the connection parameters are correct and valid.
 * - Initialize the SSL ctx structure.
 */
class SslConnection
{
	NO_COPY(SslConnection);

public:
	SslConnection(const std::string& connectionTupple, const std::string& certPemFile);
	~SslConnection();

private:
	bool validateSslConnectionParamters() const;
	bool initSslCtx();
	bool initSslBio();
	void freeAllSslRelatedObjects();


// members:
// -------
private:
	std::string m_ip;
	unsigned short m_port;
	std::string m_certPemFile;
	std::string m_connectoinTupple;
	BIO* m_ssl_bio;
	SSL_CTX* m_ssl_ctx;
	SSL* m_ssl;

};
