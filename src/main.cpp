#include <iostream>
#include <filesystem>

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
  return 0;
}