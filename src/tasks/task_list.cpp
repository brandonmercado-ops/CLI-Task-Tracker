#include "task_list.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

TaskList::TaskList() {

  // Ensures list is empty on construction
  if (!list.empty()) {
    list.clear();
  }
}

TaskList::~TaskList() { list.clear(); }

// Reading straight from task object
// Plan to read from JSON files in the future
void TaskList::show_tasks() {
  for_each(list.begin(), list.end(), [](Task &x) {
    cout << "ID: " << x.get_id() << endl;
    cout << "DESCRIPTION: " << x.get_desc() << endl;
    cout << "STATUS: " << x.get_status() << endl;
    cout << "CREATED AT: " << x.get_created() << endl;
    cout << "UPDATED AT: " << x.get_updated() << endl;
  });
};
