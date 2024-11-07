// SPDX-FileCopyrightText: 2017-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CodeSmithyTestSuite.hpp"
#include "CodeSmithyTestSuite/CodeSmithyBuildFileTests.hpp"
#include "CodeSmithyTestSuite/CodeSmithyBuildFileXMLRepositoryTests.hpp"

CodeSmithyTestSuite::CodeSmithyTestSuite(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : Ishiko::TestSequence(number, "CodeSmithy test suite", context)
{
    append<CodeSmithyProjectFileTests>();
    append<CodeSmithyProjectFileXMLRepositoryTests>();
}
