// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETOKENIZERTESTS_BAKEFILETOKENIZERTESTS_H_
#define _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETOKENIZERTESTS_BAKEFILETOKENIZERTESTS_H_

#include <Ishiko/TestFramework.hpp>

class BakefileTokenizerTests : public Ishiko::TestSequence
{
public:
	BakefileTokenizerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
	static void CreationTest1(Ishiko::Test& test);
	static void GetNextToken(Ishiko::Test& test);
};

#endif
