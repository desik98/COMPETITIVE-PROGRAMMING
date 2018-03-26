#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#define mod 100000007ll
using namespace std;
int main()
{
    int T,n,K,A[52],C[52],dp[10005];
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
        scanf("%d%d",&n,&K);
        for(int i=1;i<=n;i++)scanf("%d",&A[i]);
        memset(dp,0,sizeof(int)*10005);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=K;j>=A[i];j--)
            {
                for(int k=K;k>0;k--)
                if(j-k*A[i]>=0)dp[j]+=dp[j-k*A[i]];
                dp[j]%=mod;
            }
        }
        printf("Case %d: %d\n",cs,dp[K]);
    }
    return 0;
}
