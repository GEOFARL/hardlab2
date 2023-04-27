#include "utils.h"

void readData(fs::path path)
{
  for (const fs::directory_entry &dir_entry : fs::recursive_directory_iterator(path))
  {
    if (dir_entry.path().extension() == ".csv")
    {
      std::ifstream infile(dir_entry.path());
      if (!infile)
      {
        throw std::runtime_error("Error opening file " + dir_entry.path().string());
      }

      std::string line{};
      while(std::getline(infile, line))
      {
        std::cout << line << std::endl;
      }
    }
  }
}