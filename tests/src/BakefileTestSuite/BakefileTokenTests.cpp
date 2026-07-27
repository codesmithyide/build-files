// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "BakefileTokenTests.h"
#include "Nuime/BuildFiles/Bakefile/BakefileToken.hpp"

BakefileTokenTests::BakefileTokenTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
	: Ishiko::TestSequence(number, "BakefileToken tests", context)
{
	append<Ishiko::HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
}

void BakefileTokenTests::CreationTest1(Ishiko::Test& test)
{
    Nuime::BakefileToken token;
    
	ISHIKO_TEST_PASS();
}
