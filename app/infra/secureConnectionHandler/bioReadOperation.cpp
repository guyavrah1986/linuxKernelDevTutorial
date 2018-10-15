#include <glog/logging.h>

#include "bioReadOperation.h"

using namespace std;

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

int BioReadOperation::Read(BIO* bio, vector<unsigned char>& buffToReadInto)
{
	LOG(INFO) << "BioReadOperation::Read";
	if(buffToReadInto.size() == 0)
	{
		LOG(ERROR) << "BioReadOperation::Read - trying to read to an empty buffer";
		return 0;
	}

	// TODO:
	// 1) verify implict cating from size_t to int is not a problem
	// 2) Update the class BioOperationResult (mainly add it a "IsSuccess" function) and use it
	BioOperationResultType res = HandleOperation(bio, (void *)(buffToReadInto[0]), 1500);
	if (res == 	SECURE_CONNECTION_BIO_OPERATION_RESULT_SUCCESS)
	{
		return buffToReadInto.size();
	}

	// indicate an error (see part of the TODO).
	return -1;
}


int BioReadOperation::PerformOperation(BIO* bio, void* opBuff, int opLen)
{
	return BIO_read(bio, opBuff, opLen);
}



