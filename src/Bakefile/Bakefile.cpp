// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Bakefile/Bakefile.hpp"

Nuime::Bakefile::Bakefile()
{
}

Nuime::Bakefile::~Bakefile()
{
}

std::vector<std::shared_ptr<Nuime::BakefileTarget>>& Nuime::Bakefile::targets()
{
    return m_targets;
}
