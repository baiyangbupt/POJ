#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
  
using namespace std;
typedef __int64 lld;
const int MAX=710;
  
const int INF=1000000001;
const double PI=acos(-1.0);
const double EPS=1.0e-8;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int h[MAX][MAX];
  
bool dig(char x){return x>='0'&&x<='9';}
int getval()
{
    int ret=0,sign=1;
    char c;
    while(!dig(c=getchar())&&c!='-');
    if(c=='-')sign=-1;
    else ret=c-'0';
    while(dig(c=getchar()))ret=ret*10+c-'0';
    return ret*sign;
}
  
int minh[MAX],maxh[MAX];
struct Q
{
    int v,id;
}maxq[MAX],minq[MAX];
int maxf,maxr,minf,minr;
void insmax(int v,int id)
{
    maxr++;
    maxq[maxr].v=v;
    maxq[maxr].id=id;
    while(maxr-1>=maxf&&maxq[maxr].v>=maxq[maxr-1].v)
    {
        maxr--;
        maxq[maxr]=maxq[maxr+1];
    }
}
void insmin(int v,int id)
{
    minr++;
    minq[minr].v=v;
    minq[minr].id=id;
    while(minr-1>=minf&&minq[minr].v<=minq[minr-1].v)
    {
        minr--;
        minq[minr]=minq[minr+1];
    }
}
int querymax(int id)
{
    while(maxf<=maxr)
    {
        if(maxq[maxf].id<id)maxf++;
        else break;
    }
    if(maxf>maxr)return -INF;
    return maxq[maxf].v;
}
int querymin(int id)
{
    while(minf<=minr)
    {
        if(minq[minf].id<id)minf++;
        else break;
    }
    if(minf>minr)return INF;
    return minq[minf].v;
}
int calc(int n,int lim,int cmp,int len)
{
    int i,ret=0,tmp;
    maxf=0;
    maxr=-1;
    minf=0;
    minr=-1;
    int front=0;
    for(i=0;i<n;i++)
    {
        insmax(maxh[i],i);
        insmin(minh[i],i);
        while(front<=i)
        {
            int minv=querymin(front);
            int maxv=querymax(front);
            if(maxv-minv>lim)front++;
            else break;
        }
        if(i-front+1>ret)ret=i-front+1;
        if(n-front<=ret||(n-front)*len<=cmp)break;
    }
    return ret;
}
  
int main()
{
    int n,i,j,m;
    int lim,k;
      
    while(scanf("%d%d%d",&m,&n,&lim)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                h[i][j]=getval();
                //scanf("%d",&h[i][j]);
            }
  
        }
  
        int ans=1;
        for(i=0;i<m;i++)
        {
            j=m-1;
            if(j-i+1>100)
            {
                j=i+100-1;
            }
            if((j-i+1)*n<=ans)break;
            for(j=0;j<n;j++)
            {
                minh[j]=INF;
                maxh[j]=-INF;
            }
            for(j=i;j<m&&j-i+1<=100;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(h[k][j]>maxh[k])maxh[k]=h[k][j];
                    if(h[k][j]<minh[k])minh[k]=h[k][j];
                }
                int tmp=calc(n,lim,ans,j-i+1);
                if(tmp*(j-i+1)>ans)ans=tmp*(j-i+1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
