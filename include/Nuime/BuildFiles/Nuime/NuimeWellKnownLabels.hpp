// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_NUIME_NUIMEWELLKNOWNLABELS_HPP
#define GUARD_NUIME_BUILDFILES_NUIME_NUIMEWELLKNOWNLABELS_HPP

namespace Nuime
{
    // Well-known label strings defined by nuime. Labels are convention rather than part of the core
    // spec, but these values under the reserved "nuime:" prefix are provided here so tooling can
    // reference them by name.
    struct WellKnownLabels
    {
        static const char* const k_executable;
        static const char* const k_static_library;
    };
}

#endif
