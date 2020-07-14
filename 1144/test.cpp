#include <cstdio>
#include <cstring>
#include <vector>
const int maxn = 1005;

int main() {
    int n, a[maxn];
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    while (n--) {
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    int max = -1, num = 10000, prenum = -1;
    for (int i = 1; i < maxn; i++) {
        if (a[i] > max) {
            max = a[i];
            num = i;
        }
    }
    printf("%d", num);
    return 0;
}