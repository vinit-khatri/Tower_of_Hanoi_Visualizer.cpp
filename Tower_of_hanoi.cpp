#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// Function to print the current state of the towers
void printTowers(const vector<vector<int>>& towers, int num_disks) {
    cout << "\nCurrent State of Towers:\n";
    for (int i = num_disks; i >= 1; --i) {
        for (int j = 0; j < 3; ++j) {
            if (towers[j].size() >= i) {
                cout << " " << towers[j][i - 1] << " ";
            } else {
                cout << " | ";
            }
        }
        cout << "\n";
    }
    cout << " A   B   C\n"; // Tower labels
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, vector<vector<int>>& towers, int source, int target, int auxiliary) {
    if (n == 1) {
        // Move disk from source to target
        towers[target].push_back(towers[source].back());
        towers[source].pop_back();
        printTowers(towers, n);
        this_thread::sleep_for(chrono::milliseconds(500)); // Pause for visual effect
        return;
    }
    towerOfHanoi(n - 1, towers, source, auxiliary, target);
    towers[target].push_back(towers[source].back());
    towers[source].pop_back();
    printTowers(towers, n);
    this_thread::sleep_for(chrono::milliseconds(500)); // Pause for visual effect
    towerOfHanoi(n - 1, towers, auxiliary, target, source);
}

int main() {
    int num_disks;
    cout << "Enter the number of disks: ";
    cin >> num_disks;

    // Initialize towers
    vector<vector<int>> towers(3);
    for (int i = num_disks; i >= 1; --i) {
        towers[0].push_back(i); // Fill the first tower with disks
    }

    printTowers(towers, num_disks);
    towerOfHanoi(num_disks, towers, 0, 2, 1); // Solve the puzzle

    cout << "All disks have been moved to Tower C!" << endl;
    return 0;
}
