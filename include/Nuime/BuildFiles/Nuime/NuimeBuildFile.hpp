// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDFILE_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEBUILDFILE_HPP

#include "NuimeRecipe.hpp"
#include <Ishiko/Errors.hpp>
#include <boost/filesystem/path.hpp>
#include <vector>

namespace Nuime
{
    class NuimeBuildFile
    {
    public:
        NuimeBuildFile();
        explicit NuimeBuildFile(const NuimeRecipe& recipe);

        const std::vector<NuimeRecipe>& recipes() const;

        void load(const boost::filesystem::path& path, Ishiko::Error& error);

    private:
        std::vector<NuimeRecipe> m_recipes;
    };
}

#endif
