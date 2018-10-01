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


class BioOperation
{
	NO_COPY(BioOperation);

public:
	BioOperation(BIO* bio, void* opBuff, int opLen);
	virtual ~BioOperation();

	virtual BioOperationResultType HandleOperation() = 0;

protected:
	bool IsValidOperation() const;

// members
protected:
	BIO* m_bio;
	void* m_operationBuff;
	int m_operationLen;
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
