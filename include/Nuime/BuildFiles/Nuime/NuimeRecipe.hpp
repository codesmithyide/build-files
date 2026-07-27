// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMERECIPE_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMERECIPE_HPP

#include "NuimeInput.hpp"
#include "NuimeTarget.hpp"
#include <vector>

namespace Nuime
{
    class NuimeRecipe
    {
    public:
        NuimeRecipe(const NuimeTarget& target, const std::vector<NuimeInput>& inputs);

        const NuimeTarget& target() const;
        const std::vector<NuimeInput>& inputs() const;

    private:
        NuimeTarget m_target;
        std::vector<NuimeInput> m_inputs;
    };
}

#endif
