#pragma once

#include "gtest/gtest.h"

class BioOperationUnitTests : public ::testing::Test
{
protected:

	BioOperationUnitTests();
	virtual ~BioOperationUnitTests();
	virtual void SetUp();
	virtual void TearDown();
};

