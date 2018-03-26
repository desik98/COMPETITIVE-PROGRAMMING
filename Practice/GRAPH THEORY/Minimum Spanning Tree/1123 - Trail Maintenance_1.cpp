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
#define Inf     1000000000000000LL
#define mod		1000000007LL
using namespace std;

vector<pair<lli,plli> >V;
lli N;
vlli id;
vlli Size;
vlli Graph[201];
bool visited[201];

void Initialize()
{
    id.clear();
    Size.clear();

	lli i;

    id.pb(0);
    Size.pb(1);

	rep(i,1,N+1)
	{
		id.pb(i);
		Size.pb(1);
	}
}

lli root(lli x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}

 return x;
}

void Union(lli x,lli y)
{
	lli p=root(x);
	lli q=root(y);

	if(Size[p]>=Size[q])
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
	lli Minimum_Cost=0,unused=Inf;
	lli i;

	rep(i,0,V.sz())
	{
		lli x=V[i].S.F;
		lli y=V[i].S.S;
		lli w=V[i].F;

		if(root(x)!=root(y))
		{
			Union(x,y);

			Minimum_Cost+=w;
		}
		else
        {
            unused=i;
        }
	}

	vector<pair<lli,plli> > V1;

	rep(i,0,V.sz())
	{
	    if(unused == i)
        {
            continue;
        }

        V1.push_back(mp(V[i].F,mp(V[i].S.F,V[i].S.S)));
	}

	V.clear();

	rep(i,0,V1.sz())
	{
	    V.pb(mp(V1[i].F,mp(V1[i].S.F,V1[i].S.S)));
	}

 return Minimum_Cost;
}

void dfs(lli x)
{
    visited[x]=1;

    lli i;
    rep(i,0,Graph[x].sz())
    {
        if(!visited[Graph[x][i]])
        {
            dfs(Graph[x][i]);
        }
    }
}

int main()
{
	lli T,t=1;
	sf(T);

	while(T--)
	{
        lli M,i,j;
        sf1(N,M);

        lli Connected_Components=0;

        printf("Case %lld:\n",t++);

        while(M--)
        {
            Initialize();

            lli x,y,w;
            sf2(x,y,w);

            if(Connected_Components != 1)
            {
                Graph[x].pb(y);
                Graph[y].pb(x);

                Connected_Components=0;

                memset(visited,0,szof(visited));

                rep(i,1,N+1)
                {
                    if(!visited[i])
                    {
                        dfs(i);
                        Connected_Components++;
                    }
                }
            }

            V.pb(mp(w,mp(x,y)));

            if(Connected_Components == 1)
            {
                sort(V.begin(),V.end());
                pf(Kruskal());
            }
            else
            {
                pf(-1LL);
            }

            pn;
        }

        V.clear();
        rep(i,1,N+1)
        {
            Graph[i].clear();
            visited[i]=0;
        }
	}



 return 0;
}
