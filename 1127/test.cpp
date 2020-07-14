#include <cstdio>
#include <algorithm>
const int maxn = 100 + 5;
int p[maxn];

int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int max(const int& a, const int& b) {return a > b ? a : b;}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = find(a), y = find(b);
        if (x != y) {
            p[x] = y;
        }
    }
    for (int i = 1; i <= n; i++) p[i] = find(p[i]);
    int cnt = 0, maxp = -300, pre = -1, cntp = 0;
    std::sort(p+1, p+n+1);/* 
    for (int i = 1; i <= n; i++) printf("%d_", p[i]);
    printf("\n"); */
    for (int i = 1; i <= n; i++) {
        if (pre == p[i]) {
            cntp++;
        } else {
            cnt++;
            pre = p[i];
            // printf("Else: maxp: %d, cntp: %d\n", maxp, cntp);
            maxp = max(maxp, cntp);
            cntp = 1;
        }
    }
    maxp = max(maxp, cntp);
    printf("%d %d\n", cnt, maxp);
    return 0;
}