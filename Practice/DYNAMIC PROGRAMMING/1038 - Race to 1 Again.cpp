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

#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

double dp[100001];

void Precompute()
{
    lli i,j;

    lli N=100001;

    dp[1]=0;

    rep(i,2,N+1)
    {
        lli cnt=0;
        double Total=0;

        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j)
            {
                continue;
            }

            Total+=(1+dp[j]);
            cnt++;

            if(j*j!=i)
            {
                Total+=(1+dp[i/j]);
                cnt++;
            }
        }

        Total+=2;

        cnt+=2;

        dp[i]=Total/(1.0*(cnt-1) );
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

int main()
{
    opt;

    #ifndef ONLINE_JUDGE
    freopen("Race_To_1.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Precompute();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N;
        cin>>N;

        cout<<"Case "<<t++<<": ";

        cout<<setprecision(6)<<fixed<<dp[N];
        nl;
    }





 return 0;
}
