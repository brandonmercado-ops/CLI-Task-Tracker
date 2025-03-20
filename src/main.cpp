#include "opts.cpp"
#include "tasks/task.hpp"
#include "tasks/task_list.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

ifstream done("json/tasks_done.json");
ifstream ip("json/tasks_ip.json");
ifstream todo("json/tasks_todo.json");
void find_jsons();

int main() {
  char option;
  string empty;
  Task temp;
  TaskList tmp;

  // Open json files if they exist, create them if they do not exist
  find_jsons();

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

    switch (option) {
    case 'Q':
      cout << endl << "Exiting program..." << endl << "Goodbye!" << endl;
      goto end_loop; // Similar to MIPS ASM's branch instruction to label
    case 'A':
      cout << endl << "YOU WANT TO CREATE A TASK" << endl;
      break;
    case 'U':
      cout << endl << "YOU WANT TO UPDATE A TASK" << endl;
      break;
    case 'D':
      cout << endl << "YOU WANT TO DELETE A TASK" << endl;
      break;
    }
  }
/*  Empty label to jump to in order to exit while loop from inside switch
 statement */
end_loop:

  done.close();
  ip.close();
  todo.close();
  return 0;
}

void find_jsons() {
  if (done.is_open() && ip.is_open() && todo.is_open()) {
    cout << "these files exists and are open!" << endl;
  }

  else {
    if (!done.is_open()) {
      system("touch json/done.json");
    }
    if (!ip.is_open()) {
      system("touch json/ip.json");
    }
    if (!todo.is_open()) {
      system("touch json/todo.json");
    }
  }
}
