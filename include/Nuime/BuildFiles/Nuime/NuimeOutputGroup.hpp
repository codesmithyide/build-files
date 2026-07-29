// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEOUTPUTGROUP_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEOUTPUTGROUP_HPP

#include "NuimeOutput.hpp"
#include <vector>

namespace Nuime
{
    class NuimeOutputGroup
    {
    public:
        const std::vector<NuimeOutput>& outputs() const;
        void addOutput(const NuimeOutput& output);

    private:
        std::vector<NuimeOutput> m_outputs;
    };
}

#endif
