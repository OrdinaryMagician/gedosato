#pragma once

#include "version.h"

const char* VER_NAME = "Forlane | Rei";

const unsigned VER_MAJOR = 0;
const unsigned VER_MINOR = 17;
const unsigned VER_BUILD = 1771;

const char* VER_STRING = "version 0.17.1771 built on 2015/04/06 17:36:14";

#ifdef _DEBUG
const char* MODE_STRING = "DEBUG";
#else
const char* MODE_STRING = "RELEASE";
#endif

