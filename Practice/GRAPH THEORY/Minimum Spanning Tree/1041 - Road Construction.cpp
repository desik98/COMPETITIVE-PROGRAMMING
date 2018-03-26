/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		long long
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'

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

vector<pair<lli,pair<lli,lli> > >V;
vector<lli>V1[1001];
vlli id;
vlli Size;
bool visited[10001];
lli N;
map<string,lli>M1;

void initialize()
{
    lli i;

    id.pb(0);
    Size.pb(1);

    rep(i,1,M1.sz()+1)
    {
        id.pb(i);
        Size.pb(1);
    }
}

lli root(lli x)
{
    while(id[x]!=x)
    {
        x=id[id[x]];
    }

 return x;
}

void Union(lli x,lli y)
{
    lli p=root(x);
    lli q=root(y);

    if(Size[p]>Size[q])
    {
        id[q]=p;
        Size[p]+=Size[q];
    }
    else
    {
        id[p]=q;
        Size[q]+=Size[p];
    }
}

lli Kruskal()
{
    lli Cost=0;

    lli i;

    rep(i,0,V.sz())
    {
        lli w=V[i].F;
        lli x=V[i].S.F;
        lli y=V[i].S.S;

        if(root(x)!=root(y))
        {
            Cost+=w;
            Union(x,y);
        }
    }

 return Cost;
}

void dfs(lli x)
{
    visited[x]=1;

    lli i;

    rep(i,0,V1[x].sz())
    {
        if(!visited[V1[x][i]])
        {
            dfs(V1[x][i]);
        }
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

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli M,i;
        cin>>M;

        lli cnt=0;

        while(M--)
        {
            string x,y;
            lli w;
            cin>>x>>y>>w;

            lli cnt1,cnt2;

            if(M1.find(x)==M1.end())
            {
                cnt1=++cnt;
                M1[x]=cnt1;
            }
            else
            {
                cnt1=M1[x];
            }

            if(M1.find(y)==M1.end())
            {
                cnt2=++cnt;
                M1[y]=cnt2;
            }
            else
            {
                cnt2=M1[y];
            }

            V.pb(mp(w,mp(cnt1,cnt2)));

            V1[cnt1].pb(cnt2);
            V1[cnt2].pb(cnt1);
        }

        I flag=1;
        dfs(1);

        rep(i,1,M1.sz()+1)
        {
            if(!visited[i])
            {
                flag=0;
            }
        }

        cout<<"Case "<<t++<<": ";

        if(flag)
        {
            sort(V.begin(),V.end());

            initialize();

            cout<<Kruskal();
        }
        else
            cout<<"Impossible";

        nl;

        V.clear();
        id.clear();
        Size.clear();

        rep(i,1,M1.sz())
        {
            V1[i].clear();
            visited[i]=0;
        }
        M1.clear();
    }






 return 0;
}
