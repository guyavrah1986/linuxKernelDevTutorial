#include <glog/logging.h>

#include "bioWriteOperation.h"

BioWriteOperation::BioWriteOperation()
	: BioOperation()
{
	LOG(INFO) << "BioWriteOperation::BioWriteOperation";
}

BioWriteOperation::~BioWriteOperation()
{
	LOG(INFO) << "BioWriteOperation::~BioWriteOperation";
}


BioOperationResultType BioWriteOperation::HandleOperation(BIO* bio, void* opBuff, int opLen)
{
	BioOperationResultType res;// = SECURE_CONNECTION_BIO_CONNECTION_TYPE_UNKNOWN;
	return res;
}

int BioWriteOperation::PerformOperation(BIO* bio, void* opBuff, int opLen)
{
	return BIO_write(bio, opBuff, opLen);
}


bool BioWriteOperation::IsValidOperation() const
{
	return true;
}
