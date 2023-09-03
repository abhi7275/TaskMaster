#include "algo.h"
// Define the Task struct with Task Reminders and Task Recurrence fields
std::vector<Task> tasks;  // Vector to store tasks
// Define a custom comparator for sorting tasks by priority
struct PriorityComparator {
    bool operator()(const Task& task1, const Task& task2) const {
        return task1.priority < task2.priority;
    }
};
// Function to add a new task
void addTask(const Task& task) {
    tasks.push_back(task);
    std::cout << "Task added successfully." << std::endl;
}
// Function to edit task details by task ID
void editTask(int taskId, const std::string& newName, const std::string& newDescription) {
    for (auto& task : tasks) {
        if (task.id == taskId) {
            task.name = newName;
            task.description = newDescription;
            std::cout << "Task details updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Task with ID " << taskId << " not found." << std::endl;
}
// Function to list all tasks
void listTasks() {
    std::cout << "Task List:" << std::endl;
    for (const auto& task : tasks) {
        std::cout << "ID: " << task.id << ", Name: " << task.name << ", Description: " << task.description << std::endl;
    }
}
// Function to search tasks based on a keyword
std::vector<Task> searchTasks(const std::string& keyword) {
    std::vector<Task> matchingTasks;
    for (const auto& task : tasks) {
        if (task.name.find(keyword) != std::string::npos ||
            task.description.find(keyword) != std::string::npos ||
            task.category.find(keyword) != std::string::npos) {
            matchingTasks.push_back(task);
        }
    }
    return matchingTasks;
}

// Function to parse a date string into a std::chrono::system_clock::time_point
std::tm parseDate(const std::string& dateStr) {
    std::tm timeInfo = {};
    std::istringstream dateStream(dateStr);
    // Define the expected date format, e.g., "YYYY-MM-DD"
    dateStream >> std::get_time(&timeInfo, "%Y-%m-%d");
    if (dateStream.fail()) {
        // Parsing failed, handle the error
        throw std::runtime_error("Error parsing date string: " + dateStr);
    }
    return timeInfo;
}

// Function to set a reminder for a task

void setReminder(int taskId, int minutesBefore) {
    // Find the task with the given taskId
    Task* task = nullptr;
    for (auto& t : tasks) {
        if (t.id == taskId) {
            task = &t;
            break;
        }
    }
    if (task == nullptr) {
        std::cout << "Task with ID " << taskId << " not found." << std::endl;
        return;
    }
    // Parse the due date string to extract year, month, and day
    std::tm dueDateStruct = parseDate(task->dueDate);
    // Calculate the time when the reminder will trigger
    std::chrono::system_clock::time_point reminderTime = std::chrono::system_clock::from_time_t(std::mktime(&dueDateStruct));
    reminderTime -= std::chrono::minutes(minutesBefore);
    // Current time
    std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
    // Calculate the duration until the reminder
    std::chrono::duration<int, std::chrono::minutes::period> durationUntilReminder = std::chrono::duration_cast<std::chrono::minutes>(reminderTime - currentTime);
    if (durationUntilReminder.count() <= 0) {
        std::cout << "Reminder time has already passed." << std::endl;
        return;
    }
    // Sleep until the reminder time
    std::this_thread::sleep_for(durationUntilReminder);
    // Display the reminder
    std::cout << "Reminder: Task '" << task->name << "' is due in " << minutesBefore << " minutes." << std::endl;
}
