#include "cinema.h"

int main() {
    Cinema cinema;
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Reserve seat\n";
        cout << "2. Cancel reservation\n";
        cout << "3. Display seats status\n";
        cout << "4. Display available seats\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int row, col;
                string name;
                cout << "Enter row number: ";
                cin >> row;
                cout << "Enter column number: ";
                cin >> col;
                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, name);
                cinema.reserveSeat(row, col, name);
                break;
            }
            case 2: {
                int row, col;
                cout << "Enter row number of reservation to cancel: ";
                cin >> row;
                cout << "Enter column number of reservation to cancel: ";
                cin >> col;
                cinema.cancelReservation(row, col);
                break;
            }
            case 3:
                cinema.displaySeats();
                break;
            case 4:
                cinema.displayAvailableSeats();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
