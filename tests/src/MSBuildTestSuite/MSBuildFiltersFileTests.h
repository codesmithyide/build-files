// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHYIDE_BUILFILES_TESTS_MSBUILDFILTERSFILETESTS_H_
#define _CODESMITHYIDE_BUILFILES_TESTS_MSBUILDFILTERSFILETESTS_H_

#include <Ishiko/TestFramework.hpp>

class MSBuildFiltersFileTests : public Ishiko::TestSequence
{
public:
    MSBuildFiltersFileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& environment);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CreateTest1(Ishiko::Test& test);
    static void CreateTest2(Ishiko::Test& test);
    static void AddSourceFileTest1(Ishiko::Test& test);
    static void AddHeaderFileTest1(Ishiko::Test& test);
    static void AddHeaderAndSourceFilesTest1(Ishiko::Test& test);
};

#endif
