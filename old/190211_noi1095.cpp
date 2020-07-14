#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Thing {
    int id, vi, mi;
};

bool sortValue(const Thing & a, const Thing & b) {
    if (a.vi > b.vi) {
        return true;
    } else if (a.vi == b.vi && a.mi < b.mi) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Thing> things(n);
    int vi, mi;
    for (int i = 0; i < n; ++i) {
        cin >> vi >> mi;
        things[i] = {i + 1, vi, mi};
    }
    sort(things.begin(), things.end(), sortValue);
    for (int i = 0; i < n; ++i) {
        cout << things[i].id << " ";
    }
    return 0;
}