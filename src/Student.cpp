#include "Student.h"

Student::Student(std::string lname, Array<int> *newSubjects, bool onContract)
    : lname{lname}, subjects{newSubjects}, onContract{onContract}
{
}

Student::~Student()
{
  delete subjects;
}

void Student::setLname(std::string newLname) { lname = newLname; }

void Student::setSubjects(Array<int> *newSubjects)
{
  if (newSubjects == nullptr || newSubjects->getSize() == 0)
  {
    std::cerr << "Error: empty subjects array provided" << std::endl;
    return;
  }
  delete subjects;
  subjects = newSubjects;
}

void Student::setOnContract(bool newOnContract) { onContract = newOnContract; }

std::string Student::getLname() const { return lname; }

const Array<int> *Student::getSubjects() const
{
  return subjects;
}

bool Student::getOnContract() const { return onContract; }

float Student::getAverageScore() const
{
  float sum{};
  for (size_t i{}; i < subjects->getSize(); ++i)
  {
    sum += (*subjects)[i];
  }
  return sum / subjects->getSize();
}

std::ostream &operator<<(std::ostream &os, const Student &student)
{
  os << student.lname << "," << std::fixed << std::setprecision(3);
  os << student.getAverageScore();
  os << std::defaultfloat;
  return os;
}
