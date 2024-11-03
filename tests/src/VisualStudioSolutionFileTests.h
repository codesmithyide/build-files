// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHYIDE_BUILFILES_TESTS_VISUALSTUDIOSOLUTIONFILETESTS_H_
#define _CODESMITHYIDE_BUILFILES_TESTS_VISUALSTUDIOSOLUTIONFILETESTS_H_

#include <Ishiko/TestFramework.hpp>

class VisualStudioSolutionFileTests : public Ishiko::TestSequence
{
public:
    VisualStudioSolutionFileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& environment);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CreateTest1(Ishiko::Test& test);
    static void CreateTest2(Ishiko::Test& test);
    static void CreateTest3(Ishiko::Test& test);
    static void CreateTest4(Ishiko::Test& test);
    static void CreateTest5(Ishiko::Test& test);
};

#endif
