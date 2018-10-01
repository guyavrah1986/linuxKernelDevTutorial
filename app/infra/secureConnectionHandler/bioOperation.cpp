#include <glog/logging.h>

#include "bioOperation.h"

using namespace std;

BioOperation::BioOperation(void* opBuff, int opLen)
	: m_operationBuff(opBuff)
	, m_operationLen(opLen)
	, m_operationRes(SECURE_CONNECTION_BIO_OPERATION_RESULT_UNKNOWN)
{
	LOG(INFO) << "BioOperation::BioOperation - setting m_operationLen to:" << m_operationLen << " and"
			" m_operationBuff to:" << m_operationBuff;

}

BioOperation::~BioOperation()
{
	LOG(INFO) << "BioOperation::~BioOperation";
}

bool BioOperation::IsValidOperation() const
{
	LOG(INFO) << "BioOperation::IsValidOperation";
	if (m_operationLen < 1 || m_operationBuff == nullptr)
	{
		LOG(ERROR) << "BioOperation::IsValidOperation - one or more of the operation arguments is invalid";
		return false;
	}

	return true;
}
