// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeBuildFileTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeBuildFile.hpp"

using namespace Nuime;
using namespace boost::filesystem;

NuimeBuildFileTests::NuimeBuildFileTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeBuildFile tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
    append<Ishiko::HeapAllocationErrorsTest>("load test 1", LoadTest1);
}

void NuimeBuildFileTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeBuildFile build_file;

    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeBuildFileTests::ConstructorTest2(Ishiko::Test& test)
{
    NuimeTarget target("lib");
    std::vector<NuimeInput> inputs;
    inputs.push_back(NuimeInput("src/main.cpp"));
    std::vector<NuimeOutput> outputs;
    outputs.push_back(NuimeOutput("example"));
    NuimeRecipe recipe(target, inputs, outputs);

    NuimeBuildFile build_file(recipe);

    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].target().asString(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputs().size(), 1);
    ISHIKO_TEST_PASS();
}

void NuimeBuildFileTests::LoadTest1(Ishiko::Test& test)
{
    boost::filesystem::path input_path = test.context().getDataPath("minimal.nuime");

    NuimeBuildFile build_file;

    Ishiko::Error error;
    build_file.load(input_path, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].target().asString(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputs()[0].asString(), "src/main.cpp");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputs()[0].asString(), "example");
    ISHIKO_TEST_PASS();
}
