/*���⣺����һ������ͼ����ȥ��������֮��ʹ��ʣ�����ͨ��֧��ࡣ����������
 *�ⷨ����ö��ɾ��һ���㣺Ȼ��Զ���ɾ��һ������ͼ ���㣬������������
 *      ˫��ͨ������ࡣ
 *   ����ķ�������tarjan�㷨����ͼʱ����˫��ߡ�����һ����u����
 *   ��������ӽڵ�v��low[v]=dfn[u]����u��Ϊ��㡣�жϸ��ɾ��
 *   ����γɶ��ٸ���ͨ��������dfs�Ĺ���low[v]=dfn[u]���ֹ����ٴΡ�
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
using namespace std;
#define eN 10005
#define vN 5005
#define LL long long
int n,m;
struct edge
{
        int u,v,next;
}e[eN];
int head[vN],used[vN],en=0;
void addedge(int x,int y)
{
    e[en].u=x;
    e[en].v=y;
    e[en].next=head[x];
    head[x]=en++;
}
int dfn[vN],low[vN],res[vN],temp;
int ex,num;
int tarjan(int u)
{
    used[u]=1;
    low[u]=dfn[u]=num++;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(v==ex)continue;
        if(!used[v])
        {
            tarjan(v);
            if(low[v]==dfn[u])
            {
                res[u]++;
            }
            low[u]=min(low[u],low[v]);
        }
        else
        {
            low[u]=min(low[u],dfn[v]);
        }

    }
    if(temp<res[u])temp=res[u];
}
int main()
{
    //freopen("data.in","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        fill(head,head+n,-1);
        en=0;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        int ans=0,last=0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            fill(used,used+n,0);
            ans=0;
            for(int i=0;i<n;i++)res[i]=1;
            for(int j=0;j<n;j++)
            {
                ex=i;
                num=1;
                if(j==i||used[j])continue;
                //if(head[j]!=-1)
                    res[j]=0;
                cnt++;
                temp=0;
                tarjan(j);
                if(ans<temp)
                    ans=temp;
            }
            if(last<ans+cnt-1)last=ans+cnt-1;
        }
        printf("%d\n",last);
    }
}
