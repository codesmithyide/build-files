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
    append<Ishiko::HeapAllocationErrorsTest>("load test 2", LoadTest2);
}

void NuimeBuildFileTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeBuildFile build_file;

    ISHIKO_TEST_FAIL_IF_NEQ(build_file.name(), "");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes().size(), 0);
    ISHIKO_TEST_PASS();
}

void NuimeBuildFileTests::ConstructorTest2(Ishiko::Test& test)
{
    NuimeTarget target("lib");

    NuimeInputGroup input_group;
    input_group.addInput(NuimeInput("src/main.cpp"));
    std::vector<NuimeInputGroup> input_groups;
    input_groups.push_back(input_group);

    NuimeOutputGroup output_group;
    output_group.addOutput(NuimeOutput("example"));
    std::vector<NuimeOutputGroup> output_groups;
    output_groups.push_back(output_group);

    NuimeRecipe recipe(target, input_groups, output_groups);

    NuimeBuildFile build_file(recipe);

    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].target().name(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputGroups().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputGroups().size(), 1);
    ISHIKO_TEST_PASS();
}

void NuimeBuildFileTests::LoadTest1(Ishiko::Test& test)
{
    boost::filesystem::path input_path = test.context().getDataPath("minimal.nuime");

    NuimeBuildFile build_file;

    Ishiko::Error error;
    build_file.load(input_path, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.name(), "example");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].target().name(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputGroups().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputGroups()[0].inputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputGroups()[0].inputs()[0].asString(), "src/main.cpp");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputGroups().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputGroups()[0].outputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputGroups()[0].outputs()[0].asString(), "example");
    ISHIKO_TEST_PASS();
}

void NuimeBuildFileTests::LoadTest2(Ishiko::Test& test)
{
    boost::filesystem::path input_path = test.context().getDataPath("minimal_with_label.nuime");

    NuimeBuildFile build_file;

    Ishiko::Error error;
    build_file.load(input_path, error);

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.name(), "example");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].target().name(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].target().labels().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].target().labels()[0].asString(), "nuime:product");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].inputGroups().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipes()[0].outputGroups().size(), 1);
    ISHIKO_TEST_PASS();
}
