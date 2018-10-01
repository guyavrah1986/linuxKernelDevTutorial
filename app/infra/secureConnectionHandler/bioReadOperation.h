#pragma once

#include "bioOperation.h"

class BioReadOperation : public BioOperation
{
	NO_COPY(BioReadOperation);

public:
	BioReadOperation(void* opBuff, int opLen);
	virtual ~BioReadOperation();

	BioOperationResultType HandleOperation() override;

};
