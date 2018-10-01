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

	return BioOperationResultType(SECURE_CONNECTION_BIO_OPERATION_RESULT_UNKNOWN);
}

