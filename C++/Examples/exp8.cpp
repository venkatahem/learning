#include <iostream>

using namespace std;

int main() {
  int a;
  char ch[20];
  int b[5];
  int i;

  cout << "String: ";
  cin >> ch;

  for (i = 0; i < 5; i++) {
    cout << "Enter number " << i + 1 << " :";
    cin >> b[i];
  }

  cout << endl << "Num: ";
  cin >> a;

  cout << endl << "Num: " << a << "\tString" << ch;

  for (i = 0; i < 5; i++) {
    cout << endl << "Array nums: " << b[i] << endl;
  }

  return 7;
}