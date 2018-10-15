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

int BioWriteOperation::PerformOperation(BIO* bio, void* opBuff, int opLen)
{
	return BIO_write(bio, opBuff, opLen);
}

int BioWriteOperation::Write(BIO* bio, const std::string& buffToWrite)
{
	LOG(INFO) << "BioWriteOperation::Write";
	if(buffToWrite.empty())
	{
		LOG(ERROR) << "BioWriteOperation::Write - trying to write zero length buffer";
		return 0;
	}

	// TODO:
	// 1) verify implict cating from size_t to int is not a problem
	// 2) Update the class BioOperationResult (mainly add it a "IsSuccess" function) and use it
	BioOperationResultType res = HandleOperation(bio, const_cast<char*>(buffToWrite.c_str()), buffToWrite.length());
	if (res == 	SECURE_CONNECTION_BIO_OPERATION_RESULT_SUCCESS)
	{
		return buffToWrite.length();
	}

	// indicate an error (see part of the TODO).
	return -1;
}

bool BioWriteOperation::IsValidOperation() const
{
	return true;
}
