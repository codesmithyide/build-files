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
    NuimeBuildFile build_file;

    ISHIKO_TEST_PASS();
}
