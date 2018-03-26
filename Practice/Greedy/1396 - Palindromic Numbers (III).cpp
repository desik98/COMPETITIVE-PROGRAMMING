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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        string s;
        cin>>s;

        cout<<"Case "<<t++<<": ";

        lli N=s.length(),i;

        lli Start;

        Start=N/2-1;

        I flag=0;

        repr(i,Start,-1)
        {
            if(s[i]!=s[N-1-i])
            {
                if(s[i]>s[N-1-i])
                {
                    s[N-1-i]=s[i];
                }
                else
                {
                    s[N-1-i]=++s[i];
                }

                if(!flag)
                {
                    flag=1;
                }
            }
        }

        if(N%2)
        {
            if(!flag)
            {
                s[N/2]++;
            }
            else
            {
                s[N/2]='0';
            }
        }

        cout<<s;
        nl;
    }




 return 0;
}
