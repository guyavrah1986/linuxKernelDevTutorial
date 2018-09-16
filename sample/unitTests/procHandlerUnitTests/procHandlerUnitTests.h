#pragma once

#include "gtest/gtest.h"

class ProcHandlerUnitTests : public ::testing::Test
{
protected:

	ProcHandlerUnitTests();
	virtual ~ProcHandlerUnitTests();
	virtual void SetUp();
	virtual void TearDown();
};

