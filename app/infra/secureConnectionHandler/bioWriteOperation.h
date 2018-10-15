#pragma once

#include "bioOperation.h"

class BioWriteOperation : public BioOperation
{
public:
	NO_COPY(BioWriteOperation);

public:
	BioWriteOperation();
	virtual ~BioWriteOperation();

	virtual bool IsValidOperation() const override;
	int Write(BIO* bio, const std::string& buffToWrite);

protected:
	int PerformOperation(BIO* bio, void* opBuff, int opLen) override;
};
