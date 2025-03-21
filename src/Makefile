# Makefile

CXX = g++
CXX_FLAGS = -std=c++23 -I./include/rapidjson

all: main
	./main
main: main.cpp tasks/task.cpp tasks/task_list.cpp
	$(CXX) $(CXX_FLAGS) main.cpp tasks/task.cpp tasks/task_list.cpp -o main
clean:
	rm main
