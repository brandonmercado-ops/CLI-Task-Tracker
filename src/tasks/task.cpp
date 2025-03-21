#include "task.hpp"
#include <iostream>
#include <string>

using namespace std;

// STANDALONE FUNCTIONS OUTSIDE OF CLASS
string Task::get_id() { return id; };
string Task::get_desc() { return desc; };
string Task::get_status(){ return status; };
string Task::get_created(){ return createdAt; };
string Task::get_updated(){ return updatedAt; };

void create_task() {

  // Temp vars to store input
  string i_id;
  string i_desc;
  string i_status;
  string i_createdAt;
  string i_updatedAt;
  string cont;
  bool done = false;

  while (!done) {
    system("clear");

    cout << "Enter task id: EX -> take out trash: ";
    getline(cin, i_id);
    cout << "\tYOU INPUT ID: " << i_id << endl;

    cout << "Enter task description: Ex -> 'take kitchen trash out before mom "
            "gets mad: ";
    getline(cin, i_desc);
    cout << "\tYOU INPUT DESC: " << i_desc << endl;

    cout << "Enter task status: EX -> done (or) in progress (or) todo: ";
    getline(cin, i_status);
    cout << "\tYOU INPUT STATUS: " << i_status << endl;

    cout << "Enter date: EX -> 3/21/25: ";
    getline(cin, i_createdAt);
    i_updatedAt = i_createdAt;

    if (i_id.empty() || i_desc.empty() || i_status.empty() ||
        i_createdAt.empty() || i_updatedAt.empty()) {
      cout
          << "Error! Not all properties were properly filled! Please try again."
          << endl
          << "Click enter to continue...";
      getline(cin, cont);
    } else {
      done = true;
      Task toAdd(i_id, i_desc, i_status, i_createdAt, i_updatedAt);
      // At this stage, the task object has been created. All that is left is to
      // write this task into the respective json file (according to the status
      // of the task)
    }
  }

  cout << "Task created! Click enter to continue...";
  getline(cin, cont);
}
