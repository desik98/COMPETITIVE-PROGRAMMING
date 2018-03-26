#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[10005],sum1[10005];
const int mod=100000007;
int n,k;
int a[105],c[105];
ll f(int x)
{
    if(x<0)return 0;
    return sum1[x];
}
void pr()
{
    for(int i=0;i<=k;++i)sum1[i]=sum[i];
}
int main()
{
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;++i)cin>>a[i];
        for(int i=0;i<n;++i)cin>>c[i];

        for(int i=1;i<=k;++i)
        {
            sum[i]=0;
            sum1[i]=0;
        }

        sum1[0]=1;
        sum[0]=1;
        for(int i=0;i<n;++i){
            for(int j=a[i];j<=k;++j){
                sum[j]=sum1[j]+sum[j-a[i]]-f(j-(a[i]*(c[i]+1)))+mod;
                sum[j]%=mod;
            }
            pr();
        }

        int cnt=0;
        for(int i=1;i<=k;i++)
        {
            if(sum[i])
            {
                //cout<<i<<' '<<sum[i]<<'\n';

                cnt++;
            }
        }

        cout<<"Case "<<tc++<<": "<<cnt<<'\n';
    }

}
