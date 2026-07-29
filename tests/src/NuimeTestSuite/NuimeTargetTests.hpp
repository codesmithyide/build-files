// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMETARGETTESTS_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMETARGETTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class NuimeTargetTests : public Ishiko::TestSequence
{
public:
    NuimeTargetTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void AddLabelTest1(Ishiko::Test& test);
    static void HasLabelTest1(Ishiko::Test& test);
    static void HasLabelTest2(Ishiko::Test& test);
};

#endif
