#include <iostream>
using namespace std;

struct N {
    string owner;
    int digit;
};

int main() {
    int n, Q, num;
    cin >> n >> Q;
    N *Ns = new N[n];
    for (int i = 0; i < n; ++i) {
        cin >> num;
        Ns[i].digit = num;
    }

    string name;
    for (int i = 0; i < n; ++i) {
        cin >> name;
        Ns[i].owner = name;
    }

    int L, R;
    for (int i = 0; i < Q; ++i) {
        cin >> name >> L >> R;
        int sum = 0;
        for (int j = L - 1; j <= R - 1; ++j) {
            if (Ns[j].owner == name) {
                sum += Ns[j].digit;
            }
        }
        cout << sum << endl;
    }

    return 0;
}