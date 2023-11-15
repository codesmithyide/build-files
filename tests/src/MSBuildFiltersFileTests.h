/*
    Copyright (c) 2021-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

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
