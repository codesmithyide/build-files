/*
    Copyright (c) 2017-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/codesmithyide/build-files/blob/main/LICENSE.txt
*/

#include "Bakefile/BakefilePushParser.hpp"

namespace
{
    bool IsAlphaNum(char c)
    {
        return ((('a' <= c) && (c <= 'z')) || (('A' <= c) && (c <= 'Z')) || (('0' <= c) && (c <= '9')));
    }

    bool IsFilePathChar(char c)
    {
        return (IsAlphaNum(c) || (c == '.') || (c == '/'));
    }

    bool IsWhitespace(char c)
    {
        return ((c == ' ') || (c == '\r') || (c == '\n'));
    }
}

void CodeSmithy::BakefilePushParser::Callbacks::onHeader(boost::string_view path)
{
}

void CodeSmithy::BakefilePushParser::Callbacks::onSource(boost::string_view path)
{
}

void CodeSmithy::BakefilePushParser::Callbacks::onTargetStart(boost::string_view id)
{
}

void CodeSmithy::BakefilePushParser::Callbacks::onToolset(boost::string_view value)
{
}

CodeSmithy::BakefilePushParser::BakefilePushParser(Callbacks& callbacks)
    : m_callbacks{callbacks}
{
    m_parsing_mode_stack.push_back(ParsingMode::bakefile);
}

bool CodeSmithy::BakefilePushParser::onData(boost::string_view data, bool eod)
{
    const char* previous = data.data();
    const char* current = previous;
    const char* end = current + data.length();
    while (current < end)
    {
        switch (m_parsing_mode_stack.back())
        {
        case ParsingMode::bakefile:
            m_parsing_mode_stack.push_back(ParsingMode::whitespace);
            break;

        case ParsingMode::filepath:
            while (current < end)
            {
                if (!IsFilePathChar(*current))
                {
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmented_data.append(previous, (current - previous));
            }
            else
            {
                if (*(m_parsing_mode_stack.end() - 2) == ParsingMode::headers)
                {
                    m_callbacks.onHeader(boost::string_view(previous, (current - previous)));
                    m_parsing_mode_stack.back() = ParsingMode::whitespace;
                }
                else if (*(m_parsing_mode_stack.end() - 2) == ParsingMode::sources)
                {
                    m_callbacks.onSource(boost::string_view(previous, (current - previous)));
                    m_parsing_mode_stack.back() = ParsingMode::whitespace;
                }
                else
                {
                    // TODO: error
                }
            }
            break;

        case ParsingMode::toolsets:
            while (current < end)
            {
                if (*current == ';')
                {
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                // TODO
            }
            else
            {
                ++current;
                m_parsing_mode_stack.pop_back();
            }
            break;

        case ParsingMode::toolset:
            while (current < end)
            {
                if (!IsAlphaNum(*current))
                {
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmented_data.append(previous, (current - previous));
            }
            else
            {
                m_callbacks.onToolset(boost::string_view(previous, (current - previous)));
                m_parsing_mode_stack.back() = ParsingMode::whitespace;
            }
            break;

        case ParsingMode::identifier:
            while (current < end)
            {
                if (!IsAlphaNum(*current))
                {
                    break;
                }
                ++current;
            }
            if (current == end)
            {
                m_fragmented_data.append(previous, (current - previous));
            }
            else
            {
                if (tokenEquals(previous, current, "headers"))
                {
                    m_parsing_mode_stack.back() = ParsingMode::headers;
                    m_parsing_mode_stack.push_back(ParsingMode::whitespace);
                }
                else if (tokenEquals(previous, current, "program"))
                {
                    m_parsing_mode_stack.back() = ParsingMode::target;
                    m_parsing_mode_stack.push_back(ParsingMode::target_id);
                    m_parsing_mode_stack.push_back(ParsingMode::whitespace);
                }
                else if (tokenEquals(previous, current, "sources"))
                {
                    m_parsing_mode_stack.back() = ParsingMode::sources;
                    m_parsing_mode_stack.push_back(ParsingMode::whitespace);
                }
                else if (tokenEquals(previous, current, "toolsets"))
                {
                    m_parsing_mode_stack.back() = ParsingMode::toolsets;
                    m_parsing_mode_stack.push_back(ParsingMode::whitespace);
                }
                else if (*(m_parsing_mode_stack.end() - 2) == ParsingMode::target_id)
                {
                    m_callbacks.onTargetStart(boost::string_view(previous, (current - previous)));
                    m_parsing_mode_stack.pop_back();
                    m_parsing_mode_stack.back() = ParsingMode::whitespace;
                }
                else
                {
                    m_parsing_mode_stack.back() = ParsingMode::whitespace;
                }
            }
            break;

        case ParsingMode::whitespace:
            while (current < end)
            {
                if (!IsWhitespace(*current))
                {
                    break;
                }
                ++current;
            }
            if (current != end)
            {
                if (*current == '=')
                {
                    ++current;
                    m_parsing_mode_stack.back() = ParsingMode::assignment;
                    // TODO: should only enter that state if we are in toolsets mode
                    m_parsing_mode_stack.push_back(ParsingMode::toolsets_value);
                    m_parsing_mode_stack.push_back(ParsingMode::whitespace);
                }
                else if (*current == ';')
                {
                    ++current;
                    m_parsing_mode_stack.pop_back();
                    m_parsing_mode_stack.back() = ParsingMode::whitespace;
                }
                else if (*current == '{')
                {
                    ++current;
                }
                else if (*current == '}')
                {
                    if ((*(m_parsing_mode_stack.end() - 2) == ParsingMode::headers)
                        || (*(m_parsing_mode_stack.end() - 2) == ParsingMode::sources))
                    {
                        m_parsing_mode_stack.pop_back();
                        m_parsing_mode_stack.back() = ParsingMode::whitespace;
                    }
                    ++current;
                }
                else if (*(m_parsing_mode_stack.end() - 2) == ParsingMode::headers)
                {
                    m_parsing_mode_stack.back() = ParsingMode::filepath;
                    previous = current;
                }
                else if (*(m_parsing_mode_stack.end() - 2) == ParsingMode::sources)
                {
                    m_parsing_mode_stack.back() = ParsingMode::filepath;
                    previous = current;
                }
                else if (*(m_parsing_mode_stack.end() - 2) == ParsingMode::toolsets_value)
                {
                    m_parsing_mode_stack.back() = ParsingMode::toolset;
                    previous = current;
                }
                else
                {
                    m_parsing_mode_stack.back() = ParsingMode::identifier;
                    previous = current;
                }
            }
            break;

        default:
            // TODO: error
            break;
        }
    }
    if ((current == end) && eod)
    {
        // TODO: check we are in correct state
        return true;
    }
    return false;
}

bool CodeSmithy::BakefilePushParser::tokenEquals(const char* start, const char* end, const char* token) const
{
    // TODO: take m_fragmented_data into account
    // TOOD: use something that doesn't allocate memory
    return (std::string{start, end} == token);
}
