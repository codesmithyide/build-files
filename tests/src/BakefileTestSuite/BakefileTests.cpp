// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "BakefileTests.h"
#include "Nuime/BuildFiles/Bakefile/Bakefile.hpp"

BakefileTests::BakefileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
	: Ishiko::TestSequence(number, "Bakefile tests", context)
{
	append<Ishiko::HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
}

void BakefileTests::CreationTest1(Ishiko::Test& test)
{
    Nuime::Bakefile bakefile;

	ISHIKO_TEST_PASS();
}
