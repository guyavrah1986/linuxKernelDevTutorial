#include <glog/logging.h>

#include "bioOperation.h"

using namespace std;


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

BioOperationResultType BioOperation::HandleAttempt(BIO* bio, void* opBuff, int opLen, unsigned char numAttempt)
{
	LOG(INFO) << "BioOperation::HandleAttempt number" << numAttempt;

	int bioReadRet = BIO_read(bio, opBuff, opLen);
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


