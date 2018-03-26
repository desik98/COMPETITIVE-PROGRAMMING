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
ulli Fun(lli n,lli r)
{
    ulli num=1,den=1,i;

    rep(i,1,r+1)
    {
        num*=n-i+1;
        den*=i;

        lli gcd=__gcd(num,den);

        num/=gcd;
        den/=gcd;
    }

    return num/den;
}
int main()
{
    opt;

    #ifndef ONLINE_JUDGE
    //freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,x,j,s;
        cin>>N>>x;

        cout<<"Case "<<t++<<": ";

        lli Sum=0;
        ulli Sum1=0,Sum2=0;

        rep(s,x,6*N+1)
        {
            i=0;

            while(i<=N and (s-6*i-1)>0 and (s-6*i)>=N)
            {
                if(i%2)
                {
                    Sum1+=Fun(N,i)*Fun(s-6*i-1,N-1);
                }
                else
                {
                    Sum2+=Fun(N,i)*Fun(s-6*i-1,N-1);
                }

                i++;
            }
        }

        Sum=Sum2-Sum1;

        lli z=Power(6LL,N);
        lli y=__gcd(Sum,z);

        Sum/=y;
        z/=y;

        if(z==1)
        {
            cout<<Sum;
        }
        else
        {
            cout<<Sum<<'/'<<z;
        }

        nl;
    }





 return 0;
}
