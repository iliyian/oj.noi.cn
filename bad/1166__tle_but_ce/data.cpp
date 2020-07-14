#include <cstdio>
#include <cstdlib>
#include <ctime>
const int maxn = 30;
const int rate = 4;

int main() {
    srand(time(NULL));
    int n = rand() % maxn, m = rand() % maxn;
    printf("%d %d\n", n, m);
    int r0, c0, r2, c2;
    do {
        r0 = rand() % n, c0 = rand() % m, r2 = rand() % n, c2 = rand() % m;
    } while (r0 == r2 && c0 == c2);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == r0 && j == c0) printf("%c", 'V');
            else if (i == r2 && j == c2) printf("%c", 'J');
            else if (rand() % rate == 0) printf("%c", '+');
            else printf("%c", '.');
        }
        printf("\n");
    }
    return 0;
}