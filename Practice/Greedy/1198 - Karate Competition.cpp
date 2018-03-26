/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'
#define sf(N)       scanf("%lld",&N)
#define pf(N)       printf("%lld",N)
#define sl          cout<<' '
#define ps          printf(" ")

#define rep(i,a,b)	for(i=a;i<b;i++)
#define repr(i,a,b)	for(i=a;i>b;i--)
#define elif		else if
#define mset(a,b)	memset(a,b,sizeof(a))

#define pb		push_back
#define pob		pop_back
#define itr		iterator
#define sz()	size()
#define szof    sizeof
#define lb		lower_bound
#define ub		upper_bound
#define mp		make_pair
#define vlli    vector<lli>
#define plli	pair<lli,lli>
#define vplli	vector<plli >
#define Frst	first
#define Sec		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vlli V(51);
vlli V1(51);
lli dp[51][51];
lli N;

lli Fun(lli S1,lli S2)
{
    if(S1==N or S2==N)
    {
        return 0;
    }

    if(dp[S1][S2]+1)
    {
        return dp[S1][S2];
    }

    lli Profit=0;
    if(V[S1]>V1[S2])
    {
        Profit=Fun(S1+1,S2+1)+2;
    }
    elif(V[S1]==V1[S2])
    {
        Profit=max(Fun(S1+1,S2),Fun(S1+1,S2+1)+1);
    }
    else
    {
        Profit=Fun(S1+1,S2);
    }

    return(dp[S1][S2]=Profit);
}

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a)%mod;
        }

        b=b>>1;
        a=(a*a)%mod;
    }

 return result;
 }

int main()
{
    opt;

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli i;
        cin>>N;

        rep(i,0,N)
        {
            cin>>V[i];
        }

        rep(i,0,N)
        {
            cin>>V1[i];
        }

        sort(V.begin(),V.begin()+N);
        sort(V1.begin(),V1.begin()+N);

        /*rep(i,0,N)
        {
            cout<<V[i]<<' ';
        }
        nl;

        rep(i,0,N)
        {
            cout<<V1[i]<<' ';
        }
        nl;*/

        memset(dp,-1,szof(dp));

        cout<<"Case "<<t++<<": ";
        cout<<Fun(0,0);
        nl;

        V.clear();
        V1.clear();
    }




 return 0;
}
