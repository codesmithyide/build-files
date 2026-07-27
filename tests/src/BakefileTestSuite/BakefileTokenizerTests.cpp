// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "BakefileTokenizerTests.h"
#include "Nuime/BuildFiles/Bakefile/BakefileTokenizer.hpp"
#include <fstream>

BakefileTokenizerTests::BakefileTokenizerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
	: Ishiko::TestSequence(number, "BakefileTokenizer tests", context)
{
	append<Ishiko::HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
	append<Ishiko::HeapAllocationErrorsTest>("getNextToken test 1", GetNextToken);
}

void BakefileTokenizerTests::CreationTest1(Ishiko::Test& test)
{
    boost::filesystem::path inputPath(test.context().getDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    Nuime::BakefileTokenizer tokenizer(input);

	ISHIKO_TEST_PASS();
}

void BakefileTokenizerTests::GetNextToken(Ishiko::Test& test)
{
    boost::filesystem::path inputPath(test.context().getDataDirectory() / "MinimalBakefile.bkl");

    std::ifstream input(inputPath.c_str());
    Nuime::BakefileTokenizer tokenizer(input);
    Nuime::BakefileToken token;

	ISHIKO_TEST_FAIL_IF_NOT(tokenizer.getNextToken(token) == Nuime::BakefileTokenizer::eEnd);
    ISHIKO_TEST_PASS();
}
