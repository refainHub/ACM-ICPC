#include "bits/stdc++.h"
using namespace std;
#define MAXN 100005
int a[MAXN];
int sum[MAXN];
int n, m, l, r;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    while (m--) {
        scanf("%d%d", &l, &r); //求出[l, r]这段区间的和
        int ans = sum[r] - sum[l - 1];
        printf("%d\n", ans);
    }
    return 0;
}