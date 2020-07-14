#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Player {
    string name;
    int time;
};

bool sortTime(const Player & a, const Player & b) {
    return a.time < b.time;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<Player> players(N);
    for (int i = 0; i < N; ++i) {
        cin >> players[i].name >> players[i].time;
    }
    sort(players.begin(), players.end(), sortTime);
    cout << players[K - 1].name << endl;
    return 0;
}