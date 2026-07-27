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
}

void NuimeBuildFileTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeTarget target("lib");
    std::vector<NuimeInput> inputs;
    inputs.push_back(NuimeInput("src/main.cpp"));
    std::vector<NuimeOutput> outputs;
    outputs.push_back(NuimeOutput("example"));
    NuimeRecipe recipe(target, inputs, outputs);

    NuimeBuildFile build_file(recipe);

    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipe().target().asString(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipe().inputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(build_file.recipe().outputs().size(), 1);
    ISHIKO_TEST_PASS();
}
