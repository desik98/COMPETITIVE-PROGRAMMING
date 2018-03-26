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

lli Ones[1<<15];

lli Power(lli a,lli b)
{
    lli result=1;

    while(b)
    {
        if(b%2)
        {
            result=(result*a);
        }

        b=b>>1;
        a=(a*a);
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

    lli FACT[20],i,Bits[1<<15];

    FACT[0]=1LL;

    rep(i,1,20)
    {
        FACT[i]=FACT[i-1]*i;
    }

    rep(i,1,1LL<<15)
    {
        Bits[i] = __builtin_popcountll(i);
    }

    lli T,t=1;
    scanf("%lld",&T);

    while(T--)
    {
        lli N,j;
        scanf("%lld",&N);

        rep(i,1,1LL<<N)
        {
            Ones[i]=0;
        }

        lli a[N][N],a1[N][N],a2[N][N];

        rep(i,0,N)
        {
            rep(j,0,N)
            {
                scanf("%lld",&a[i][j]);

                if(a[i][j] == 1)
                {
                    a1[i][j]=1;
                    a2[i][j]=1;
                }
                elif(a[i][j] == 0)
                {
                    a1[i][j]=0;
                    a2[i][j]=1;
                }
                else
                {
                    a1[i][j]=0;
                    a2[i][j]=0;
                }
            }
        }

        // Main Logic Starts Here.

        lli Sum=0;
        Ones[0]=1LL;
        rep(i,1,1LL<<N)
        {
            lli Set_Bits=Bits[i];

            rep(j,0,N)
            {
                if(i & (1<<j))
                {
                    Ones[i] += Ones[i^(1<<j)] * a1[Set_Bits-1][j];
                }
            }
        }

        Sum+=Ones[(1<<N)-1];

        rep(i,1,1LL<<N)
        {
            Ones[i]=0;
        }

        Ones[0]=1LL;
        rep(i,1,1LL<<N)
        {
            lli Set_Bits=Bits[i];

            rep(j,0,N)
            {
                if(i & (1<<j))
                {
                    Ones[i] += Ones[i^(1<<j)] * a2[Set_Bits-1][j];
                }
            }
        }

        Sum+=FACT[N]-Ones[(1<<N)-1];

        printf("Case %lld: %lld\n",t++,Sum);
    }




 return 0;
}
