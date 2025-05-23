#include "task.hpp"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/filereadstream.h"
#include "../include/rapidjson/filewritestream.h"
// #include "../include/rapidjson/ostreamwrapper.h"
#include "../include/rapidjson/prettywriter.h"
// #include "../include/rapidjson/writer.h"
// #include <filesystem>
// #include <fstream>
#include <iostream>
#include <string>

// namespace fs = std::filesystem;
using namespace std;
using namespace rapidjson;

// STANDALONE FUNCTIONS OUTSIDE OF CLASS
string Task::get_id() { return id; };
string Task::get_desc() { return desc; };
string Task::get_status() { return status; };
string Task::get_created() { return createdAt; };
string Task::get_updated() { return updatedAt; };

void create_task() {

  // Temp vars to store input
  string i_id;
  string i_desc;
  string i_status;
  string i_createdAt;
  string i_updatedAt;
  string cont;
  bool done = false;

  // Run program until user provides all valid inputs to create a task
  while (!done) {
    system("clear");

    // Prompt user for Task ID
    cout << "Enter task id: EX -> take out trash: ";
    getline(cin, i_id);
    cout << "\tYOU INPUT ID: " << i_id << endl;

    // Prompt user for Task Description
    cout << "Enter task description: Ex -> 'take kitchen trash out before mom "
            "gets mad: ";
    getline(cin, i_desc);
    cout << "\tYOU INPUT DESC: " << i_desc << endl;

    // Prompt user for Task Status
    cout << "Enter task status: EX -> done (or) in progress (or) todo: ";
    getline(cin, i_status);
    cout << "\tYOU INPUT STATUS: " << i_status << endl;

    // Prompt user for Task Time Created At
    // When task is first being created, initial updatedAt will be equivalent to
    // createdAt
    cout << "Enter date: EX -> 3/21/25: ";
    getline(cin, i_createdAt);
    i_updatedAt = i_createdAt;

    // Ensuring all inputs were valid. If not, restart from top of loop. If so,
    // writing task to respective json file (according to the status)
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

      // Create JSON Document to write
      Document d;
      d.SetObject();

      // Converting variable strings to rapidjson value objects
      Value idValue(i_id.c_str(), d.GetAllocator());
      Value descValue(i_desc.c_str(), d.GetAllocator());
      Value createdValue(i_createdAt.c_str(), d.GetAllocator());
      Value updatedValue(i_updatedAt.c_str(), d.GetAllocator());

      // Add task properties to document
      // ! These do not work if values are not passed as objects (or string
      // literals in between quotations "")
      d.AddMember("id", idValue, d.GetAllocator());
      d.AddMember("desc", descValue, d.GetAllocator());
      d.AddMember("createdAt", createdValue, d.GetAllocator());
      d.AddMember("updatedAt", updatedValue, d.GetAllocator());

      // Grab filepath for respective json files
      const char *filepath;
      if (i_status == "done" || i_status == "Done" || i_status == "DONE") {
        filepath = "/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
                   "src/json/tasks_done.json";

      } else if (i_status == "in progress" || i_status == "In progress" ||
                 i_status == "In Progress" || i_status == "IN PROGRESS" ||
                 i_status == "ip" || i_status == "IP") {
        filepath = "/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
                   "src/json/tasks_ip.json";

      } else if (i_status == "todo" || i_status == "Todo" ||
                 i_status == "TODO") {
        filepath = "/Users/brandonmercado/Desktop/CODE/C++/CLI-Task-Tracker/"
                   "src/json/tasks_todo.json";
      } else {
        cout << "Incorrect input of status! Click enter to try again..."
             << endl;
        done = false;       // To restart whole loop
        getline(cin, cont); // The name cont can be confusing here but its just
                            // to click enter
      }

      // Open output file respective to i_status
      // r+ means read mode to check if any tasks are already in json file
      FILE *fp = fopen(filepath, "r+");
      Document curr_doc;
      if (fp != nullptr) {
        // Read existing data to curr_doc
        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));
        curr_doc.ParseStream(is);
        fclose(fp);
      }

      // Check if current document is an array and if its not, create one
      if (!curr_doc.IsArray()) {
        curr_doc.SetArray();
      }

      // Add newly created task to the array of tasks
      curr_doc.PushBack(d, curr_doc.GetAllocator());

      // Open file again to write
      fp = fopen(filepath, "w");
      if (fp == nullptr) {
        cout << "FILE DID NOT OPEN CORRECTLY" << endl;
      } else {
        // Write JSON data to the open file
        char writeBuffer[65536];
        FileWriteStream os(fp, writeBuffer, sizeof(writeBuffer));
        PrettyWriter<FileWriteStream> writer(os);

        // Accept writer
        curr_doc.Accept(writer);

        // Close file once written
        fclose(fp);
      }
    }
  }

  cout << "Task created! Click enter to continue...";
  getline(cin, cont);
}
