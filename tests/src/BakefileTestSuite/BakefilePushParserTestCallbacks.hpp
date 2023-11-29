/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#ifndef GUARD_CODESMITHYIDE_BUILDFILES_TESTS_BAKEFILETESTSUITE_BAKEFILEPUSHPARSERTESTCALLBACKS_HPP
#define GUARD_CODESMITHYIDE_BUILDFILES_TESTS_BAKEFILETESTSUITE_BAKEFILEPUSHPARSERTESTCALLBACKS_HPP

#include "CodeSmithy/BuildFiles/Bakefile/BakefilePushParser.hpp"
#include <boost/filesystem.hpp>
#include <string>
#include <utility>
#include <vector>

class BakefilePushParserTestCallbacks : public CodeSmithy::BakefilePushParser::Callbacks
{
public:
    void onTargetStart(boost::string_view id) override;
    void onToolset(boost::string_view value) override;

    void exportToXML(const boost::filesystem::path& path) const;

private:
    std::vector<std::pair<std::string, std::string>> m_events;
};

#endif
