#include <glog/logging.h>

#include "bioReadOperation.h"

BioReadOperation::BioReadOperation()
	: BioOperation()
{
	LOG(INFO) << "BioReadOperation::BioReadOperation";
}

BioReadOperation::~BioReadOperation()
{
	LOG(INFO) << "BioReadOperation::~BioReadOperation";
}

BioOperationResultType BioReadOperation::HandleOperation(BIO* bio, void* opBuff, int opLen)
{
	LOG(INFO) << "BioReadOperation::HandleOperation";
	if (false == IsValidOperation())
	{
		LOG(INFO) << "BioReadOperation::HandleOperation - invalid operation";
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
			LOG(INFO) << "BioReadOperation::HandleOperation - attempt " << i << " has failed, about to retry";
			continue;
		}

		break;
	}

	return res;
}

bool BioReadOperation::IsValidOperation() const
{
	return true;
}


