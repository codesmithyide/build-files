// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETARGETTESTS_H_
#define _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETARGETTESTS_H_

#include <Ishiko/TestFramework.hpp>

class BakefileTargetTests : public Ishiko::TestSequence
{
public:
	BakefileTargetTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
	static void CreationTest1(Ishiko::Test& test);
};

#endif
