#pragma once

#include <glog/logging.h>

#include "globalInclude.h"


Result handleCommandLineArgs(int argc, char** argv);
Result setGlog(const char* programName, const int logLelvel, const char* logFileFullPath);
