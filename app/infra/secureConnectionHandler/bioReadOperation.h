#pragma once

#include "bioOperation.h"

/*
 * BIO_read will attempt to read a certain number of bytes from the server.
 * It returns the number of bytes read, or 0 or -1.
 * On a blocking connection:
 * 0  - return of 0 means that the connection was closed.
 * -1 - indicates that an error occurred.
 * On a non-blocking connection:
 * 0  - means no data was available
 * -1 - indicates an error.
 * To determine if the error is recoverable, call BIO_should_retry.
 */
class BioReadOperation : public BioOperation
{
	NO_COPY(BioReadOperation);

public:
	BioReadOperation();
	virtual ~BioReadOperation();

	virtual int PerformOperation(BIO* bio, void* opBuff, int opLen) override;
	virtual bool IsValidOperation() const override;

private:

};
