// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeOutputGroup.hpp"

using namespace Nuime;

const std::vector<NuimeOutput>& NuimeOutputGroup::outputs() const
{
    return m_outputs;
}

void NuimeOutputGroup::addOutput(const NuimeOutput& output)
{
    m_outputs.push_back(output);
}
