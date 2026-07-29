// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeRecipe.hpp"

using namespace Nuime;

NuimeRecipe::NuimeRecipe(const NuimeTarget& target, const std::vector<NuimeInputGroup>& input_groups,
    const std::vector<NuimeOutputGroup>& output_groups)
    : m_target(target), m_input_groups(input_groups), m_output_groups(output_groups)
{
}

const NuimeTarget& NuimeRecipe::target() const
{
    return m_target;
}

const std::vector<NuimeInputGroup>& NuimeRecipe::inputGroups() const
{
    return m_input_groups;
}

const std::vector<NuimeOutputGroup>& NuimeRecipe::outputGroups() const
{
    return m_output_groups;
}
