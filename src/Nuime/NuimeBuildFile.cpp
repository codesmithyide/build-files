// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeBuildFile.hpp"
#include <Ishiko/TidyYAML.hpp>

using namespace Nuime;

NuimeBuildFile::NuimeBuildFile()
{
}

NuimeBuildFile::NuimeBuildFile(const NuimeRecipe& recipe)
{
    m_recipes.push_back(recipe);
}

const std::vector<NuimeRecipe>& NuimeBuildFile::recipes() const
{
    return m_recipes;
}
