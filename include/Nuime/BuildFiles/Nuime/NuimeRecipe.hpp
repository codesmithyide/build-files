// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMERECIPE_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMERECIPE_HPP

#include "NuimeInputGroup.hpp"
#include "NuimeOutputGroup.hpp"
#include "NuimeTarget.hpp"
#include <vector>

namespace Nuime
{
    class NuimeRecipe
    {
    public:
        NuimeRecipe(const NuimeTarget& target, const std::vector<NuimeInputGroup>& input_groups,
            const std::vector<NuimeOutputGroup>& output_groups);

        const NuimeTarget& target() const;
        const std::vector<NuimeInputGroup>& inputGroups() const;
        const std::vector<NuimeOutputGroup>& outputGroups() const;

    private:
        NuimeTarget m_target;
        std::vector<NuimeInputGroup> m_input_groups;
        std::vector<NuimeOutputGroup> m_output_groups;
    };
}

#endif
