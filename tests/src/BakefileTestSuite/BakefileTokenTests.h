// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETOKENTESTS_H_
#define _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILETOKENTESTS_H_

#include <Ishiko/TestFramework.hpp>

class BakefileTokenTests : public Ishiko::TestSequence
{
public:
	BakefileTokenTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
	static void CreationTest1(Ishiko::Test& test);
};

#endif
