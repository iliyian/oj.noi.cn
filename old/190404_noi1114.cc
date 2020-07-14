#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N, n, target[1001];
    cin >> N;
    while(N--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> target[i];
        int A = 1, B = 1;
        stack<int> s;
        bool ok = true;
        while (B < n) {
            if (A == target[B]) {
                B++;
                A++;
            } else if (!s.empty() && s.top() == target[B]) {
                s.pop();
                B++;
            } else if (B <= n) {
                s.push(B++);
            } else {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Possible\n" : "Impossible\n");
    }
    return 0;
}