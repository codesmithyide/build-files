// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_TESTS_CODESMITHYTESTSUITE_CODESMITHYPROJECTFILETESTS_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_TESTS_CODESMITHYTESTSUITE_CODESMITHYPROJECTFILETESTS_HPP

#include <Ishiko/TestFramework.hpp>

class CodeSmithyProjectFileTests : public Ishiko::TestSequence
{
public:
    CodeSmithyProjectFileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif
