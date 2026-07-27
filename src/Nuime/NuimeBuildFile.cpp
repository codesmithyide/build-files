// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "Nuime/NuimeBuildFile.hpp"
#include <Ishiko/TidyYAML.hpp>

using namespace Nuime;

NuimeBuildFile::NuimeBuildFile(const NuimeRecipe& recipe)
    : m_recipe(recipe)
{
}

const NuimeRecipe& NuimeBuildFile::recipe() const
{
    return m_recipe;
}
