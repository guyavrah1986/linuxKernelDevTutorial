#include <glog/logging.h>

#include "bioOperation.h"

using namespace std;

BioOperationResultType BioOperation::HandleOperation(BIO* bio, void* opBuff, int opLen)
{
	LOG(INFO) << "BioOperation::HandleOperation";
	if (false == IsValidOperation())
	{
		LOG(INFO) << "BioOperation::HandleOperation - invalid operation";
		return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_ERROR);
	}

	const size_t maxNumOfAttempts = 2;
	unsigned char numOfAttempts = 0;
	BioOperationResultType res;// = SECURE_CONNECTION_BIO_CONNECTION_TYPE_UNKNOWN;
	for (size_t i = 0;;)
	{
		res = HandleAttempt(bio, opBuff, opLen, numOfAttempts);
		++i;
		if (res == SECURE_CONNECTION_BIO_OPERATION_RESULT_FAILED && i < maxNumOfAttempts)
		{
			LOG(INFO) << "BioOperation::HandleOperation - attempt " << i << " has failed, about to retry";
			continue;
		}

		break;
	}

	return res;
}

BioOperationResultType BioOperation::HandleAttempt(BIO* bio, void* opBuff, int opLen, unsigned char numAttempt)
{
	LOG(INFO) << "BioOperation::HandleAttempt number" << numAttempt;

	int bioReadRet = PerformOperation(bio, opBuff, opLen);
	if(bioReadRet < 0)
	{
		LOG(INFO) << "BioOperation::HandleAttempt - attempt " << ++numAttempt << " failed";
		return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_FAILED);
	}

	if (bioReadRet == 0)
	{
		if(m_connectionType == SECURE_CONNECTION_BIO_CONNECTION_TYPE_BLOCKING)
		{
		    /* Handle closed connection */
			LOG(INFO) << "BioOperation::HandleAttempt - connection was cloased";
			return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_CONNECTION_WAS_CLOSED);
		}

		if(m_connectionType == SECURE_CONNECTION_BIO_CONNECTION_TYPE_NON_BLOCKING)
		{
		    /* Handle no availble data  */
			LOG(INFO) << "BioOperation::HandleAttempt - no data was avialble";
			return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_NO_DATA_AVAILBLE);
		}

		LOG(ERROR) << "BioOperation::HandleAttempt - invalid connection type";
		return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_UNKNOWN);
	}

	/* Handle success read */
	return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_SUCCESS);
}

/*
 * This function verifies that the common "basic operation's arguments" are all safe
 * to be used.
 */
bool BioOperation::IsValidOperationArgs(BIO* bio, void* opBuff, int opLen) const
{
	LOG(INFO) << "BioOperation::IsValidOperationArgs";
	if (bio == nullptr || opBuff == nullptr || opLen < 0)
	{
		LOG(ERROR) << "BioOperation::IsValidOperationArgs - one or more of the arguments provided"
				" to the operation is invalid";
		return false;
	}

	return true;
}

