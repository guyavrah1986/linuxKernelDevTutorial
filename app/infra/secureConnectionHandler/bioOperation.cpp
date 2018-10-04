#include <glog/logging.h>

#include "bioOperation.h"

using namespace std;

/*
 * This function verifies that the common "basic operation's arguments" are all safe
 * to be used.
 */
bool IsValidOperationArgs(BIO* bio, void* opBuff, int opLen) const
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


