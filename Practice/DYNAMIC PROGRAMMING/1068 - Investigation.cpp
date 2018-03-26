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

lli dp[21][101][101][2];
lli K;
lli Ten_Power[15];

void Precompute_Powers_Ten()
{
    lli i;

    Ten_Power[0]=1LL;

    rep(i,1,15)
    {
        Ten_Power[i]=Ten_Power[i-1]*10;
    }
}

lli Investigation(lli idx,lli Sum,lli Rem,lli flag,string s)
{
    if(idx == s.length())
    {
        return (Sum%K==0 and !Rem);
    }

    if(dp[idx][Sum][Rem][flag] == -1)
    {
        lli Sum1=0,i;

        if(flag)
        {
            rep(i,0,s[idx]-'0'+1)
            {
                if(i == s[idx]-'0')
                {
                    lli Rem1=(Rem+i*Ten_Power[s.length()-1-idx])%K;
                    Sum1+=Investigation(idx+1,Sum+i,Rem1,1,s);
                }
                else
                {
                    lli Rem1=(Rem+i*Ten_Power[s.length()-1-idx])%K;
                    Sum1+=Investigation(idx+1,Sum+i,Rem1,0,s);
                }
            }
        }
        else
        {
            rep(i,0,10)
            {
                lli Rem1=(Rem+i*Ten_Power[s.length()-1-idx])%K;
                Sum1+=Investigation(idx+1,Sum+i,Rem1,0,s);
            }
        }

        dp[idx][Sum][Rem][flag]=Sum1;
    }

    return dp[idx][Sum][Rem][flag];
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

    Precompute_Powers_Ten();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli A,B;
        cin>>A>>B;

        cin>>K;

        cout<<"Case "<<t++<<": ";

        if(K>100)
        {
            cout<<0;
            nl;

            continue;
        }

        A--;

        string s="";
        lli A1=A;

        while(A1)
        {
            s.push_back(A1%10+'0');
            A1/=10;
        }

        reverse(s.begin(),s.end());

        lli x;
        if(s.length())
        {
            memset(dp,-1,szof(dp));
            x=Investigation(0,0,0,1,s);
        }
        else
        {
            x=1;
        }

        string s1="";
        A1=B;

        while(A1)
        {
            s1.push_back(A1%10+'0');
            A1/=10;
        }
        reverse(s1.begin(),s1.end());

        memset(dp,-1,szof(dp));
        lli y=Investigation(0,0,0,1,s1);

        cout<<y-x;
        nl;
    }











 return 0;
}
