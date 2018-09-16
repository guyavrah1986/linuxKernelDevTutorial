#pragma once

#include <glog/logging.h>

#include "globalInclude.h"

const std::string LOGS_PATH_PREFIX = "/tmp/guyProj";

Result handleCommandLineArgs(int argc, char** argv);
Result setGlog(const char* programName, const int logLelvel, const char* logFileFullPath);
