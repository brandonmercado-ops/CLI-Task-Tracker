#include "task_list.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/filereadstream.h"
#include <algorithm>
#include <cstdio>
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
/* void TaskList::show_tasks() {
  for_each(list.begin(), list.end(), [](Task &x) {
    cout << "ID: " << x.get_id() << endl;
    cout << "DESCRIPTION: " << x.get_desc() << endl;
    cout << "STATUS: " << x.get_status() << endl;
    cout << "CREATED AT: " << x.get_created() << endl;
    cout << "UPDATED AT: " << x.get_updated() << endl;
  });
}; */

// Printing existing tasks in order of
// DONE, In Progress, TODO in descending order
void show_tasks() {
  string fp_ip = "/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
                 "src/json/tasks_ip.json";

  string fp_todo = "/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
                   "src/json/tasks_todo.json";

  // Open files
  FILE *f_done =
      fopen("/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
            "src/json/tasks_done.json",
            "r");
  char readBuffer1[65536];
  rapidjson::FileReadStream is1(f_done, readBuffer1, sizeof(readBuffer1));
  rapidjson::Document d_done;
  d_done.ParseStream(is1);

  FILE *f_ip = fopen("/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
                     "src/json/tasks_ip.json",
                     "r");
  char readBuffer2[65536];
  rapidjson::FileReadStream is2(f_ip, readBuffer2, sizeof(readBuffer2));
  rapidjson::Document d_ip;
  d_ip.ParseStream(is2);

  FILE *f_todo =
      fopen("/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
            "src/json/tasks_todo.json",
            "r");
  char readBuffer3[65536];
  rapidjson::FileReadStream is3(f_todo, readBuffer3, sizeof(readBuffer3));
  rapidjson::Document d_todo;
  d_todo.ParseStream(is3);

  // Close files
  fclose(f_done);
  fclose(f_ip);
  fclose(f_todo);

  // Print contents of files
  if (d_done.IsArray()) {

    if (d_done.Empty()) {
      cout << "Empty!" << '\n';
    } else {

      cout << "-------------------- DONE TASKS --------------------" << '\n';
      for (rapidjson::SizeType i = 0; i < d_done.Size(); i++) {
        rapidjson::Value &task = d_done[i];

        if (task.IsObject()) {
          cout << "TASK: " << task["id"].GetString() << '\n';
          cout << "DESC: " << task["desc"].GetString() << '\n';
          cout << "- - - - - - - - - - - - - - - - - - - -" << '\n';
        }
      }
    }
  }

  if (d_ip.IsArray()) {
    if (d_ip.Empty()) {
      cout << "Empty!" << '\n';
    } else {

      cout << "-------------------- IN PROGRESS TASKS --------------------"
           << '\n';
      for (rapidjson::SizeType i = 0; i < d_ip.Size(); i++) {
        rapidjson::Value &task = d_ip[i];

        if (task.IsObject()) {
          cout << "TASK: " << task["id"].GetString() << '\n';
          cout << "DESC: " << task["desc"].GetString() << '\n';
          cout << "- - - - - - - - - - - - - - - - - - - -" << '\n';
        }
      }
    }
  }

  if (d_todo.IsArray()) {
    if (d_todo.Empty()) {
      cout << "Empty!" << '\n';
    } else {

      cout << "-------------------- COMPLETED TASKS --------------------"
           << '\n';
      for (rapidjson::SizeType i = 0; i < d_todo.Size(); i++) {
        rapidjson::Value &task = d_todo[i];

        if (task.IsObject()) {
          cout << "TASK: " << task["id"].GetString() << '\n';
          cout << "DESC: " << task["desc"].GetString() << '\n';
          cout << "- - - - - - - - - - - - - - - - - - - -" << '\n';
        }
      }
    }
  }
  cout << '\n' << '\n' << '\n';
}
