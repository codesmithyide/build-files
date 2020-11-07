/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILFILES_TESTS_MSBUILDPROJECTFILETESTS_H_
#define _CODESMITHYIDE_BUILFILES_TESTS_MSBUILDPROJECTFILETESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class MSBuildProjectFileTests : public Ishiko::Tests::TestSequence
{
public:
    MSBuildProjectFileTests(const Ishiko::Tests::TestNumber& number,
        const Ishiko::Tests::TestEnvironment& environment);
};

#endif
