// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILEPARSERTESTS_BAKEFILEPARSERTESTS_H_
#define _CODESMITHY_TEST_BAKEFILE_CORE_BAKEFILEPARSERTESTS_BAKEFILEPARSERTESTS_H_

#include <Ishiko/TestFramework.hpp>

class BakefilePushParserTests : public Ishiko::TestSequence
{
public:
    BakefilePushParserTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
	static void ConstructorTest1(Ishiko::Test& test);
	static void OnDataTest1(Ishiko::Test& test);
	static void OnDataTest2(Ishiko::Test& test);
    static void OnDataTest3(Ishiko::Test& test);
};

#endif
