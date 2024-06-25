#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
int n, m, q;
int a[MAXN][MAXN]; //原数组
int sub[MAXN][MAXN]; //差分数组
int pre[MAXN][MAXN]; //差分的前缀和，相当于原数组，存放更新过后的值

void insert(int a1, int b1, int a2, int b2, int val) {
    //某个子矩阵内所有元素加上val
    sub[a1][b1] += val;
    sub[a2 + 1][b1] -= val;
    sub[a1][b2 + 1] -= val;
    sub[a2 + 1][b2 + 1] += val;
}

void solve() {
    int a1, b1, a2, b2, val;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            insert(i, j, i, j, a[i][j]);
        }
    }
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d%d%d%d", &a1, &b1, &a2, &b2, &val);
        insert(a1, b1, a2, b2, val);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + sub[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf(j == m ? "%d\n" : "%d ", pre[i][j]);
        }
    }
}

int main(void) {
    solve();
    return 0;
}