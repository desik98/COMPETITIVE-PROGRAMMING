/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			 printf("\n")
#define nl			 cout<<'\n'
#define sf(N)        scanf("%lld",&N)
#define pf(N)        printf("%lld",N)
#define sf1(N1,N2)    scanf("%lld %lld",&N1,&N2)
#define pf1(N1,N2)    printf("%lld %lld",N1,N2)
#define sf2(N1,N2,N3) scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf2(N1,N2,N3) printf("%lld %lld %lld",N1,N2,N3)

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
#define Dup     erase(unique(V.begin(),V.end()),V.end())

#define bs      binary_search
#define ub      upper_bound
#define lb      lower_bound

#define ALL(V)  V.begin(),V.end()

#define MX1     100000LL
#define MX2     1000000LL
#define Inf     1000000000000000LL
#define mod		1000000007LL
using namespace std;

lli dp[1<<15][15];
vplli V;

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

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli M,N,i,j,k;
        cin>>M>>N;

        rep(i,0,1<<15)
        {
            rep(j,0,15)
            {
                dp[i][j]=Inf;
            }
        }

        lli posx,posy;

        rep(i,0,M)
        {
            string s;
            cin>>s;

            rep(j,0,N)
            {
                if(s[j] == 'x')
                {
                    posx=i;
                    posy=j;
                }
                elif(s[j] == 'g')
                {
                    V.pb(mp(i,j));
                }
            }
        }

        if(!V.sz())
        {
            cout<<"Case "<<t++<<": "<<0;
            nl;

            continue;
        }

        rep(i,0,Power(2,V.sz()))
        {
            rep(j,0,V.sz())
            {
                if(i&(1<<j))
                {
                    lli x=i&(i-1);

                    if(x == 0)
                    {
                        dp[i][j]=max(abs(V[j].F-posx),abs(V[j].S-posy));
                    }
                    else
                    {
                        rep(k,0,V.sz())
                        {
                            if(i&(1<<k) and (j!=k))
                            {
                                dp[i][j]=min(max(abs(V[j].F-V[k].F),abs(V[j].S-V[k].S))+dp[i^(1<<j)][k],dp[i][j]);
                            }
                        }
                    }
                }
            }
        }

        i--;

        lli Min=Inf;
        rep(j,0,V.sz())
        {
            Min=min(Min,dp[i][j]+max(abs(V[j].F-posx),abs(V[j].S-posy)));
        }

        cout<<"Case "<<t++<<": "<<Min<<'\n';

        V.clear();
    }







 return 0;
}
