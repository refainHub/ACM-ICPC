#include "bits/stdc++.h"
using namespace std;
#define MAXN 1005
int a[MAXN][MAXN];
int sum[MAXN][MAXN];
int n, m, q;
int x, y, xx, yy;
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //初始化
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
        }
    }
    while (q--) {
        scanf("%d%d%d%d", &x, &y, &xx, &yy); //求子矩阵元素和
        printf("%d\n", sum[xx][yy] - sum[xx][y - 1] - sum[x - 1][yy] + sum[x - 1][y - 1]);
    }
    return 0;
}