#include "Student.h"

Student::Student(std::string lname, const Array<int> &newSubjects, bool onContract)
    : lname{lname}, subjects{Array<int>{newSubjects.getSize()}}, onContract{onContract}
{
  for (int i{}; i < newSubjects.getSize(); ++i)
  {
    if (newSubjects[i] < Student::MIN_SCORE || newSubjects[i] > Student::MAX_SCORE)
    {
      std::cerr << "Error: Invalid score " << newSubjects[i] << " passed to constructor" << std::endl;
      return;
    }
    subjects[i] = newSubjects[i];
  }
}

void Student::setLname(std::string newLname) { lname = newLname; }

void Student::setSubjects(const Array<int> &newSubjects)
{
  if (newSubjects.getSize() == 0)
  {
    std::cerr << "Error: empty subjects array provided" << std::endl;
    return;
  }
  subjects = newSubjects;
}

void Student::setOnContract(bool newOnContract) { onContract = newOnContract; }

std::string Student::getLname() const { return lname; }

const Array<int> Student::getSubjects() const
{
  return subjects;
}

bool Student::getOnContract() const { return onContract; }

float Student::getAverageScore() const
{
  float sum{};
  for (int i{}; i < subjects.getSize(); ++i)
  {
    sum += subjects[i];
  }
  return sum / subjects.getSize();
}

std::ostream &operator<<(std::ostream &os, const Student &student)
{
  os << student.lname << ",";
  for (int i{}; i < student.subjects.getSize(); ++i)
  {
    os << student.subjects[i] << ",";
  }
  os << (student.onContract ? "TRUE" : "FALSE");
  return os;
}
