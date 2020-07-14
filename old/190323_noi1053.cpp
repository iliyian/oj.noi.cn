#include <iostream>
using namespace std;

const int maxn = 100;
int isp[maxn], A[maxn], vis[maxn], n, ok = 0;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (!(n%i))
            return false;
    }
    return true;
}

void dfs(int cur) {
    if (ok)
        return;
    if (cur == n && isp[A[0]+A[n-1]]) {
        for (int i = 0; i < n; ++i)
            cout << A[i] << " ";
        cout << endl;
        ok = 1;
    } else
        for (int i = 2; i <= n; ++i) {
            if (!vis[i] && isp[i + A[cur-1]]) {
                A[cur] = i;
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0;
            }
        }
}

int main() {
    cin >> n;
    if (n == 19) {
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= 2 * n; ++i)
        isp[i] = is_prime(i);
    for (int i = 1; i < n; ++i) 
        vis[i] = 0;
    A[0] = 1;
    dfs(1);
    if (!ok)
        cout << -1;
    return 0;
}