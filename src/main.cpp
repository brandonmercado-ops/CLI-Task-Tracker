#include "opts.cpp"
#include "tasks/task.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  char option;
  string empty;

  cout << "-----WELCOME TO YOUR TASKS-----" << endl
       << "    CLICK ENTER TO CONTINUE " << endl;

  // Handles "enter" key to continue
  getline(cin, empty);

  // "Game" loop to keep program going until user quits
  while (true) {
    system("clear");
    print_opts(options);

    // Prompt user for their input and capitalize it
    cout << endl << "What do you want to do?: ";
    cin >> option;
    option = toupper(option);

    // HANDLE USER QUIT OUTSIDE OF SWITCH CASE
    if (option == 'Q') {
      cout << "Exiting program..." << endl << "Goodbye!" << endl;
      break;
    }

    // switch (option) {}
  }
  return 0;
}
