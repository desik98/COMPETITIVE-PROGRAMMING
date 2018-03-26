/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     long long
#define ulli unsigned long long

#define pn           printf("\n")
#define nl           cout<<'\n'
#define sf(N)        scanf("%lld",&N)
#define pf(N)        printf("%lld",N)
#define sf1(N1,N2)    scanf("%lld %lld",&N1,&N2)
#define pf1(N1,N2)    printf("%lld %lld",N1,N2)
#define sf2(N1,N2,N3) scanf("%lld %lld %lld",&N1,&N2,&N3)
#define pf2(N1,N2,N3) printf("%lld %lld %lld",N1,N2,N3)

#define sl          cout<<' '
#define ps          printf(" ")

#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))

#define pb      push_back
#define pob     pop_back
#define itr     iterator
#define sz()    size()
#define szof    sizeof
#define lb      lower_bound
#define ub      upper_bound
#define mp      make_pair
#define vlli    vector<lli>
#define plli    pair<lli,lli>
#define vplli   vector<plli >
#define F       first
#define S       second
#define Dup     erase(unique(V.begin(),V.end()),V.end())

#define bs      binary_search
#define ub      upper_bound
#define lb      lower_bound

#define ALL(V)  V.begin(),V.end()

#define MX1     100000LL
#define MX2     1000000LL
#define Inf     1000000000000000LL
#define mod     1000000007LL
using namespace std;

bool isprime[MX1+1];
bool isprime_Seg[MX1+1];
vlli Primes_MX1;

void Precompute_Primes_MX1()
{
    lli N=50000,i,j;

    for(i=2*2;i<=N;i+=2)
    {
        isprime[i]=1;
    }

    lli z=sqrt(N);

    for(i=3;i<=z;i+=2)
    {
        if(!isprime[i])
        {
            for(j=i*i;j<=N;j+=i)
            {
                isprime[j]=1;
            }
        }
    }

    Primes_MX1.pb(2);
    for(i=3;i<=N;i+=2)
    {
        if(!isprime[i])
        {
            Primes_MX1.pb(i);
        }
    }
}

lli Seg_Sieves(lli a,lli b)
{
    lli i=0,j;

    lli cnt=0;
    while(i<Primes_MX1.sz() and Primes_MX1[i]*Primes_MX1[i]<=b)
    {
        lli z=Primes_MX1[i];

        if(z >= a)
        {
            cnt++;
        }

        for(j = (a/z)*z ; j <= b; j += z)
        {
            if(j-a >= 0)
            {
                isprime_Seg[j-a] = 0;
            }
        }

        i++;
    }

    for(i = max(a,2LL) ;i <=b;i++)
    {
        if(isprime_Seg[i-a])
        {
            cnt++;
        }
    }

    return cnt;
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

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Precompute_Primes_MX1();

    lli T,t=1;
    sf(T);

    while(T--)
    {
        memset(isprime_Seg,1,szof(isprime_Seg));

        lli a,b;
        sf1(a,b);

        printf("Case %lld: %lld\n",t++,Seg_Sieves(a,b));
    }







  return 0;
}
