#include <iostream>
#include <string>
#include <list>
using namespace std;

class toDoItem {
private:
    int id;
    string mission;
    bool completed;
public:
    toDoItem (): id(0), mission(" "), completed(false) {}
    ~toDoItem() = default;

    bool create(string newMission, int inputId) {
        id = inputId;
        mission = newMission;
        return true;
    }

    int getId() { return id; }
    string getMission() { return mission; }
    bool isCompleted() { return completed;}
    void setCompleted(bool val) {completed = val;}
};

void displayToDoItems(const list<toDoItem>& toDoItems) {
    cout << "To DO List Program :)" << endl << endl;

    for (auto item : toDoItems) {
        string status = item.isCompleted() ? "Done" : "Not Yet";
        cout << item.getId() << " | " << item.getMission() << " | " << status << endl;
    }
    cout << "-------------------------------" << endl;
}

int main() {

    char option;
    int markedId;
    int removedId;
    string inputMission;
    int inputId;

    list<toDoItem> toDoItems;
    toDoItems.clear();

    while (true) {

        displayToDoItems(toDoItems);

        cout << "[a]dd a new task" << endl;
        cout << "[c]omplete a task" << endl;
        cout << "[r]move a task" << endl;
        cout << "[q]uit" << endl;
        cin >> option;
        cin.ignore();

        if (option == 'a') {
            cout << "Write Ur Task's ID :" << endl;
            cin >> inputId;
            cin.ignore();
            cout << "Write Ur New Task: " << endl;
            getline(cin, inputMission);
            toDoItem newItem;
            newItem.create(inputMission, inputId);
            toDoItems.push_back(newItem);
        }

        else if (option == 'q') {
            cout << "Have A Nice Day!";
            break;
        }

        else if (option == 'r') {
            cout << "Please Enter The Id Of The Removed Task: " << endl;
            cin >> removedId;
            cin.ignore();
            for (auto it = toDoItems.begin(); it != toDoItems.end(); ++it) {
                if (removedId == it->getId()) {
                    toDoItems.erase(it);
                    break;
                }
            }
        }

        else if (option == 'c') {
            cout << "Please Enter The Id Of The Completed Task: " << endl;
            cin >> markedId;
            cin.ignore();
            for (auto& item : toDoItems) {
                if (markedId == item.getId()) {
                    item.setCompleted(true);
                    break;
                }
            }
        }
    }

    return 0;
}