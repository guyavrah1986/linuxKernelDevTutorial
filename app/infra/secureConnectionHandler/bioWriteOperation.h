#pragma once

#include "bioOperation.h"

class BioWriteOperation : public BioOperation
{
public:
	NO_COPY(BioWriteOperation);

public:
	BioWriteOperation();
	virtual ~BioWriteOperation();

	BioOperationResultType HandleOperation(BIO* bio, void* opBuff, int opLen) override;
	virtual bool IsValidOperation() const override;

private:
	BioOperationResultType handleAttempt(unsigned char numAttempt);

};
