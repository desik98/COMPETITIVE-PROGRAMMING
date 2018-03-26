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
#define Inf     10000000000000LL
#define mod		1000000007LL
using namespace std;

vlli Lucky_Numbers;
set<lli> Very_Lucky_Numbers;
set<lli> :: itr it;
vlli Very_Lucky_Numbers_vector;
lli Big_Number=1000000010000LL;
lli Count;

void Compute_Very_Lucky(lli idx,lli Number)
{
    if(Number > Big_Number)
    {
        return ;
    }

    if(Number!=1)
    {
        Very_Lucky_Numbers.insert(Number);
    }

    if(idx==Lucky_Numbers.size())
    {
        return ;
    }

    if( Number <= Big_Number / Lucky_Numbers[idx] ) Compute_Very_Lucky(idx,Number*Lucky_Numbers[idx]);
    if( Number <= Big_Number / Lucky_Numbers[idx] ) Compute_Very_Lucky(idx+1,Number);
    if( Number <= Big_Number / Lucky_Numbers[idx] ) Compute_Very_Lucky(idx+1,Number*Lucky_Numbers[idx]);
}

void Precompute()
{
    Lucky_Numbers.pb(4);
    Lucky_Numbers.pb(7);

    lli i=0;

    while(1)
    {
        lli x=Lucky_Numbers[i]*10+4,y=Lucky_Numbers[i]*10+7;

        if(x<=Big_Number)
        {
            Lucky_Numbers.pb(x);
        }
        else
        {
            break;
        }

        if(y<=Big_Number)
        {
            Lucky_Numbers.pb(y);
        }
        else
        {
            break;
        }

        i++;
    }

    Compute_Very_Lucky(0,1);

    for(it=Very_Lucky_Numbers.begin();it!=Very_Lucky_Numbers.end();it++)
    {
        Very_Lucky_Numbers_vector.pb(*it);
    }

    //cout<<Very_Lucky_Numbers.size();
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
    //freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    Precompute();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli a,b;
        cin>>a>>b;

        cout<<"Case "<<t++<<": ";
        cout<<upper_bound(Very_Lucky_Numbers_vector.begin(),Very_Lucky_Numbers_vector.end(),b)-lower_bound(Very_Lucky_Numbers_vector.begin(),Very_Lucky_Numbers_vector.end(),a);
        nl;
    }





 return 0;
}
