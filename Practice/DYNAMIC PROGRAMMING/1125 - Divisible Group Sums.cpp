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

#define MX1     100000
#define MX2     1000000
#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

lli dp[201][21][11];

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
        lli N,i;
        cin>>N;

        lli Q;
        cin>>Q;

        vlli V(N);
        rep(i,0,N)
        {
            cin>>V[i];
        }

        cout<<"Case "<<t++<<":\n";

        while(Q--)
        {
            lli D,M,j,k;
            cin>>D>>M;

            rep(i,0,N+1)
            {
                rep(j,0,D+1)
                {
                    rep(k,0,M+1)
                    {
                        dp[i][j][k]=0;
                    }
                }
            }

            rep(i,0,N+1)
            {
                dp[i][0][0]=1;
            }

            rep(i,1,N+1)
            {
                lli x=V[i-1]%D;

                rep(j,0,D+1)
                {
                    rep(k,1,M+1)
                    {
                        dp[i][j][k]+=dp[i-1][(j-x+D)%D][k-1];
                        dp[i][j][k]+=dp[i-1][j][k];
                    }
                }
            }

            cout<<dp[N][0][M];
            nl;
        }
    }



 return 0;
}
