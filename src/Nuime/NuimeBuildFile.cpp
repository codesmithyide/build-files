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

void NuimeBuildFile::load(const boost::filesystem::path& path, Ishiko::Error& error)
{
    try
    {
        YAML::Node root = YAML::LoadFile(path.string());

        for (const auto& target_node : root["targets"])
        {
            NuimeTarget target(target_node["name"].as<std::string>());

            // Groups are not represented internally yet: flatten every input-group's inputs
            // straight into the recipe's input list.
            std::vector<NuimeInput> inputs;
            for (const auto& group : target_node["input-groups"])
            {
                for (const auto& input : group["inputs"])
                {
                    inputs.push_back(NuimeInput(input.as<std::string>()));
                }
            }

            // Same for the output-groups.
            std::vector<NuimeOutput> outputs;
            for (const auto& group : target_node["output-groups"])
            {
                for (const auto& output : group["outputs"])
                {
                    outputs.push_back(NuimeOutput(output.as<std::string>()));
                }
            }

            m_recipes.push_back(NuimeRecipe(target, inputs, outputs));
        }
    }
    catch (const std::exception& e)
    {
        error.fail(Ishiko::ErrorsErrorCategory::Get(),
            static_cast<int>(Ishiko::ErrorsErrorCategory::Value::generic_error), e.what(), __FILE__, __LINE__);
    }
}
