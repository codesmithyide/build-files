// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDFILE_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDFILE_HPP

#include "NuimeRecipe.hpp"
#include <vector>

namespace Nuime
{
    class NuimeBuildFile
    {
    public:
        NuimeBuildFile();
        explicit NuimeBuildFile(const NuimeRecipe& recipe);

        const std::vector<NuimeRecipe>& recipes() const;

    private:
        std::vector<NuimeRecipe> m_recipes;
    };
}

#endif
