/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILFILES_TESTS_VISUALSTUDIOSOLUTIONFILETESTS_H_
#define _CODESMITHYIDE_BUILFILES_TESTS_VISUALSTUDIOSOLUTIONFILETESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class VisualStudioSolutionFileTests : public Ishiko::Tests::TestSequence
{
public:
    VisualStudioSolutionFileTests(const Ishiko::Tests::TestNumber& number,
        const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
    static void CreateTest1(Ishiko::Tests::FileComparisonTest& test);
};

#endif
