// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEOUTPUTGROUPTESTS_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEOUTPUTGROUPTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class NuimeOutputGroupTests : public Ishiko::TestSequence
{
public:
    NuimeOutputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void AddLabelTest1(Ishiko::Test& test);
    static void HasLabelTest1(Ishiko::Test& test);
    static void SetBaseTest1(Ishiko::Test& test);
    static void AddOutputTest1(Ishiko::Test& test);
};

#endif
