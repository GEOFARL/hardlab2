#include "utils.h"

void readData(fs::path path)
{
  for (const fs::directory_entry &dir_entry : fs::recursive_directory_iterator(path))
  {
    std::cout << dir_entry.path().filename().string() << std::endl;
  }
}