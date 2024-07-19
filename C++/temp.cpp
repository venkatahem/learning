#include <iostream>
#include <regex>

using namespace std;

bool isPowerOfTwo(const string &binary) {
  int decimal = stoi(binary, 0, 2);
  return (decimal != 0) && ((decimal & (decimal - 1)) == 0);
}

int main() {
  string binary = "101";
  regex regex("^0*10*$");

  if (regex_match(binary, regex)) {
    bool isPower = isPowerOfTwo(binary);
    cout << (isPower ? "True" : "False") << endl;
  } else {
    cout << "Invalid binary string." << endl;
  }

  return 0;
}