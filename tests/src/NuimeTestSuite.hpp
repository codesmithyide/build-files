// SPDX-FileCopyrightText: 2017-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_NUIMETESTSUITE_HPP

#include <Ishiko/TestFramework.hpp>

class NuimeTestSuite : public Ishiko::TestSequence
{
public:
    NuimeTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);
};

#endif
