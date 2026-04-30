#include "TrainSchedule.h"

void showMenu() {
    cout << "\n========== SCHEDULE MENU ==========" << endl;
    cout << "1. Add new train" << endl;
    cout << "2. View full schedule" << endl;
    cout << "3. Find trains departing AFTER specific time" << endl;
    cout << "4. Search by departure point" << endl;
    cout << "5. Search by destination point" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Your choice: ";
}

void addTrain(multimap<string, Train>& schedule) {
    Train t;
    cout << "\nEnter departure point: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, t.departurePoint);

    cout << "Enter destination point: ";
    getline(cin, t.destinationPoint);

    cout << "Select type (1-Regular, 2-High Comfort, 3-Express): ";
    int ch = getValidInt();
    if (ch == 2) t.type = "High Comfort";
    else if (ch == 3) t.type = "Express";
    else t.type = "Regular";

    cout << "Enter departure time:" << endl;
    t.departureTime = inputTime();

    schedule.insert({ t.departurePoint, t });
    cout << ">> Record successfully added!" << endl;
}

void viewAll(const multimap<string, Train>& schedule) {
    if (schedule.empty()) {
        cout << "\n[!] The schedule is empty." << endl;
        return;
    }
    printHeader();
    for (const auto& pair : schedule) {
        printTrain(pair.second);
    }
}

void findByTime(const multimap<string, Train>& schedule) {
    if (schedule.empty()) return;
    cout << "\nEnter time limit (searching for departures AFTER this time):" << endl;
    int limit = inputTime();
    bool found = false;
    printHeader();
    for (const auto& pair : schedule) {
        if (pair.second.departureTime > limit) {
            printTrain(pair.second);
            found = true;
        }
    }
    if (!found) cout << "[!] No trains found after " << minutesToTimeStr(limit) << endl;
}

void findByDeparture(const multimap<string, Train>& schedule) {
    cout << "\nEnter departure point: ";
    string point;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, point);

    auto range = schedule.equal_range(point);
    if (range.first == range.second) {
        cout << "[!] No trains found departing from '" << point << "'." << endl;
    }
    else {
        printHeader();
        for (auto it = range.first; it != range.second; ++it) {
            printTrain(it->second);
        }
    }
}

void findByDestination(const multimap<string, Train>& schedule) {
    cout << "\nEnter destination point: ";
    string dest;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, dest);

    bool found = false;
    printHeader();
    for (const auto& pair : schedule) {
        if (pair.second.destinationPoint == dest) {
            printTrain(pair.second);
            found = true;
        }
    }
    if (!found) cout << "[!] No trains found going to '" << dest << "'." << endl;
}

// Utility implementation
int getValidInt() {
    int val;
    while (!(cin >> val)) {
        cout << "Error! Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return val;
}

int inputTime() {
    int h, m;
    while (true) {
        cout << "  Hours (0-23): "; h = getValidInt();
        cout << "  Minutes (0-59): "; m = getValidInt();
        if (h >= 0 && h < 24 && m >= 0 && m < 60) break;
        cout << "[!] Invalid time! Please try again." << endl;
    }
    return h * 60 + m;
}

string minutesToTimeStr(int totalMinutes) {
    int h = totalMinutes / 60;
    int m = totalMinutes % 60;
    string hh = (h < 10) ? "0" + to_string(h) : to_string(h);
    string mm = (m < 10) ? "0" + to_string(m) : to_string(m);
    return hh + ":" + mm;
}

void printHeader() {
    cout << "\n" << left << setw(18) << "Departure" << setw(18) << "Destination"
        << setw(18) << "Type" << setw(8) << "Time" << endl;
    cout << string(62, '-') << endl;
}

void printTrain(const Train& t) {
    cout << left << setw(18) << t.departurePoint << setw(18) << t.destinationPoint
        << setw(18) << t.type << setw(8) << minutesToTimeStr(t.departureTime) << endl;
}