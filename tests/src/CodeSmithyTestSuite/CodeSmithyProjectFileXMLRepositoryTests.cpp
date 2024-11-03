// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CodeSmithyProjectFileXMLRepositoryTests.hpp"
#include "CodeSmithy/BuildFiles/CodeSmithy/CodeSmithyProjectFileXMLRepository.hpp"

using namespace CodeSmithy;
using namespace boost::filesystem;

CodeSmithyProjectFileXMLRepositoryTests::CodeSmithyProjectFileXMLRepositoryTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : TestSequence(number, "CodeSmithyProjectFileXMLRepository tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("create test 1", CreateTest1);
    append<Ishiko::HeapAllocationErrorsTest>("open test 1", OpenTest1);
    append<Ishiko::HeapAllocationErrorsTest>("open test 2", OpenTest2);
    append<Ishiko::HeapAllocationErrorsTest>("setName test 1", SetNameTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addProjectNode test 1", AddProjectNodeTest1);
    append<Ishiko::HeapAllocationErrorsTest>("getProjectNode test 1", GetProjectNodeTest1);
}

void CodeSmithyProjectFileXMLRepositoryTests::ConstructorTest1(Ishiko::Test& test)
{
    CodeSmithyProjectFileXMLRepository repository;

    ISHIKO_TEST_PASS();
}

void CodeSmithyProjectFileXMLRepositoryTests::CreateTest1(Ishiko::Test& test)
{
    const char* outputName = "ProjectRepositoryTests_CreateTest1.csmthprj";
    
    Ishiko::Error error;
    CodeSmithyProjectFileXMLRepository repository;
    repository.create(test.context().getOutputPath(outputName), error);
    repository.close();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "");
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputName);
    ISHIKO_TEST_PASS();
}

void CodeSmithyProjectFileXMLRepositoryTests::OpenTest1(Ishiko::Test& test)
{
    path inputPath = test.context().getDataPath("ProjectRepositoryTests_OpenTest1.csmthprj");

    Ishiko::Error error;

    CodeSmithyProjectFileXMLRepository repository;
    repository.open(inputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "");
    ISHIKO_TEST_PASS();
}

void CodeSmithyProjectFileXMLRepositoryTests::OpenTest2(Ishiko::Test& test)
{
    path inputPath = test.context().getDataPath("ProjectRepositoryTests_OpenTest2.csmthprj");

    Ishiko::Error error;

    CodeSmithyProjectFileXMLRepository repository;
    repository.open(inputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "ProjectRepositoryTests_OpenTest2");
    ISHIKO_TEST_PASS();
}

void CodeSmithyProjectFileXMLRepositoryTests::SetNameTest1(Ishiko::Test& test)
{
    const char* outputName = "ProjectRepositoryTests_SetNameTest1.csmthprj";

    Ishiko::Error error;
    CodeSmithyProjectFileXMLRepository repository;
    repository.create(test.context().getOutputPath(outputName), error);
    repository.setName("ProjectRepositoryTests_SetNameTest1");
    repository.close();
    
    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "ProjectRepositoryTests_SetNameTest1");
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputName);
    ISHIKO_TEST_PASS();
}

void CodeSmithyProjectFileXMLRepositoryTests::AddProjectNodeTest1(Ishiko::Test& test)
{
    const char* outputName = "ProjectRepositoryTests_AddProjectNodeTest1.csmthprj";

    Ishiko::Error error;
    CodeSmithyProjectFileXMLRepository repository;
    repository.create(test.context().getOutputPath(outputName), error);
    repository.setName("ProjectRepositoryTests_AddProjectNodeTest1");
    DiplodocusDB::XMLTreeDBNode project1 = repository.addProjectNode("Project1", error);
    repository.close();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputName);
    ISHIKO_TEST_PASS();
}

void CodeSmithyProjectFileXMLRepositoryTests::GetProjectNodeTest1(Ishiko::Test& test)
{
    boost::filesystem::path inputPath =
        test.context().getDataPath("ProjectRepositoryTests_GetProjectNodeTest1.csmthprj");

    Ishiko::Error error;

    CodeSmithyProjectFileXMLRepository repository;
    repository.open(inputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "ProjectRepositoryTests_GetProjectNodeTest1");

    DiplodocusDB::XMLTreeDBNode projectNode = repository.getProjectNode("Project1", error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(projectNode);
    ISHIKO_TEST_PASS();
}
