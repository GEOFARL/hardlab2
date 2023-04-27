#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <filepath>" << endl;
    return 1;
  }
  cout << argv[1] << endl;
  return 0;
}