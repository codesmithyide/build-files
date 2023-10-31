/*
    Copyright (c) 2020 Xavier Leclercq
    Released under the MIT License
    See https://github.com/CodeSmithyIDE/BuildFiles/blob/master/LICENSE.txt
*/

#ifndef _CODESMITHYIDE_BUILDFILES_LINKOPTIONS_H_
#define _CODESMITHYIDE_BUILDFILES_LINKOPTIONS_H_

#ifdef _DEBUG
#pragma comment(lib, "CodeSmithyBuildFiles-d.lib")
#else
#pragma comment(lib, "CodeSmithyBuildFiles.lib")
#endif

#endif
