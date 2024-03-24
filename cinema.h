#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;

struct Seat {
    bool reserved;
    string customerName;
};

class Cinema {
private:
    vector<vector<Seat>> seats;

public:
    Cinema();
    bool reserveSeat(int row, int col, const string& customerName);
    bool cancelReservation(int row, int col);
    void displaySeats();
    void displayAvailableSeats();
    void saveReservationsToFile();
};

#endif // CINEMA_H
