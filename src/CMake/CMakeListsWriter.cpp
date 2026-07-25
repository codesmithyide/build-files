// SPDX-FileCopyrightText: 2017-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CMake/CMakeListsWriter.hpp"

using namespace CodeSmithy;

CMakeListsWriter::CMakeListsWriter(const boost::filesystem::path& output_file, Ishiko::Error& error)
{
    m_output_file.create(output_file, error);
}

void CMakeListsWriter::close()
{
    m_output_file.close();
}

void CMakeListsWriter::writeAddLibraryCommand()
{
    // TODO
}

void CMakeListsWriter::writeCMakeMinimumRequiredCommand(const std::string& version)
{
    m_output_file.write("cmake_minimum_required(VERSION ");
    m_output_file.write(version);
    m_output_file.writeLine(")");
}

void CMakeListsWriter::writeProjectCommand(const std::string& project_name)
{
    m_output_file.write("project(");
    m_output_file.write(project_name);
    m_output_file.writeLine(" LANGUAGES CXX)");
}
