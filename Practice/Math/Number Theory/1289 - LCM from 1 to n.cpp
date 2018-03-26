/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli    unsigned int

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
#define mod		4294967296LL
using namespace std;

#define Size 100000100
long long isprime[Size / 64 + 100];
ulli Prime[5761558];
ulli Prefix[5761558];
lli cnt;

ulli Power(ulli a,ulli b)
{
    ulli result=1;

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

void Sieves()
{
    lli z=sqrt(Size);

	for (long long i = 3; i <= sqrt(Size); i += 2) {
		if(!(isprime[i/64]&(1LL<<(i%64)))) {
			for(long long j = i * i; j <= Size; j += 2 * i) {
				isprime[j/64] |= (1LL<<(j%64));
			}
		}
	}

	Prime[cnt]=2;
	Prefix[cnt]=2;
	cnt++;

	for (long long i = 3; i <= Size; i += 2) {
		if(!(isprime[i / 64] & (1LL << (i % 64)))) {
			Prime[cnt]=i;
            Prefix[cnt]=Prefix[cnt-1]*Prime[cnt];

            cnt++;
		}
	}
}

int main()
{
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Sieves();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        ulli N,i;
        cin>>N;

        cout<<"Case "<<t++<<": ";

        if(N<=2)
        {
            cout<<N;
            nl;

            continue;
        }
        elif(N==3)
        {
            cout<<6;
            nl;

            continue;
        }
        elif(N==4)
        {
            cout<<12;
            nl;

            continue;
        }

        ulli z=sqrt(N),Sum=1LL;

        i=0;
        while(Prime[i]<=z)
        {
            ulli x=N;

            ulli a=0;

            while(x>=Prime[i])
            {
                x/=Prime[i];
                a++;
            }

            //cout<<a<<' ';

            Sum=(Sum*Power(Prime[i],a-1))%mod;
            i++;
        }

        ulli x=upper_bound(Prime,Prime+cnt,N)-Prime-1;

        Sum*=Prefix[x];

        cout<<Sum;
        nl;
    }





 return 0;
}
