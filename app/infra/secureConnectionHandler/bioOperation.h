#pragma once

#include <openssl/bio.h>

#include "globalInclude.h"

enum BioConnectionType
{
	SECURE_CONNECTION_BIO_CONNECTION_TYPE_BLOCKING = 0,
	SECURE_CONNECTION_BIO_CONNECTION_TYPE_NON_BLOCKING,
	SECURE_CONNECTION_BIO_CONNECTION_TYPE_UNKNOWN
};

enum BioOperationResultType
{
	SECURE_CONNECTION_BIO_OPERATION_RESULT_ERROR = -1,
	SECURE_CONNECTION_BIO_OPERATION_RESULT_NO_DATA_AVAILBLE,
	SECURE_CONNECTION_BIO_OPERATION_RESULT_CONNECTION_WAS_CLOSED,
	SECURE_CONNECTION_BIO_OPERATION_RESULT_SUCCESS,
	SECURE_CONNECTION_BIO_OPERATION_RESULT_FAILED,
	SECURE_CONNECTION_BIO_OPERATION_RESULT_UNKNOWN
};

/*
 * This class is intendend to be used per "connection", meaning that, a certain client can have
 * several DIFFERENT (SSL-based) connections with a server(s) at the same time, thus  each instance
 * of this class (more precisessly, its derived classes) will represent a BIO operation (basically a
 * read/write operation) towards the connection that the BIO* object was connected to.
 * The main tasks of this objects is to provides a "RAII abstraction" layer between the object that
 * wishes to perform a read/write (i.e.- BIO operation) with a server it has already connected to.
 * - It simply gets the "only" three parameters it needs to perform the desired operation and returns
 * a respective result.
 */
class BioOperation
{
	NO_COPY(BioOperation);

public:
	BioOperation()
		: m_operationRes(SECURE_CONNECTION_BIO_OPERATION_RESULT_UNKNOWN)
		, m_connectionType(SECURE_CONNECTION_BIO_CONNECTION_TYPE_UNKNOWN)
	{
		LOG(INFO) << "BioOperation::BioOperation - setting m_connectionType to:" << m_connectionType;
	}

	virtual ~BioOperation()
	{
		LOG(INFO) << "BioOperation::~BioOperation";
	}

	virtual bool IsValidOperation() const = 0;

protected:
	virtual BioOperationResultType HandleOperation(BIO* bio, void* opBuff, int opLen);
	virtual int PerformOperation(BIO* bio, void* opBuff, int opLen) = 0;
	BioOperationResultType HandleAttempt(BIO* bio, void* opBuff, int opLen, unsigned char numAttempt);
	bool IsValidOperationArgs(BIO* bio, void* opBuff, int opLen) const;


// members
protected:
	int m_operationRes;
	BioConnectionType m_connectionType;
};

/*
 * class BioOperationResult
{
public:
	BioResult(BioConnectionType connectionType, BioOperationType opType)
		: m_connectionType(connectionType)
		, m_numBytesUsed(res)
	{
		if (res == 0)
		{
			if (m_connectionType == BioConnectionType::SECURE_CONNECTION_BIO_CONNECTION_BLOCKING)
			{
				/ On a blocking connection, a return of 0 means that the connection was closed
				m_connectionRes = BioResultType::SECURE_CONNECTION_BIO_RESULT_CONNECTION_WAS_CLOSED;
			}
			else if (m_connectionType == BioConnectionType::SECURE_CONNECTION_BIO_CONNECTION_NON_BLOCKING)
			{
				/On a non-blocking connection, a return of 0 means no data was available
				m_connectionRes = BioResultType::SECURE_CONNECTION_BIO_RESULT_NO_DATA_AVAILBLE;
			}
			else
			{
				m_connectionRes = BioResultType::SECURE_CONNECTION_BIO_RESULT_UNKNOWN;
			}
		}
		else if (res == -1)
		{
			m_connectionRes = BioResultType::SECURE_CONNECTION_BIO_RESULT_ERROR;
		}
		else if (res > 0)
		{
			m_connectionRes = BioResultType::SECURE_CONNECTION_BIO_RESULT_SUCCESS;
		}
		else
		{
			m_connectionRes = BioResultType::SECURE_CONNECTION_BIO_RESULT_UNKNOWN;
		}
	}
 *
 */
