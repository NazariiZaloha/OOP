#include "TrainSchedule.h"

int main() {
    multimap<string, Train> schedule;
    int choice;

    do {
        showMenu();
        choice = getValidInt();

        switch (choice) {
        case 1: addTrain(schedule); break;
        case 2: viewAll(schedule); break;
        case 3: findByTime(schedule); break;
        case 4: findByDeparture(schedule); break;
        case 5: findByDestination(schedule); break;
        case 0: cout << "Exiting program..." << endl; break;
        default: cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}