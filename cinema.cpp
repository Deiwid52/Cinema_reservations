#include "cinema.h"

Cinema::Cinema() {
    seats.resize(NUM_ROWS, vector<Seat>(NUM_COLS));
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            seats[i][j].reserved = false;
        }
    }
}

bool Cinema::reserveSeat(int row, int col, const string& customerName) {
    if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
        if (!seats[row - 1][col - 1].reserved) {
            seats[row - 1][col - 1].reserved = true;
            seats[row - 1][col - 1].customerName = customerName;
            cout << "Seat reserved successfully.\n";
            saveReservationsToFile();
            return true;
        } else {
            cout << "This seat is already reserved.\n";
            return false;
        }
    } else {
        cout << "Invalid seat.\n";
        return false;
    }
}

bool Cinema::cancelReservation(int row, int col) {
    if (row >= 1 && row <= NUM_ROWS && col >= 1 && col <= NUM_COLS) {
        if (seats[row - 1][col - 1].reserved) {
            seats[row - 1][col - 1].reserved = false;
            seats[row - 1][col - 1].customerName = "";
            cout << "Reservation canceled successfully.\n";
            saveReservationsToFile();
            return true;
        } else {
            cout << "This seat is not reserved.\n";
            return false;
        }
    } else {
        cout << "Invalid seat.\n";
        return false;
    }
}

void Cinema::displaySeats() {
    cout << "Seats status in the cinema:\n";
    cout << "   ";
    for (int j = 1; j <= NUM_COLS; ++j) {
        cout << setw(3) << j;
    }
    cout << "\n";
    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << setw(3) << i + 1;
        for (int j = 0; j < NUM_COLS; ++j) {
            if (seats[i][j].reserved) {
                cout << setw(3) << "X";
            } else {
                cout << setw(3) << ".";
            }
        }
        cout << "\n";
    }
}

void Cinema::displayAvailableSeats() {
    cout << "Available seats in the cinema:\n";
    cout << "   ";
    for (int j = 1; j <= NUM_COLS; ++j) {
        cout << setw(3) << j;
    }
    cout << "\n";
    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << setw(3) << i + 1;
        for (int j = 0; j < NUM_COLS; ++j) {
            if (!seats[i][j].reserved) {
                cout << setw(3) << ".";
            } else {
                cout << setw(3) << " ";
            }
        }
        cout << "\n";
    }
}

void Cinema::saveReservationsToFile() {
    ofstream file("reservations.txt");
    if (file.is_open()) {
        for (int i = 0; i < NUM_ROWS; ++i) {
            for (int j = 0; j < NUM_COLS; ++j) {
                if (seats[i][j].reserved) {
                    file << seats[i][j].customerName << " " << i + 1 << endl;
                }
            }
        }
        file.close();
        cout << "Reservations saved to file.\n";
    } else {
        cout << "Unable to open file for writing.\n";
    }
}
