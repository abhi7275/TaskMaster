#include <iostream>
#include <string>
#include <vector>
#include "algo.h" // Include the header file for function declarations

int main() {
    std::vector<Task> tasks; // Vector to store tasks

    while (true) {
        std::cout << "TaskMaster - Command Menu" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Edit Task" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. List Tasks" << std::endl;
        std::cout << "5. Search Tasks" << std::endl;
        std::cout << "6. Set Reminder" << std::endl;
        std::cout << "7. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Add Task
                Task task;
                std::cout << "Enter Task ID: ";
                int taskId;
                std::cin >> taskId;
                std::cout << "Enter Task Name: ";
                std::string name;
                std::cin >> name;
                std::cout << "Enter Task Description: ";
                std::string description;
                std::cin >> description;
                std::cout << "Enter Task Category: ";
                std::string category;
                std::cin >> category;
                std::cout << "Enter Task Priority: ";
                int priority;
                std::cin >> priority;
                std::cout << "Enter Task Completion Status (0 for incomplete, 1 for complete): ";
                bool completed;
                std::cin >> completed;
                std::cout << "Enter Task Due Date (YYYY-MM-DD): ";
                std::string dueDate;
                std::cin >> dueDate;

                // Create the task and add it to the vector
                Task task(taskId, name, description, category, priority, completed, dueDate);
                addTask(task);
                break;
            }
            case 2: {
                // Edit Task
                int taskId;
                std::cout << "Enter Task ID to Edit: ";
                std::cin >> taskId;
                std::string newName, newDescription;
                std::cout << "Enter New Task Name: ";
                std::cin >> newName;
                std::cout << "Enter New Task Description: ";
                std::cin >> newDescription;
                editTask(taskId, newName, newDescription);
                break;
            }
            case 3: {
                // Delete Task
                int taskId;
                std::cout << "Enter Task ID to Delete: ";
                std::cin >> taskId;
                deleteTask(taskId);
                break;
            }
            case 4: {
                // List Tasks
                listTasks();
                break;
            }
            case 5: {
                // Search Tasks
                std::string keyword;
                std::cout << "Enter Keyword to Search: ";
                std::cin >> keyword;
                std::vector<Task> matchingTasks = searchTasks(keyword);
                std::cout << "Matching tasks for keyword '" << keyword << "':" << std::endl;
                for (const auto& task : matchingTasks) {
                    std::cout << "ID: " << task.id << ", Name: " << task.name << ", Description: " << task.description << std::endl;
                }
                break;
            }
            case 6: {
                // Set Reminder
                int taskId, minutesBefore;
                std::cout << "Enter Task ID for Reminder: ";
                std::cin >> taskId;
                std::cout << "Enter Minutes Before Reminder: ";
                std::cin >> minutesBefore;
                setReminder(taskId, minutesBefore);
                break;
            }
            case 7: {
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
