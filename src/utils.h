#ifndef __UTILS_H_
#define __UTILS_H_

#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include "Student.h"

namespace fs = std::filesystem;

std::pair<std::string, int> readData(fs::path);
void processData(std::pair<std::string, int>);

#endif