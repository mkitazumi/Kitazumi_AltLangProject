/*
reads cell.csv

*/
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


// Trim whitespace from both ends of a string
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Convert a string to a float
float toFloat(const std::string& str) {
    std::string numStr = "";
    for (char c : str) {
        if (isdigit(c) || c == '.') {
            numStr += c;
        }
    }
    return std::stof(numStr);
}

// Convert a string to an integer
int toInt(const std::string& str) {
    std::string numStr = "";
    for (char c : str) {
        if (isdigit(c)) {
            numStr += c;
        }
    }
    return numStr.empty() ? 0 : std::stoi(numStr);
}

class Cell {
private:
    // Column attributes as strings
    std::string oem;
    std::string model;
    std::string launch_announced;
    std::string launch_status;
    std::string body_dimensions;
    std::string body_weight;
    std::string body_sim;
    std::string display_type;
    std::string display_size;
    std::string display_resolution;
    std::string features_sensors;
    std::string platform_os;

public:
    // Constructor
    Cell() {}

    // Getter and setters for attributes
    std::string getOem() const { return oem; }
    void setOem(const string& newOem) {
        oem = newOem.empty() ? "null" : newOem;
    }

    std::string getModel() const { return model; }
    void setModel(const string& newModel) {
        model = newModel.empty() ? "null" : newModel;
    }

    std::string getLaunchAnnounced() const { return launch_announced; }
    void setLaunchAnnounced(const string& newLaunchAnnounced) {
        int year = toInt(newLaunchAnnounced);
        launch_announced = year == 0 ? "null" : to_string(year);
    }

    std::string getLaunchStatus() const { return launch_status; }
    void setLaunchStatus(const string& newLaunchStatus) {
        static const unordered_set<string> valid = { "Discontinued", "Cancelled", "Available. Released" };
        launch_status = valid.count(newLaunchStatus) > 0 ? newLaunchStatus : "null";
    }

    std::string getBodyDimensions() const { return body_dimensions; }
    void setBodyDimensions(const string& newBodyDimensions) {
        body_dimensions = newBodyDimensions.empty() ? "null" : newBodyDimensions;
    }

    std::string getBodyWeight() const { return body_weight; }
    void setBodyWeight(const string& newBodyWeight) {
        float weight = toFloat(newBodyWeight);
        body_weight = weight == 0 ? "null" : to_string(weight);
    }

    std::string getBodySim() const { return body_sim; }
    void setBodySim(const string& newBodySim) {
        body_sim = (newBodySim.empty() || newBodySim == "No" || newBodySim == "Yes") ? "null" : newBodySim;
    }

    std::string getDisplayType() const { return display_type; }
    void setDisplayType(const string& newDisplayType) {
        display_type = newDisplayType.empty() ? "null" : newDisplayType;
    }

    std::string getDisplaySize() const { return display_size; }
    void setDisplaySize(const string& newDisplaySize) {
        float size = toFloat(newDisplaySize);
        display_size = size == 0 ? "null" : to_string(size);
    }

    std::string getDisplayResolution() const { return display_resolution; }
    void setDisplayResolution(const string& newDisplayResolution) {
        display_resolution = newDisplayResolution.empty() ? "null" : newDisplayResolution;
    }

    std::string getFeaturesSensors() const { return features_sensors; }
    void setFeaturesSensors(const string& newFeaturesSensors) {
        features_sensors = newFeaturesSensors.empty() ? "null" : newFeaturesSensors;
    }

    std::string getPlatformOS() const { return platform_os; }
    void setPlatformOS(const string& newPlatformOS) {
        platform_os = newPlatformOS.empty() ? "null" : newPlatformOS;
    }

        
};

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


/*
gen c++
https://www.w3schools.com/cpp/cpp_access_specifiers.asp

reading file
https://www.w3schools.com/cpp/cpp_files.asp
*/
