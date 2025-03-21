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

public:
  Task(string i, string d, string s, string c, string u)
      : id(i), desc(d), status(s), createdAt(c), updatedAt(u) {};
};

#endif
