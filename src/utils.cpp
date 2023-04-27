#include "utils.h"

const std::string OUTPUT_FILENAME = "rating.csv";

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

  std::string word{};
  iss >> word;
  onContract = word == "TRUE";

  return Student(lname, subjects, onContract);
}

void saveData(Student *students, int numOfSuccesfulStudents, int numOfStudents)
{
  std::ofstream outfile(OUTPUT_FILENAME);
  if (!outfile)
  {
    throw std::runtime_error("Error opening file for saving data");
  }

  int index{};

  for (int i{}; i < numOfStudents; ++i)
  {
    if (!students[i].getOnContract())
    {
      outfile << students[i].getLname() << "," << std::fixed << std::setprecision(3)
              << students[i].getAverageScore() << std::endl;
      index += 1;
      if (index == numOfSuccesfulStudents)
      {
        std::cout << "Minimal score for scholarship: " << students[i].getAverageScore() << std::endl;
        break;
      }
    }
  }

  outfile.close();
}

void processData(std::pair<std::string, int> data)
{
  int numOfStudents = data.second;
  std::string text = data.first;

  Student *students = new Student[numOfStudents];
  std::string line{};
  std::istringstream iss{text};

  int numOfBudgetStudents{};

  for (int i{}; i < numOfStudents; ++i)
  {
    getline(iss, line);
    students[i] = parseEntry(line);
    numOfBudgetStudents += students[i].getOnContract() ? 0 : 1;
  }

  std::sort(students, students + numOfStudents,
            [](const Student &s1, const Student &s2)
            {
              return s1.getAverageScore() > s2.getAverageScore();
            });
  int numOfSuccessfulStudents = 0.4 * numOfBudgetStudents;

  saveData(students, numOfSuccessfulStudents, numOfStudents);
  delete[] students;
}
