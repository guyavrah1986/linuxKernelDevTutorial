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

bool BioReadOperation::IsValidOperation() const
{
	return true;
}

int BioReadOperation::PerformOperation(BIO* bio, void* opBuff, int opLen)
{
	return BIO_read(bio, opBuff, opLen);
}


