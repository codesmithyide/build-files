// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef _CODESMITHY_TEST_CORE_PROJECTTESTS_PROJECTFILEREPOSITORYTESTS_H_
#define _CODESMITHY_TEST_CORE_PROJECTTESTS_PROJECTFILEREPOSITORYTESTS_H_

#include <Ishiko/TestFramework.hpp>

class CodeSmithyProjectFileXMLRepositoryTests : public Ishiko::TestSequence
{
public:
    CodeSmithyProjectFileXMLRepositoryTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void CreateTest1(Ishiko::Test& test);
    static void OpenTest1(Ishiko::Test& test);
    static void OpenTest2(Ishiko::Test& test);
    static void SetNameTest1(Ishiko::Test& test);
    static void AddProjectNodeTest1(Ishiko::Test& test);
    static void GetProjectNodeTest1(Ishiko::Test& test);
};

#endif
