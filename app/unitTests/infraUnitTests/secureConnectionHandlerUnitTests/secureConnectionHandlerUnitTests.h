#pragma once

#include "gtest/gtest.h"

class SecureConnectionHandlerUnitTests : public ::testing::Test
{
protected:

	SecureConnectionHandlerUnitTests();
	virtual ~SecureConnectionHandlerUnitTests();
	virtual void SetUp();
	virtual void TearDown();
};

