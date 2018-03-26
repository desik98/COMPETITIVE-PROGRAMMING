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
#define F   	first
#define S		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

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

vlli Prime,Prime1;
lli Max=100;

void Sieves()
{
    lli i,j;

    rep(i,0,Max+1)
    {
        Prime1.pb(i);
    }

    for(i=2;i<=sqrt(Max);i++)
    {
        for(j=2;j<=Max/i;j++)
        {
            Prime1[i*j]=0;
        }
    }

    rep(i,2,Max+1)
    {
        if(Prime1[i])
        {
            Prime.pb(i);
        }
    }
}

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("Intelligent_Factorial_Factorization.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Sieves();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,K,j;
        cin>>N;

        cout<<"Case "<<t++<<": "<<N<<" = ";

        vplli V;

        rep(i,0,Prime.sz())
        {
            lli N1=N,cnt=0;

            while(N1/Prime[i])
            {
                cnt+=N1/Prime[i];
                N1/=Prime[i];
            }

            if(cnt)
            {
                V.pb(mp(Prime[i],cnt));
            }
        }

        rep(i,0,V.sz())
        {
            if(i!=V.sz()-1)
            {
                cout<<V[i].F<<" ("<<V[i].S<<") * ";
            }
            else
            {
                cout<<V[i].F<<" ("<<V[i].S<<')';
            }
        }
        nl;
    }



 return 0;
}
