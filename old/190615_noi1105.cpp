#include <cstdio>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int n, m, s[5005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &m);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a) {
            for (int i = 0; i < n; i++) {
                if (s[i] != b) {
                    printf("%d ", s[i]);
                }
            }
            printf("\n");
        } else {
            int i;
            for (i = 0; i < n; i++) {
                if (s[i] == b) {
                    break;
                }
            }
            int t = s[i];
            for (int j = i + 1; j < n; j++) {
                s[j - 1] = s[j];
            }
            s[n - 1] = t;
        }
    }
    return 0;
}