#ifndef __UTILS_H_
#define __UTILS_H_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>

namespace fs = std::filesystem;

void readData(fs::path);

#endif