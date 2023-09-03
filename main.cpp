#include <iostream>
#include <string>
#include <vector>
#include "algo.h" // Include the header file for your algorithm functions

int main() {
    std::vector<Task> tasks; // Vector to store tasks

    while (true) {
        // Display the main menu options
        std::cout << "TaskMaster - Command Menu" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Edit Task" << std::endl;
        std::cout << "3. List Tasks" << std::endl;
        std::cout << "4. Search Tasks" << std::endl;
        std::cout << "5. Set Reminder" << std::endl;
        std::cout << "6. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add Task
                Task task;
                std::cout << "Enter task details:" << std::endl;
                std::cout << "Name: ";
                std::cin.ignore(); // Consume the newline character left in the input buffer
                std::getline(std::cin, task.name);
                std::cout << "Description: ";
                std::getline(std::cin, task.description);
                std::cout << "Due Date (YYYY-MM-DD): ";
                std::cin >> task.dueDate;
                std::cout << "Priority: ";
                std::cin >> task.priority;

                // Call the addTask function to add the task to the vector
                addTask(task);
                break;
            }
            case 2: {
                // Edit Task
                int taskId;
                std::cout << "Enter the task ID to edit: ";
                std::cin >> taskId;
                std::string newName, newDescription;
                std::cout << "Enter new name: ";
                std::cin.ignore();
                std::getline(std::cin, newName);
                std::cout << "Enter new description: ";
                std::getline(std::cin, newDescription);

                // Call the editTask function to edit the task
                editTask(taskId, newName, newDescription);
                break;
            }
            case 3: {
                // List Tasks
                listTasks();
                break;
            }
            case 4: {
                // Search Tasks
                std::string keyword;
                std::cout << "Enter a keyword to search for tasks: ";
                std::cin.ignore();
                std::getline(std::cin, keyword);

                // Call the searchTasks function to search for tasks
                std::vector<Task> matchingTasks = searchTasks(keyword);
                if (matchingTasks.empty()) {
                    std::cout << "No matching tasks found." << std::endl;
                } else {
                    std::cout << "Matching tasks:" << std::endl;
                    for (const Task& task : matchingTasks) {
                        std::cout << "ID: " << task.id << ", Name: " << task.name << ", Description: " << task.description << std::endl;
                    }
                }
                break;
            }
            case 5: {
                // Set Reminder
                int taskId, minutesBefore;
                std::cout << "Enter the task ID for which to set a reminder: ";
                std::cin >> taskId;
                std::cout << "Enter the number of minutes before the due date for the reminder: ";
                std::cin >> minutesBefore;

                // Call the setReminder function to set a reminder for the task
                setReminder(taskId, minutesBefore);
                break;
            }
            case 6: {
                // Quit the program
                std::cout << "Exiting TaskMaster. Goodbye!" << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    return 0;
}
