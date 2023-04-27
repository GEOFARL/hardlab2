#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <string>

class Student
{
  friend std::ostream &operator<<(std::ostream &, const Student &);
  std::string lname;
  int subjects[5];
  bool onContract;

public:
  const static int NUM_OF_SUBJECTS = 5;
  const static int MAX_SCORE = 105;
  const static int MIN_SCORE = 0;
  Student();
  Student(std::string, int[], bool);

  void setLname(std::string);
  void setSubjects(int[]);
  void setOnContract(bool);

  std::string getLname() const;
  int *getSubjects() const;
  bool getOnContract() const;

  float getAverageScore() const;
};

#endif