// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_TESTS_MSBUILDTESTSUITE_HPP
#define GUARD_NUIME_BUILDFILES_TESTS_MSBUILDTESTSUITE_HPP

#include <Ishiko/TestFramework.hpp>

class MSBuildTestSuite : public Ishiko::TestSequence
{
public:
    MSBuildTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);
};

#endif
