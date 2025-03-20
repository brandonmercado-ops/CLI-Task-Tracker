#include "task_list.hpp"

TaskList::TaskList(){

  // Ensures list is empty on construction
  if(!list.empty()){
    list.clear();
  }
}

TaskList::~TaskList(){
  list.clear();
}
