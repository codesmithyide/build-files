/*
    Copyright (c) 2017-2023 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include "BakefilePushParserTests.hpp"
#include "BakefilePushParserTestCallbacks.hpp"
#include "CodeSmithy/BuildFiles/Bakefile/BakefilePushParser.hpp"
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
    CodeSmithy::BakefilePushParser parser{callbacks};

    ISHIKO_TEST_PASS();
}

void BakefilePushParserTests::OnDataTest1(Test& test)
{
    boost::filesystem::path input_path = test.context().getDataPath("MinimalBakefile.bkl");
    std::string bakefile_data = Ishiko::FileSystem::ReadFile(input_path);

    BakefilePushParserTestCallbacks callbacks;
    CodeSmithy::BakefilePushParser parser{callbacks};

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
    CodeSmithy::BakefilePushParser parser{callbacks};

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
    CodeSmithy::BakefilePushParser parser{callbacks};

    bool complete = parser.onData(bakefile_data, true);

    const char* outputFileName = "BakefilePushParserTests_OnDataTest3.xml";
    callbacks.exportToXML(test.context().getOutputPath(outputFileName));

    ISHIKO_TEST_FAIL_IF_NOT(complete);
    ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ(outputFileName);
    ISHIKO_TEST_PASS();
}
