/*
    Copyright (c) 2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "BakefilePushParserTestCallbacks.hpp"
#include <Ishiko/XML.hpp>
#include <Ishiko/Errors.hpp>

void BakefilePushParserTestCallbacks::onToolset(boost::string_view value)
{
    m_events.emplace_back("onToolset", value);
}

void BakefilePushParserTestCallbacks::exportToXML(const boost::filesystem::path& path) const
{
    Ishiko::XMLWriter xmlWriter;
    // TODO: handle errors
    Ishiko::Error error;
    xmlWriter.create(path, error);
    xmlWriter.writeXMLDeclaration();
    xmlWriter.writeElementStart("events");
    xmlWriter.increaseIndentation();
    for (const std::pair<std::string, std::string>& e : m_events)
    {
        xmlWriter.writeNewlineAndIndentation();

        xmlWriter.writeElementStart("callback");
        xmlWriter.increaseIndentation();
        xmlWriter.writeNewlineAndIndentation();

        xmlWriter.writeElementStart("name");
        xmlWriter.writeText(e.first);
        xmlWriter.writeElementEnd();
        if (!e.second.empty())
        {
            xmlWriter.writeNewlineAndIndentation();
            xmlWriter.writeElementStart("argument");
            // Escape a few extra characters that are annoying to show in the logs
            Ishiko::XMLEscapedString escapedArgument =
                Ishiko::XMLEscapedString::FromUnescapedString(e.second.c_str(), "\r\n");
            xmlWriter.writeText(escapedArgument);
            xmlWriter.writeElementEnd();
        }

        xmlWriter.decreaseIndentation();
        xmlWriter.writeNewlineAndIndentation();
        xmlWriter.writeElementEnd();
    }
    xmlWriter.decreaseIndentation();
    xmlWriter.writeNewlineAndIndentation();
    xmlWriter.writeElementEnd();
}