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

lli dp1[33][33][33][3][7][2];//dp1[idx][Ones][Diff][Rem1][Rem2][flag]
lli dp2[33][33][33][3][7][2];//dp2[idx][Ones][Diff][Rem1][Rem2][flag]
lli Two_Power[33];

lli Max_One,k;
string s1,s2,s;

void Precompute()
{
    lli i;

    Two_Power[0]=1;
    rep(i,1,33)
    {
        Two_Power[i]=Two_Power[i-1]*2LL;
    }
}

lli Fun1(lli idx,lli Ones,lli Diff,lli Rem1,lli Rem2,lli flag)
{
    if(Ones>Max_One or Diff>k)
    {
        return 0;
    }

    if(idx == s1.length())
    {
        return (!Rem1 and Rem2);
    }

    if(dp1[idx][Ones][Diff][Rem1][Rem2][flag] == -1)
    {
        lli Sum=0;

        if(flag)
        {
            lli i;

            rep(i,0,s1[idx]-'0'+1)
            {
                Sum+=Fun1(idx+1,Ones+i,Diff+(i!=s[idx]),(2*Rem1+i)%3,(2*Rem2+i)%7,(i==s1[idx]-'0'));
            }
        }
        else
        {
            lli i;

            rep(i,0,2)
            {
                Sum+=Fun1(idx+1,Ones+i,Diff+(i!=s[idx]),(2*Rem1+i)%3,(2*Rem2+i)%7,0);
            }
        }

        dp1[idx][Ones][Diff][Rem1][Rem2][flag]=Sum;
    }

    return dp1[idx][Ones][Diff][Rem1][Rem2][flag];
}

lli Fun2(lli idx,lli Ones,lli Diff,lli Rem1,lli Rem2,lli flag)
{
    if(Ones>Max_One or Diff>k)
    {
        return 0;
    }

    if(idx == s2.length())
    {
        return (!Rem1 and Rem2);
    }

    if(dp2[idx][Ones][Diff][Rem1][Rem2][flag] == -1)
    {
        lli Sum=0;

        if(flag)
        {
            lli i;

            rep(i,0,s2[idx]-'0'+1)
            {
                Sum+=Fun2(idx+1,Ones+i,Diff+(i!=s[idx]),(2*Rem1+i)%3,(2*Rem2+i)%7,(i==s2[idx]-'0'));
            }
        }
        else
        {
            lli i;

            rep(i,0,2)
            {
                Sum+=Fun2(idx+1,Ones+i,Diff+(i!=s[idx]),(2*Rem1+i)%3,(2*Rem2+i)%7,0);
            }
        }

        dp2[idx][Ones][Diff][Rem1][Rem2][flag]=Sum;
    }

    return dp2[idx][Ones][Diff][Rem1][Rem2][flag];
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

    Precompute();

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        memset(dp1,-1,szof(dp1));
        memset(dp2,-1,szof(dp2));

        lli a,b,Ideal_Number;
        cin>>a>>b>>Max_One>>Ideal_Number>>k;

        cout<<"Case "<<t++<<": ";

        a--;

        s.clear();
        lli cnt=0;
        while(cnt<s.length())
        {
            s.pb(Ideal_Number%2+'0');
            Ideal_Number/=2;

            cnt++;
        }

        reverse(s.begin(),s.end());

        cout<<s<<' ';

        s1.clear();
        while(b)
        {
            s1.push_back(b%2+'0');
            b/=2;
        }
        reverse(s1.begin(),s1.end());

        cout<<s1<<' ';
//        lli y=Fun1(0,0,0,0,0,1);

        s2.clear();
        while()
        {
            s2.push_back(a%2+'0');
            a/=2;
        }

        lli y;

        if(s2.length())
        {
            reverse(s2.begin(),s2.end());
            cout<<s2<<'\n';
        }
  //      lli x=Fun2(0,0,0,0,0,1);

//        cout<<y-x;
        nl;
    }









 return 0;
}
