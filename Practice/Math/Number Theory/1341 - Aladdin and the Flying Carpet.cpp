/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
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
using namespace std::tr1;

bool isprime[MX2+1];
vlli Primes;
vplli Primes_Exponent;

void Precompute()
{
    lli N=MX2,i,j;

    for(i=3;i<=N;i+=2)
    {
        if(!isprime[i])
        {
            for(j=2*i;j<=N;j+=i)
            {
                isprime[j]=1;
            }
        }
    }

    Primes.pb(2);

    for(i=3;i<=N;i+=2)
    {
        if(!isprime[i])
        {
            Primes.pb(i);
        }
    }
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

void Prime_Factorize(lli Number)
{
    lli i;

    i=0;
    while(i<Primes.sz() and Primes[i]*Primes[i] <= Number)
    {
        if(Number%Primes[i] == 0)
        {
            lli Count=0;
            while(Number%Primes[i] == 0)
            {
                Count++;

                Number/=Primes[i];
            }

            Primes_Exponent.pb(mp(Primes[i],Count));
        }

        i++;
    }

    if(Number != 1)
    {
        Primes_Exponent.pb(mp(Number,1));
    }
}

lli a,b;
lli cnt;
unordered_map<lli,lli>U;

void Get_Divisors(lli idx,lli Number)
{
    if(idx == Primes_Exponent.sz())
    {
        if(Number>=b and !U[Number] and !U[a/Number] and (a/Number)>=b and Number*Number!=a)
        {
            cnt++;
            U[Number]=1;
            U[a/Number]=1;
        }

        return ;
    }

    lli Multiple=1;
    for(int i=0;i<=Primes_Exponent[idx].S;i++)
    {
        Get_Divisors(idx+1,Number*Multiple);
        Multiple=Multiple*Primes_Exponent[idx].F;
    }
}

int main()
{
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Precompute();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        cin>>a>>b;

        cout<<"Case "<<t++<<": ";

        Prime_Factorize(a);

        cnt=0;
        Get_Divisors(0,1);

        cout<<cnt;
        nl;

        Primes_Exponent.clear();
        U.clear();
    }







 return 0;
}
