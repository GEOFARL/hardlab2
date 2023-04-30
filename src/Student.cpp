#include "Student.h"

Student::Student(std::string lname, int newSubjects[], bool onContract)
    : lname{lname}, onContract{onContract}
{
  for (int i{}; i < Student::NUM_OF_SUBJECTS; ++i)
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

void Student::setSubjects(int newSubjects[])
{
  if (newSubjects == nullptr)
  {
    std::cerr << "Error: Null pointer passed to setSubjects()" << std::endl;
    return;
  }

  for (int i{}; i < Student::NUM_OF_SUBJECTS; ++i)
  {
    if (newSubjects[i] < 0 || newSubjects[i] > 100)
    {
      std::cerr << "Error: Invalid score " << newSubjects[i] << " passed to setSubjects()" << std::endl;
      return;
    }
    subjects[i] = newSubjects[i];
  }
}
void Student::setOnContract(bool newOnContract) { onContract = newOnContract; }

std::string Student::getLname() const { return lname; }

int *Student::getSubjects() const
{
  int *copy = new int[NUM_OF_SUBJECTS];
  for (int i = 0; i < NUM_OF_SUBJECTS; i++)
  {
    copy[i] = subjects[i];
  }
  return copy;
}

bool Student::getOnContract() const { return onContract; }

float Student::getAverageScore() const
{
  float sum{};
  for (int i{}; i < Student::NUM_OF_SUBJECTS; ++i)
  {
    sum += subjects[i];
  }
  return sum / Student::NUM_OF_SUBJECTS;
}

std::ostream &operator<<(std::ostream &os, const Student &student)
{
  os << student.lname << ",";
  for (int i{}; i < Student::NUM_OF_SUBJECTS; ++i)
  {
    os << student.subjects[i] << ",";
  }
  os << (student.onContract ? "TRUE" : "FALSE");
  return os;
}
