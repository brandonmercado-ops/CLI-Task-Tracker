# Makefile

all: main
	./main
main: main.cpp tasks/task.cpp tasks/task_list.cpp
	g++ -std=c++23 main.cpp tasks/task.cpp tasks/task_list.cpp -o main
clean:
	rm main
