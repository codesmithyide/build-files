// SPDX-FileCopyrightText: 2016-2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#ifndef GUARD_NUIME_BUILDFILES_LINKOPTIONS_HPP
#define GUARD_NUIME_BUILDFILES_LINKOPTIONS_HPP

#ifdef _DEBUG
#pragma comment(lib, "NuimeBuildFiles-d.lib")
#else
#pragma comment(lib, "NuimeBuildFiles.lib")
#endif

#endif
