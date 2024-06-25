// ����������Ҫ�� N ���㶼����һ�飬������Ž��ȻҪ���� N-1 �����֣��ߣ���ÿ
// �����֣������پ���һ�Ρ����Ž�Ҳ��ྭ�� N-1 �����֣��ߣ���Ϊ���� N-1 ��
// ���֣���ʱ���Ѿ��� N ���㶼��������һ�顣�������ö�������߲��ߣ�֮��
// �յ��Ȼ�������ߵ������˵�֮һ�� ������㵽�����˵�ľ���ֱ��� S1�� S2��
// �� �� �� �� �� �� �� �� �� �� S1+S2+min(S1,S2). �� �� �� �� �� �� �� �� �� ��
// min{S1+S2+min(S1,S2)}.�ܵĸ��Ӷ�Ϊ N^2�� 
#include <cstdio>
#define inf 100000000
int map[1050][1050];
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int i,j,k;
    int e[10000];
    int n;
    int t;
    scanf("%d",&t);
    int num=0;
    while (t--)
    {
        num++;
        scanf("%d",&n);
        int total=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",e+i);
            map[i][i]=0;
            total+=e[i];
        }
        for (j=0;j<n;j++)
        {
            for (i=j+1;i<n;i++)
            {
                map[j][i]=map[j][i-1]+e[i-1];
                map[i][j]=total-map[j][i];
            }
        }
        printf("Case #%d:",num);
         for (i=0;i<n;i++)
         {
             int ans=inf;
             for (j=0;j<n;j++)
             {
                 ans=min(ans,map[i][j]+map[(j+1)%n][i]+min(map[i][j],map[(j+1)%n][i]));
             }
             printf(" %d",ans);
         }
         printf("\n");
    }
}
