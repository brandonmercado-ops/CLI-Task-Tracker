#ifndef TASK_HPP
#define TASK_HPP

#include <string>
using namespace std;

void create_task();

class Task {
private:
  string id;
  string desc;
  string status;
  string createdAt;
  string updatedAt;
};

#endif
