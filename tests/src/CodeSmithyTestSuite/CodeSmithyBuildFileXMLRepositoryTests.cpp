// SPDX-FileCopyrightText: 2016-2024 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CodeSmithyBuildFileXMLRepositoryTests.hpp"
#include "CodeSmithy/BuildFiles/CodeSmithy/CodeSmithyBuildFileXMLRepository.hpp"

using namespace CodeSmithy;
using namespace boost::filesystem;

CodeSmithyBuildFileXMLRepositoryTests::CodeSmithyBuildFileXMLRepositoryTests(const Ishiko::TestNumber& number,
    const Ishiko::TestContext& context)
    : TestSequence(number, "CodeSmithyBuildFileXMLRepository tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("create test 1", CreateTest1);
    append<Ishiko::HeapAllocationErrorsTest>("open test 1", OpenTest1);
    append<Ishiko::HeapAllocationErrorsTest>("open test 2", OpenTest2);
    append<Ishiko::HeapAllocationErrorsTest>("setName test 1", SetNameTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addBuildFileNode test 1", AddBuildFileNodeTest1);
    append<Ishiko::HeapAllocationErrorsTest>("getBuildFileNode test 1", GetBuildFileNodeTest1);
    append<Ishiko::HeapAllocationErrorsTest>("addSourceFile test 1", AddSourceFileTest1);
}

void CodeSmithyBuildFileXMLRepositoryTests::ConstructorTest1(Ishiko::Test& test)
{
    CodeSmithyBuildFileXMLRepository repository;

    ISHIKO_TEST_PASS();
}

void CodeSmithyBuildFileXMLRepositoryTests::CreateTest1(Ishiko::Test& test)
{
    const char* outputName = "ProjectRepositoryTests_CreateTest1.csmthprj";
    
    Ishiko::Error error;
    CodeSmithyBuildFileXMLRepository repository;
    repository.create(test.context().getOutputPath(outputName), error);
    repository.close();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "");
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputName);
    ISHIKO_TEST_PASS();
}

void CodeSmithyBuildFileXMLRepositoryTests::OpenTest1(Ishiko::Test& test)
{
    path inputPath = test.context().getDataPath("ProjectRepositoryTests_OpenTest1.csmthprj");

    Ishiko::Error error;

    CodeSmithyBuildFileXMLRepository repository;
    repository.open(inputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "");
    ISHIKO_TEST_PASS();
}

void CodeSmithyBuildFileXMLRepositoryTests::OpenTest2(Ishiko::Test& test)
{
    path inputPath = test.context().getDataPath("ProjectRepositoryTests_OpenTest2.csmthprj");

    Ishiko::Error error;

    CodeSmithyBuildFileXMLRepository repository;
    repository.open(inputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "ProjectRepositoryTests_OpenTest2");
    ISHIKO_TEST_PASS();
}

void CodeSmithyBuildFileXMLRepositoryTests::SetNameTest1(Ishiko::Test& test)
{
    const char* outputName = "ProjectRepositoryTests_SetNameTest1.csmthprj";

    Ishiko::Error error;
    CodeSmithyBuildFileXMLRepository repository;
    repository.create(test.context().getOutputPath(outputName), error);
    repository.setName("ProjectRepositoryTests_SetNameTest1");
    repository.close();
    
    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "ProjectRepositoryTests_SetNameTest1");
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputName);
    ISHIKO_TEST_PASS();
}

void CodeSmithyBuildFileXMLRepositoryTests::AddBuildFileNodeTest1(Ishiko::Test& test)
{
    const char* outputName = "ProjectRepositoryTests_AddProjectNodeTest1.csmthprj";

    Ishiko::Error error;
    CodeSmithyBuildFileXMLRepository repository;
    repository.create(test.context().getOutputPath(outputName), error);
    repository.setName("ProjectRepositoryTests_AddProjectNodeTest1");
    DiplodocusDB::XMLTreeDBNode project1 = repository.addBuildFileNode("Project1", error);
    repository.close();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputName);
    ISHIKO_TEST_PASS();
}

void CodeSmithyBuildFileXMLRepositoryTests::GetBuildFileNodeTest1(Ishiko::Test& test)
{
    boost::filesystem::path inputPath =
        test.context().getDataPath("ProjectRepositoryTests_GetProjectNodeTest1.csmthprj");

    Ishiko::Error error;

    CodeSmithyBuildFileXMLRepository repository;
    repository.open(inputPath, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(repository.name() == "ProjectRepositoryTests_GetProjectNodeTest1");

    std::unique_ptr<CodeSmithyBuildFile> build_file = repository.getBuildFileNode("Project1", error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NOT(build_file);
    ISHIKO_TEST_PASS();
}

void CodeSmithyBuildFileXMLRepositoryTests::AddSourceFileTest1(Ishiko::Test& test)
{
    const char* output_name = "CodeSmithyBuildFileXMLRepositoryTests_AddSourceFileTest1.csbld";

    Ishiko::Error error;
    CodeSmithyBuildFileXMLRepository repository;
    repository.create(test.context().getOutputPath(output_name), error);
    repository.setName("CodeSmithyBuildFileXMLRepositoryTests_AddSourceFileTest1");
    repository.addBuildFileNode("Project1", error);

    ISHIKO_TEST_ABORT_IF(error);

    std::unique_ptr<CodeSmithyBuildFile> build_file = repository.getBuildFileNode("Project1", error);

    ISHIKO_TEST_ABORT_IF(error);

    build_file->addSourceFile("SourceFile1");

    repository.close();

    
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(output_name);
    ISHIKO_TEST_PASS();
}
