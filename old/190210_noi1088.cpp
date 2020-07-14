#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> s;
    int *v = new int[N];
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        v[i] = x;
    }
    for (int i = 0; i < N; ++i) {
        int x = 0;
        for (set<int>::iterator j = s.begin(); j != s.end(); ++j, ++x) {
            if (*j == v[i]) {
                cout << x + 1 << " ";
                break;
            }
        }
    }
    return 0;
}