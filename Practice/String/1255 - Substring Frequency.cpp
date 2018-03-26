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
#define mod1    1000000007
#define mod2    1000000009
using namespace std;

lli H1[1000001];
lli H2[1000001];
lli H3[1000001];
lli H4[1000001];
lli P1[1000001];
lli P2[1000001];

void Make_Hash(string s)
{
    lli N=s.length(),i;

    P1[0]=1;
    P2[0]=1;

    lli B1=33,B2=163;
    rep(i,1,N+1)
    {
        P1[i]=(P1[i-1]*B1)%mod1;
        P2[i]=(P2[i-1]*B2)%mod2;
    }

    rep(i,1,N+1)
    {
        H1[i]=(H1[i-1]*B1+s[i-1]-'a'+1)%mod1;
        H2[i]=(H2[i-1]*B2+s[i-1]-'a'+1)%mod2;
    }
}

void Make_Hash1(string s1)
{
    lli N=s1.length(),i;

    lli B1=33,B2=163;
    rep(i,1,N+1)
    {
        H3[i]=(H3[i-1]*B1+s1[i-1]-'a'+1)%mod1;
        H4[i]=(H4[i-1]*B2+s1[i-1]-'a'+1)%mod2;
    }
}

lli get_Hash1(lli L,lli R)
{
    return (H1[R]-(H1[L-1]*P1[R-L+1])%mod1+mod1)%mod1;
}

lli get_Hash2(lli L,lli R)
{
    return (H2[R]-(H2[L-1]*P2[R-L+1])%mod2+mod2)%mod2;
}

lli get_Hash3(lli L,lli R)
{
    return (H3[R]-(H3[L-1]*P1[R-L+1])%mod1+mod1)%mod1;
}

lli get_Hash4(lli L,lli R)
{
    return (H4[R]-(H4[L-1]*P2[R-L+1])%mod2+mod2)%mod2;
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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        string s,s1;
        cin>>s>>s1;

        Make_Hash(s);
        Make_Hash1(s1);

        /*lli N=s.length(),i;
        rep(i,1,N+1)
        {
            cout<<H3[i];sl;cout<<H4[i];
            nl;
        }*/

        lli N=s.length(),N1=s1.length(),i,cnt=0;
        rep(i,1,N-N1+2)
        {
            if(get_Hash1(i,i+N1-1)==get_Hash3(1,N1) and get_Hash2(i,i+N1-1)==get_Hash4(1,N1))
            {
                cnt++;
            }
        }

        cout<<"Case "<<t++<<": "<<cnt;
        nl;
    }




 return 0;
}
