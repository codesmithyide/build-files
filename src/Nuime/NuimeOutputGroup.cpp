// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeOutputGroup.hpp"

using namespace Nuime;

const std::string& NuimeOutputGroup::base() const
{
    return m_base;
}

void NuimeOutputGroup::setBase(const std::string& base)
{
    m_base = base;
}

const std::vector<NuimeOutput>& NuimeOutputGroup::outputs() const
{
    return m_outputs;
}

void NuimeOutputGroup::addOutput(const NuimeOutput& output)
{
    m_outputs.push_back(output);
}
