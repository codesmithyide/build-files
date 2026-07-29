// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEINPUTGROUPTESTS_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_NUIMEINPUTGROUPTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class NuimeInputGroupTests : public Ishiko::TestSequence
{
public:
    NuimeInputGroupTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void AddInputTest1(Ishiko::Test& test);
};

#endif
