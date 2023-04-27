#include "utils.h"

std::pair<std::string, int>readData(fs::path path)
{
  int numOfStudents{};
  std::string text{};
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
      std::getline(infile, line);
      numOfStudents += stoi(line);

      while(std::getline(infile, line))
      {
        text += line + '\n';
      }
    }
  }

  return std::make_pair(text, numOfStudents);
}