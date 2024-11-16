// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_TESTS_CODESMITHYTESTSUITE_CODESMITHYBUILDFILEXMLREPOSITORYTESTS_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_TESTS_CODESMITHYTESTSUITE_CODESMITHYBUILDFILEXMLREPOSITORYTESTS_HPP

#include <Ishiko/TestFramework.hpp>

class CodeSmithyBuildFileXMLRepositoryTests : public Ishiko::TestSequence
{
public:
    CodeSmithyBuildFileXMLRepositoryTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CreateTest1(Ishiko::Test& test);
    static void OpenTest1(Ishiko::Test& test);
    static void OpenTest2(Ishiko::Test& test);
    static void SetNameTest1(Ishiko::Test& test);
    static void AddBuildFileNodeTest1(Ishiko::Test& test);
    static void GetBuildFileNodeTest1(Ishiko::Test& test);
    static void AddProjectTest1(Ishiko::Test& test);
    static void AddSourceFileTest1(Ishiko::Test& test);
};

#endif
