// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "BakefilePushParserTests.hpp"
#include "BakefilePushParserTestCallbacks.hpp"
#include "Nuime/BuildFiles/Bakefile/BakefilePushParser.hpp"
#include <Ishiko/FileSystem.hpp>

BakefilePushParserTests::BakefilePushParserTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
	: Ishiko::TestSequence(number, "BakefilePushParser tests", context)
{
	append<Ishiko::HeapAllocationErrorsTest>("constructor test 1", ConstructorTest1);
	append<Ishiko::HeapAllocationErrorsTest>("onData test 1", OnDataTest1);
	append<Ishiko::HeapAllocationErrorsTest>("onData test 2", OnDataTest2);
    append<Ishiko::HeapAllocationErrorsTest>("onData test 3", OnDataTest3);
}

void BakefilePushParserTests::ConstructorTest1(Test& test)
{
    BakefilePushParserTestCallbacks callbacks;
    Nuime::BakefilePushParser parser{callbacks};

    ISHIKO_TEST_PASS();
}

void BakefilePushParserTests::OnDataTest1(Test& test)
{
    boost::filesystem::path input_path = test.context().getDataPath("MinimalBakefile.bkl");
    std::string bakefile_data = Ishiko::FileSystem::ReadFile(input_path);

    BakefilePushParserTestCallbacks callbacks;
    Nuime::BakefilePushParser parser{callbacks};

    bool complete = parser.onData(bakefile_data, true);

    const char* outputFileName = "BakefilePushParserTests_OnDataTest1.xml";
    callbacks.exportToXML(test.context().getOutputPath(outputFileName));

    ISHIKO_TEST_FAIL_IF_NOT(complete);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputFileName);
	ISHIKO_TEST_PASS();
}

void BakefilePushParserTests::OnDataTest2(Test& test)
{
    boost::filesystem::path input_path = test.context().getDataPath("EmptyTargetBakefile.bkl");
    std::string bakefile_data = Ishiko::FileSystem::ReadFile(input_path);

    BakefilePushParserTestCallbacks callbacks;
    Nuime::BakefilePushParser parser{callbacks};

    bool complete = parser.onData(bakefile_data, true);

    const char* outputFileName = "BakefilePushParserTests_OnDataTest2.xml";
    callbacks.exportToXML(test.context().getOutputPath(outputFileName));

    ISHIKO_TEST_FAIL_IF_NOT(complete);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputFileName);
    ISHIKO_TEST_PASS();
}

void BakefilePushParserTests::OnDataTest3(Test& test)
{
    boost::filesystem::path input_path = test.context().getDataPath("SimpleBakefile1.bkl");
    std::string bakefile_data = Ishiko::FileSystem::ReadFile(input_path);

    BakefilePushParserTestCallbacks callbacks;
    Nuime::BakefilePushParser parser{callbacks};

    bool complete = parser.onData(bakefile_data, true);

    const char* outputFileName = "BakefilePushParserTests_OnDataTest3.xml";
    callbacks.exportToXML(test.context().getOutputPath(outputFileName));

    ISHIKO_TEST_FAIL_IF_NOT(complete);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputFileName);
    ISHIKO_TEST_PASS();
}
