#ifndef __UTILS_H_
#define __UTILS_H_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>

namespace fs = std::filesystem;

std::pair<std::string, int> readData(fs::path);

#endif