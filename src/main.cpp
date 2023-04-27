#include <iostream>
#include <filesystem>
#include "utils.h"
#include "Student.h"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <filepath>" << endl;
    return 1;
  }
  fs::path path{argv[1]};
  if (!fs::exists(path))
  {
    cerr << "The filepath " << fs::absolute(path).string() << " is not valid" << endl;
    return 1;
  }
  if (fs::status(path).type() != fs::file_type::directory)
  {
    cerr << "The filepath " << fs::absolute(path).string() << " you provided is not a directory" << endl;
    return 1;
  }
  if (fs::is_empty(path))
  {
    cerr << "The directory is empty" << endl;
    return 1;
  }

  try
  {
    auto result = readData(path);
    cout << result.first;
    cout << result.second << endl;
  }
  catch (const exception &e)
  {
    cerr << e.what() << endl;
    return 1;
  }

  Student s1{};
  cout << s1 << endl;
  cout << s1.getAverageScore() << endl;

  int subjects[] = {1, 2, 4, 5, 6};
  Student s2{
      "Hello",
      subjects,
      true};
  cout << s2 << endl;
  cout << s2.getAverageScore() << endl;
  return 0;
}