#include <iostream>
using namespace std;

int t = 0;
void solve(int p, char from, char buf, char to) {
    if (p == 0) {
        return;
    }
    solve(p - 1, from, to, buf);
    cout << ++t << ".Move " << p << " from " << from << " to " << to << endl;
    solve(p - 1, buf, from, to);
}

int main() {
    int n;
    cin >> n;
    solve(n, 'a', 'b', 'c');
    return 0;
}