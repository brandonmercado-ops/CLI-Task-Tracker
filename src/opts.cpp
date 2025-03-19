// List of options for user input
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> options = {
  {"A", "ADD"},
  {"U", "UPDATE"},
  {"D", "DELETE"},
  {"Q", "QUIT"}
};

void print_opts(vector<vector<string>> &t) {

  auto lam = [](vector<string> &s) {
    cout << s[0] << ": " << s[1] << endl;
  };

  for_each(t.begin(), t.end(), lam);
}
