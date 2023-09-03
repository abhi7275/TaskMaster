#ifndef ALGO_H
#define ALGO_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>
#include <thread>
#include <sstream>
#include <ctime>
#include <iomanip>
// Define the Task struct
struct Task {
    int id;
    std::string name;
    std::string description;
    std::string category;
    int priority; // Added priority field
    bool completed;
    std::string dueDate;
    // Default constructor
   // Task(int taskId, const std::string& taskName, const std::string& taskDescription, const std::string& taskCategory, bool taskCompleted, const std::string& taskDueDate)
   // : id(taskId), name(taskName), description(taskDescription), category(taskCategory), completed(taskCompleted), dueDate(taskDueDate) {}
   Task() : id(0), name(""), description(""), dueDate(""),priority(0){}
    // Parameterized constructor
    // Task(int _id, const std::string& _name, const std::string& _description, const std::string& _category, int _priority, bool _completed, const std::string& _dueDate)
    //     : id(_id), name(_name), description(_description), category(_category), priority(_priority), completed(_completed), dueDate(_dueDate) {}
};
// Function declarations for functions defined in algo.cpp
void addTask(const Task& task);
void editTask(int taskId, const std::string& newName, const std::string& newDescription);
void listTasks();
std::vector<Task> searchTasks(const std::string& keyword);
void setReminder(int taskId, int minutesBefore);
// You can add more function declarations as needed
#endif // ALGO_H
