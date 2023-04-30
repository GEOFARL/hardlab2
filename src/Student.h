#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>
#include "Array.h"
#include <iomanip>

class Student
{
  friend std::ostream &operator<<(std::ostream &, const Student &);
  std::string lname;
  Array<int> *subjects;
  bool onContract;

public:
  const static int MAX_SCORE = 105;
  const static int MIN_SCORE = 0;
  Student(std::string, Array<int> *, bool);
  ~Student();

  void setLname(std::string);
  void setSubjects(Array<int> *);
  void setOnContract(bool);

  std::string getLname() const;
  const Array<int> *getSubjects() const;
  bool getOnContract() const;

  float getAverageScore() const;
};

#endif