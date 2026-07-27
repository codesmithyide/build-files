// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "BakefileTargetTests.h"
#include "Nuime/BuildFiles/Bakefile/BakefileTarget.hpp"

BakefileTargetTests::BakefileTargetTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
	: Ishiko::TestSequence(number, "BakefileTarget tests", context)
{
	append<Ishiko::HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
}

void BakefileTargetTests::CreationTest1(Ishiko::Test& test)
{
    Nuime::BakefileTarget target;
    
	ISHIKO_TEST_PASS();
}
