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

#include "BakefileParserTests.h"
#include "CodeSmithy/BuildFiles/Bakefile/BakefileParser.hpp"
#include <fstream>

BakefileParserTests::BakefileParserTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
	: Ishiko::TestSequence(number, "BakefileParser tests", context)
{
	append<Ishiko::HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
	append<Ishiko::HeapAllocationErrorsTest>("parse test 1", ParseTest1);
	append<Ishiko::HeapAllocationErrorsTest>("parse test 2", ParseTest2);
}

void BakefileParserTests::CreationTest1(Test& test)
{
    boost::filesystem::path inputPath(test.context().getDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileParser parser(input);
    input.close();

	ISHIKO_TEST_PASS();
}

void BakefileParserTests::ParseTest1(Test& test)
{
    boost::filesystem::path inputPath(test.context().getDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileParser parser(input);
    std::shared_ptr<CodeSmithy::Bakefile> bakefile = parser.parse();
    input.close();

	ISHIKO_TEST_FAIL_IF_NOT(bakefile->targets().empty());
	ISHIKO_TEST_PASS();
}

void BakefileParserTests::ParseTest2(Test& test)
{
    boost::filesystem::path inputPath(test.context().getDataDirectory() / "EmptyTargetBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    CodeSmithy::BakefileParser parser(input);
    std::shared_ptr<CodeSmithy::Bakefile> bakefile = parser.parse();
    input.close();

	ISHIKO_TEST_FAIL_IF_NOT(bakefile->targets().size() == 1);
	ISHIKO_TEST_PASS();
}
