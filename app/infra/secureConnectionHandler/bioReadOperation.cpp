#include <glog/logging.h>

#include "bioReadOperation.h"

BioReadOperation::BioReadOperation(void* opBuff, int opLen)
	: BioOperation(opBuff, opLen)
{
	LOG(INFO) << "BioReadOperation::BioReadOperation";
}

BioReadOperation::~BioReadOperation()
{
	LOG(INFO) << "BioReadOperation::~BioReadOperation";
}

BioOperationResultType BioReadOperation::HandleOperation()
{
	LOG(INFO) << "BioReadOperation::HandleOperation";
	if (false == IsValidOperation())
	{
		LOG(INFO) << "BioReadOperation::HandleOperation - invalid operation";
		return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_ERROR);
	}

	const size_t maxNumOfAttempts = 2;
	unsigned char numOfAttempts = 0;
	BioOperationResultType res = SECURE_CONNECTION_BIO_CONNECTION_TYPE_UNKNOWN;
	for (size_t i = 0;;)
	{
		res = handleAttempt(numOfAttempts);
		++i;
		if (res == SECURE_CONNECTION_BIO_OPERATION_RESULT_FAILED && i < maxNumOfAttempts)
		{
			LOG(INFO) << "BioReadOperation::HandleOperation - attempt " << i << " has failed, about to retry";
			continue;
		}

		break;
	}

	return res;
}

BioOperationResultType BioReadOperation::handleAttempt(unsigned char numAttempt)
{
	LOG(INFO) << "BioReadOperation::handleAttempt number" << numAttempt;

	int bioReadRet = BIO_read(m_bio, m_operationBuff, m_operationLen);
	if(bioReadRet < 0)
	{
		LOG(INFO) << "BioReadOperation::HandleOperation - attempt " << ++numAttempt << " failed";
		return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_FAILED);
	}

	if (bioReadRet == 0)
	{
		if(m_connectionType == SECURE_CONNECTION_BIO_CONNECTION_TYPE_BLOCKING)
		{
		    /* Handle closed connection */
			LOG(INFO) << "BioReadOperation::HandleOperation - connection was cloased";
			return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_CONNECTION_WAS_CLOSED);
		}

		if(m_connectionType == SECURE_CONNECTION_BIO_CONNECTION_TYPE_NON_BLOCKING)
		{
		    /* Handle closed connection */
			LOG(INFO) << "BioReadOperation::HandleOperation - no data was avialble";
			return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_NO_DATA_AVAILBLE);
		}

		LOG(ERROR) << "BioReadOperation::HandleOperation - invalid connection type";
		return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_UNKNOWN);
	}

	/* Handle success read */
	return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_SUCCESS);
}
