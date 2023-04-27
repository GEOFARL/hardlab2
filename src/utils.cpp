#include "utils.h"

std::pair<std::string, int> readData(fs::path path)
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

      while (std::getline(infile, line))
      {
        text += line + '\n';
      }
    }
  }

  return std::make_pair(text, numOfStudents);
}

Student parseEntry(std::string line)
{
  std::istringstream iss{line};
  std::string lname{};
  int subjects[Student::NUM_OF_SUBJECTS]{};
  bool onContract{};

  std::getline(iss, lname, ',');
  for (int i{}; i < Student::NUM_OF_SUBJECTS; ++i)
  {
    iss >> subjects[i];
    iss.ignore(); // ignore the comma separator
  }
  iss >> std::boolalpha >> onContract;

  return Student(lname, subjects, onContract);
}

void processData(std::pair<std::string, int> data)
{
  int numOfStudents = data.second;
  std::string text = data.first;

  Student *students = new Student[numOfStudents];
  std::string line{};
  std::istringstream iss{text};

  for (int i{}; i < numOfStudents; ++i)
  {
    getline(iss, line);
    students[i] = parseEntry(line);
    std::cout << students[i] << std::endl;
  }

  delete[] students;
}
