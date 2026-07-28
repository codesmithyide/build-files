// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeOutput.hpp"

using namespace Nuime;

NuimeOutput::NuimeOutput(const std::string& value)
    : m_value(value)
{
}

const std::string& NuimeOutput::asString() const
{
    return m_value;
}
