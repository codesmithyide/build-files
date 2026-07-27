// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETESTS_BAKEFILETESTS_H_
#define _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETESTS_BAKEFILETESTS_H_

#include <Ishiko/TestFramework.hpp>

class BakefileTests : public Ishiko::TestSequence
{
public:
	BakefileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
	static void CreationTest1(Ishiko::Test& test);
};

#endif
