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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vector<lli>V[20001];
bool visited[20001];
lli instack[20001];
I flag;

void Cycles(lli x)
{
    visited[x]=1;
    instack[x]=1;

    lli i;

    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i]])
        {
            Cycles(V[x][i]);
        }

        if(instack[V[x][i]] && visited[V[x][i]])
        {
            flag=1;
            return ;
        }
    }

    instack[x]=0;
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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli Q,i;
        cin>>Q;

        flag=0;

        map<string,lli>M;

        lli cnt=0;

        while(Q--)
        {
            string s1,s2;
            cin>>s1>>s2;

            lli x,y;

            if(M.find(s1)!=M.end())
            {
                if(M.find(s2)!=M.end())
                {
                    x=M[s1];
                    y=M[s2];
                }
                else
                {
                    x=M[s1];

                    y=++cnt;
                    M[s2]=y;
                }
            }
            else
            {
                if(M.find(s2)!=M.end())
                {
                    x=++cnt;
                    M[s1]=x;

                    y=M[s2];
                }
                else
                {
                    x=++cnt;
                    M[s1]=x;

                    y=++cnt;
                    M[s2]=y;
                }
            }

            V[x].pb(y);
        }

        rep(i,1,M.sz()+1)
        {
            if(!visited[i])
                Cycles(i);
        }

        cout<<"Case "<<t++<<": ";
        if(!flag)
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
        nl;

        rep(i,1,M.sz()+1)
        {
            V[i].clear();
            visited[i]=0;
            instack[i]=0;
        }
    }





 return 0;
}
