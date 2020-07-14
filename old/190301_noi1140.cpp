#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a, b, c;
    char ch;
    string A, B;
    cin >> A >> B;
    for (int i = 0; i < A.size(); ++i) {
        a.push_back(A[i] - 48);
    }
    for (int i = 0; i < B.size(); ++i) {
        b.push_back(B[i] - 48);
    }
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    c.assign(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < c.size() - 1; ++i) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c.back() > 9) {
        c.push_back(c.back() / 10);
        c[c.size() - 2] %= 10;
    }
    for (auto i = c.rbegin(); i != c.rend(); ++i) {
        cout << *i;
    }
    return 0;
}