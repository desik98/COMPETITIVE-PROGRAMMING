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

lli dp[20][20][2];
string s;

lli PalindromeNumbers(lli index1,lli index2,lli flag)
{
    if(index1 == index2)
    {
        if(flag)
        {
            return s[index1]-'0'+1;
        }
        else
        {
            return 10;
        }
    }

    if(index1 == index2-1)
    {
        if(flag)
        {
            return (min(s[index1],s[index2])-'0'+1);
        }
        else
        {
            return 10;
        }
    }

    //if(dp[index1][index2][flag] == -1)
    //{
        lli Sum=0;

        Sum+=PalindromeNumbers(index1+1,index2,0);

        if(flag)
        {
            lli i;

            rep(i,0,min(s[index1],s[index2])-'0'+1)
            {
                if(i == min(s[index1],s[index2])-'0')
                {
                    Sum+=PalindromeNumbers(index1+1,index2-1,s[index1] == min(s[index1],s[index2]));
                }
                else
                {
                    Sum+=PalindromeNumbers(index1+1,index2-1,0);
                }
            }
        }
        else
        {
            lli i;

            rep(i,0,10)
            {
                Sum+=PalindromeNumbers(index1+1,index2-1,0);
            }
        }

        //dp[index1][index2][flag]=Sum;
    //}

    return Sum;//dp[index1][index2][flag];
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

    lli T;
    cin>>T;

    while(T--)
    {
        lli a,b;
        cin>>a>>b;

        a--;
        s.clear();
        memset(dp,-1,szof(dp));

        lli a1=a;
        while(a1)
        {
            s.pb(a1%10+'0');
            a1/=10;
        }

        lli x;

        if(a)
        {
            reverse(s.begin(),s.end());
            x=PalindromeNumbers(0,s.length()-1,1);
        }
        else
        {
            x=1;
        }

        s.clear();
        memset(dp,-1,szof(dp));

        lli b1=b;
        while(b1)
        {
            s.pb(b1%10+'0');
            b1/=10;
        }

        reverse(s.begin(),s.end());
        //cout<<s<<' ';

        lli y=PalindromeNumbers(0,s.length()-1,1);

        cout<<x<<' '<<y<<' ';
        cout<<y-x;
        nl;
    }





 return 0;
}
