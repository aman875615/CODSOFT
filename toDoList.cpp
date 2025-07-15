#include <iostream>
#include <map>
using namespace std;

map<string, bool> taskNames; // To avoid duplicates

// Linked list node for a task
struct Task {
    string title;
    bool done;
    Task* next;
};

// Start and end pointers of the list
Task* head = nullptr;
Task* tail = nullptr;

// Function to add a new task
void addTask(const string& name) {
    if (taskNames[name]) {
        cout << "Task already exists. Try something else.\n";
        return;
    }

    Task* newTask = new Task{name, false, nullptr};

    if (!head) {
        head = tail = newTask;
    } else {
        tail->next = newTask;
        tail = newTask;
    }

    taskNames[name] = true;
    cout << "Task \"" << name << "\" added successfully.\n";
}

// Function to display all tasks
void displayTasks() {
    if (!head) {
        cout << "No tasks found.\n";
        return;
    }

    Task* temp = head;
    int index = 1;

    cout << "\n========= Your Task List =========\n";
    while (temp) {
        cout << index++ << ". " << temp->title 
             << " [" << (temp->done ? "✔ Done" : "Pending") << "]\n";
        temp = temp->next;
    }
    cout << "==================================\n";
}

// Function to mark a task as completed
void markAsDone(int num) {
    if (!head) {
        cout << "Task list is empty.\n";
        return;
    }

    Task* temp = head;
    int count = 1;
    while (temp) {
        if (count == num) {
            temp->done = true;
            cout << "Task \"" << temp->title << "\" marked as done.\n";
            return;
        }
        temp = temp->next;
        count++;
    }

    cout << "Invalid task number.\n";
}

// Function to remove a task
void deleteTask(int num) {
    if (!head) {
        cout << "Nothing to delete.\n";
        return;
    }

    Task* temp = head;
    Task* prev = nullptr;
    int count = 1;

    if (num == 1) {
        taskNames.erase(head->title);
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
        cout << "Task deleted.\n";
        return;
    }

    while (temp && count < num) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (!temp) {
        cout << "No such task.\n";
        return;
    }

    prev->next = temp->next;
    if (temp == tail) tail = prev;

    taskNames.erase(temp->title);
    delete temp;
    cout << "Task deleted.\n";
}

int main() {
    char option;

    cout << "================ TO-DO LIST APP ================\n";

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "Any other key to Exit\n";
        cout << "\nEnter choice: ";
        cin >> option;

        switch(option) {
            case '1': {
                string task;
                cout << "Enter task: ";
                cin.ignore(); getline(cin, task);
                addTask(task);
                break;
            }
            case '2':
                displayTasks();
                break;
            case '3': {
                int n;
                displayTasks();
                cout << "Enter task number to mark as completed: ";
                cin >> n;
                markAsDone(n);
                break;
            }
            case '4': {
                int n;
                displayTasks();
                cout << "Enter task number to delete: ";
                cin >> n;
                deleteTask(n);
                break;
            }
            default:
                cout << "\n Exiting To-Do List. Goodbye!\n";
                return 0;
        }
    } while (true);
}
