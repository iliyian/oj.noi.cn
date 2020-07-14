#include <cstdio>
int beats[100000];

int main() {
    int n, q, idx = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            beats[idx + j] = i;
        }
        idx += x;
    }
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", beats[x]);
    }
    return 0;
}