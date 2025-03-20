#ifndef TASK_LIST_HPP
#define TASK_LIST_HPP

#include <vector>
#include "task.hpp"

class TaskList{
private:
  vector<Task> list;

public:
  bool search(Task &t);

  // CONSTRUCTOR & DESTRUCTOR
  TaskList();
  ~TaskList();
};

#endif
