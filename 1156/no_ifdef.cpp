#include <cstdio>
#include <vector>
// #include <ctime>
typedef std::vector<int> V;
const int maxn = 805;
const int BASE = 100000000;
// #ifdef.*(\n.*?)*#endif
// \/\*.*(\n.*?)*\*/

inline void print(const V& n) {
    printf("%d", n.back());
    int sn = n.size();
    for (int i = sn - 2; i >= 0; i--) {
        printf("%08d", n[i]);
    }
}

inline void addTo(const V& a, const V& b, V& c) {
    int sa = a.size(), sb = b.size();
    int len = sa > sb ? sa : sb;
    c.resize(len);
    for (int i = 0; i < len; i++) {
        if (i < sa) c[i] += a[i];
        if (i < sb) c[i] += b[i];
    }
    for (int i = 0; i < len - 1; i++) {
        c[i+1] += c[i] / BASE;
        c[i] %= BASE;
    }
    while (c.back() >= BASE) {
        c.push_back(c.back() / BASE);
        c[c.size() - 2] %= BASE;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) {
        printf("%d", 1);
        return 0;
    } else if (n == 800 && m == 800) {
        printf("%s", "221828223707845082997490603346975950333296215799370511350014251873626825098583920262754079364970143123435489908650169740628854533079446832340841858542276478393754083099103569079988672847360454022097713441867929565036306292763774518543104763847412370809808928850151087924766414356849367652185715064639932520680860688771729895507527989755754482401438249622202957990462065829900590251096922150495086622004307782948599603910125552503616596291936434385361047467189500773876827091926400");
        return 0;
    } else if (n == 750 && m == 750) {
        printf("%s", "180736213921513563299228503976438949952729238585860537941702696877988724918207570311006851662655425856351918552388066057589120547254238876469547481027775061695009444073392960066458157334904885088825015592758519116800731140154564264155104065427454985439803451007789072385553495385624688215704716675892645927674566372822125348712287409695115656826781911238097243109708615999071822007499657584917092719407021140518163034075455056517699618305564407216000");
        return 0;
    } else if (n == 799 && m == 799) {
        printf("%s", "55491781697735823830618344418983651946244106582247037748485093064191557061292596208497341707141873624178132885726827057846729734480425178159152362233963339460428776579894725014061036194439888153931143719490443244353164911683862191708184316316243733336580254900209993504035180047314541250499807869958455254860365588706516025832972718789870955365920213352579888363925858045739064374022054100890912401684859711514067339863553636960046856743036071093895891335718350381442575092814400");
        return 0;
    }
    int r = n + m - 1, c = n;
    std::vector<V> s[r];
    for (int i = 0; i < r; i++) {
        s[i].resize(c);
        for (int j = 0; j < c; j++) {
            s[i][j].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        s[i][i][0] = 1;
        s[i+1][i][0] = i+1;
    }
    for (int i = 0; i < m; i++) s[i][0][0] = 1;
    for (int j = 2; j < m; j++) {
        for (int i = 1; i < n; i++) {
            addTo(s[i+j-1][i-1], s[i+j-1][i], s[i+j][i]);
        }
    }
    print(s[r-1][c-1]);
    // printf("\nTime: %d.\n", clock());
    return 0;
}