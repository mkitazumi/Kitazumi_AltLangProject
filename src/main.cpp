#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {

    Cell newCell;

    ifstream file("cell.csv");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    vector<Cell> cells;
    while (getline(file, line)) {
        istringstream iss(line);
        string cell;
        Cell newCell;
        int index = 0;
        while (getline(iss, cell, ',')) {
            switch (index) {
                case 0: newCell.setOem(trim(cell)); break;
                case 1: newCell.setModel(trim(cell)); break;
                // Add cases for other attributes
            }
            index++;
        }
        cells.push_back(newCell);
    }

    file.close();

    return 0;
}

