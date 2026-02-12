#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Task {
    string name;
    bool completed;
};

vector<Task> tasks;

void welcomeMessage() {
    cout << "Let's organize your day.\n";
}

void showTasks() {
    if (tasks.empty()) {
        cout << "\nYour list is currently empty.\n";
        cout << "You can start by adding a new task.\n";
        return;
    }

    cout << "\nHere are your current tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << (tasks[i].completed ? "[Done] " : "[Pending] ")
             << tasks[i].name << endl;
    }
}

void addTask() {
    string taskName;
    cin.ignore();

    cout << "\nEnter the task you would like to add: ";
    getline(cin, taskName);

    tasks.push_back({taskName, false});

    cout << "Task added successfully.\n";
}

void completeTask() {
    if (tasks.empty()) {
        cout << "\nThere are no tasks to mark as completed.\n";
        return;
    }

    showTasks();

    int choice;
    cout << "\nEnter the number of the task you completed: ";
    cin >> choice;

    if (choice > 0 && choice <= tasks.size()) {
        tasks[choice - 1].completed = true;
        cout << "Great work. The task has been marked as completed.\n";
    } else {
        cout << "Invalid selection. Please try again.\n";
    }
}

void deleteTask() {
    if (tasks.empty()) {
        cout << "\nThere are no tasks to remove.\n";
        return;
    }

    showTasks();

    int choice;
    cout << "\nEnter the number of the task you want to remove: ";
    cin >> choice;

    if (choice > 0 && choice <= tasks.size()) {
        tasks.erase(tasks.begin() + choice - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid selection. Please try again.\n";
    }
}

void showProgress() {
    if (tasks.empty()) {
        cout << "\nNo tasks available to calculate progress.\n";
        return;
    }

    int completed = 0;
    for (auto t : tasks) {
        if (t.completed) completed++;
    }

    double percent = (double)completed / tasks.size() * 100;

    cout << "\nYou have completed "
         << fixed << setprecision(1)
         << percent << "% of your tasks.\n";

    if (percent == 100)
        cout << "All tasks are completed. Excellent work.\n";
    else if (percent >= 50)
        cout << "You are making steady progress. Keep going.\n";
    else
        cout << "Every step counts. Stay consistent.\n";
}

int main() {
    welcomeMessage();

    int option;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add a new task\n";
        cout << "2. View tasks\n";
        cout << "3. Mark a task as completed\n";
        cout << "4. Remove a task\n";
        cout << "5. View progress\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        cin >> option;

        switch (option) {
            case 1: addTask(); break;
            case 2: showTasks(); break;
            case 3: completeTask(); break;
            case 4: deleteTask(); break;
            case 5: showProgress(); break;
            case 0: cout << "\nSession ended. Stay focused and productive.\n"; break;
            default: cout << "Invalid option. Please try again.\n";
        }

    } while (option != 0);

    return 0;
}