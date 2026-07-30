// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeOutputGroup.hpp"

using namespace Nuime;

const std::vector<NuimeLabel>& NuimeOutputGroup::labels() const
{
    return m_labels;
}

void NuimeOutputGroup::addLabel(const NuimeLabel& label)
{
    m_labels.push_back(label);
}

bool NuimeOutputGroup::hasLabel(const std::string& label) const
{
    for (const NuimeLabel& group_label : m_labels)
    {
        if (group_label.asString() == label)
        {
            return true;
        }
    }
    return false;
}

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
