#include "bits/stdc++.h"
using namespace std;
#define MAXN 100005
int n, m, l, r, w;
int a[MAXN]; //原数组
int sub[MAXN]; //差分数组


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        //差分数组初始化
        sub[i] = a[i] - a[i - 1];
    }
    while (m--) {
        //区间更新
        scanf("%d%d%d", &l, &r, &w);
        sub[l] += w, sub[r + 1] -= w;
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += sub[i];
        printf("%d ", sum);
    }
    return 0;
}