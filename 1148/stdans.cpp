#include <cstdio>
#include <algorithm>
const int maxn = 15;

int main() {
    int n, a[15];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i] = i;
    do {
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        printf("\n");
    } while (std::next_permutation(a+1, a+n+1));
    return 0;
}