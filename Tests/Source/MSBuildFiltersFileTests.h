/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILFILES_TESTS_MSBUILDFILTERSFILETESTS_H_
#define _CODESMITHYIDE_BUILFILES_TESTS_MSBUILDFILTERSFILETESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class MSBuildFiltersFileTests : public Ishiko::Tests::TestSequence
{
public:
    MSBuildFiltersFileTests(const Ishiko::Tests::TestNumber& number,
        const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
};

#endif
