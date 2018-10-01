#include <glog/logging.h>

#include "bioOperation.h"

using namespace std;

BioOperation::BioOperation(BIO* bio, void* opBuff, int opLen)
	: m_bio(bio)
	, m_operationBuff(opBuff)
	, m_operationLen(opLen)
	, m_operationRes(SECURE_CONNECTION_BIO_OPERATION_RESULT_UNKNOWN)
	, m_connectionType(SECURE_CONNECTION_BIO_CONNECTION_TYPE_UNKNOWN)

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
	if (m_bio == nullptr || m_operationBuff == nullptr || m_operationLen < 1)
	{
		LOG(ERROR) << "BioOperation::IsValidOperation - one or more of the operation arguments is invalid";
		return false;
	}

	return true;
}
