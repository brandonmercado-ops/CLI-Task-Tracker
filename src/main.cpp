#include "opts.cpp"
#include "tasks/task.hpp"
#include "tasks/task_list.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

// DECLARATIONS
ifstream done_f("json/tasks_done.json");
ifstream ip_f("json/tasks_ip.json");
ifstream todo_f("json/tasks_todo.json");
void find_jsons();

int main() {
  char option;
  string empty;
  bool done;

  TaskList done_l;
  TaskList ip_l;
  TaskList todo_l;

  // Open json files if they exist, create them if they do not exist
  // from handle_json.cpp
  find_jsons();

  cout << "-----WELCOME TO YOUR TASKS-----" << endl
       << "    CLICK ENTER TO CONTINUE " << endl;

  // Handles "enter" key to continue
  getline(cin, empty);

  // "Game" loop to keep program going until user quits
  while (true) {
    system("clear");
    show_tasks();
    print_opts(options);

    // Prompt user for their input and capitalize it
    cout << endl << "What do you want to do?: ";
    cin >> option;
    option = toupper(option);

    // cin command above messes with getline() functions in create_task()
    // function in case 'A' of option switch below
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option) {
    case 'Q':
      cout << endl << "Exiting program..." << endl << "Goodbye!" << endl;
      done = true;
      break;
    case 'A':
      create_task();
      break;
    case 'U':
      cout << endl << "YOU WANT TO UPDATE A TASK" << endl;
      break;
    case 'D':
      cout << endl << "YOU WANT TO DELETE A TASK" << endl;
      break;
    }

    if (done) {
      break;
    }
  }

  done_f.close();
  ip_f.close();
  todo_f.close();
  return 0;
}

void find_jsons() {
  if (done_f.is_open() && ip_f.is_open() && todo_f.is_open()) {
    cout << "these files exists and are open!" << endl;
  }

  else {
    if (!done_f.is_open()) {
      system("touch json/tasks_done.json");
    }
    if (!ip_f.is_open()) {
      system("touch json/tasks_ip.json");
    }
    if (!todo_f.is_open()) {
      system("touch json/tasks_todo.json");
    }
  }
}
