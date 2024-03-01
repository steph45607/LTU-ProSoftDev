 #include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>

using namespace std;

vector<int> read_file(string s) {
    fstream content(s);
    vector<int> calorieCount;
    string line;
    int calories = 0;

    while(getline(content,line)) {
        if(line.empty()) {
            calorieCount.push_back(calories);
            calories = 0;
        }
        else {
            calories = calories + stoi(line);
        }
    }
    content.close();
    return calorieCount;
}


int max_calc(vector<int> elf) {
    int maxCalories = 0;

    for (int i = 0; i < elf.size(); i++) {
        if (elf[i] > maxCalories) {
            maxCalories = elf[i];
        }
    }
    return maxCalories;
}

int main() {
    string filename = "input.txt";
    vector<int> calorieCount = read_file(filename);
    int maxc = max_calc(calorieCount);
    
    cout << "Total calories carried by the Elf with the most calories " << maxc << endl;
};