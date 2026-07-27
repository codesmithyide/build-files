// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDFILE_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDFILE_HPP

#include "NuimeRecipe.hpp"

namespace Nuime
{
    // TODO: this should hold a list of targets. For now it just holds a single recipe.
    class NuimeBuildFile
    {
    public:
        explicit NuimeBuildFile(const NuimeRecipe& recipe);

        const NuimeRecipe& recipe() const;

    private:
        NuimeRecipe m_recipe;
    };
}

#endif
