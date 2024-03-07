#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string tournamentWinner(
        vector<vector<string>> competitions, vector<int> results
) {
    // Time: O(n), Space: O(k)
    unordered_map<string, int> standings;
    for (int i = 0; i < competitions.size(); i++) {
        auto competition = competitions[i];
        auto result = !results[i];
        standings[competition[result]] += 3;
    }

    string winner;
    int max_points = INT_MIN;

    for (auto &[team, points]: standings) {
        if (points > max_points) {
            max_points = points;
            winner = team;
        }
    }
    return winner;
}
