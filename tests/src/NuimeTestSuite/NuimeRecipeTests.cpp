// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "NuimeRecipeTests.hpp"
#include "Nuime/BuildFiles/Nuime/NuimeRecipe.hpp"

using namespace Nuime;

NuimeRecipeTests::NuimeRecipeTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context)
    : TestSequence(number, "NuimeRecipe tests", context)
{
    append<Ishiko::HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void NuimeRecipeTests::ConstructorTest1(Ishiko::Test& test)
{
    NuimeTarget target("lib");

    NuimeInputGroup input_group;
    input_group.addInput(NuimeInput("src/Error.cpp"));
    input_group.addInput(NuimeInput("src/Exception.cpp"));
    std::vector<NuimeInputGroup> input_groups;
    input_groups.push_back(input_group);

    NuimeOutputGroup output_group;
    output_group.addOutput(NuimeOutput("IshikoErrors"));
    std::vector<NuimeOutputGroup> output_groups;
    output_groups.push_back(output_group);

    NuimeRecipe recipe(target, input_groups, output_groups);

    ISHIKO_TEST_FAIL_IF_NEQ(recipe.target().name(), "lib");
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.inputGroups().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.inputGroups()[0].inputs().size(), 2);
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.inputGroups()[0].inputs()[0].asString(), "src/Error.cpp");
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.inputGroups()[0].inputs()[1].asString(), "src/Exception.cpp");
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.outputGroups().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.outputGroups()[0].outputs().size(), 1);
    ISHIKO_TEST_FAIL_IF_NEQ(recipe.outputGroups()[0].outputs()[0].asString(), "IshikoErrors");
    ISHIKO_TEST_PASS();
}
