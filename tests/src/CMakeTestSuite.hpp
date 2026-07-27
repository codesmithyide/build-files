// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_CMAKETESTSUITE_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_CMAKETESTSUITE_HPP

#include <Ishiko/TestFramework.hpp>

class CMakeTestSuite : public Ishiko::TestSequence
{
public:
    CMakeTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);
};

#endif
