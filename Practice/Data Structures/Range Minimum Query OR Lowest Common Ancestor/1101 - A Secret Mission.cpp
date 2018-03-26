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
#define k       16
using namespace std;

vplli V[MX1+1];
vector<pair<lli,plli> > V1;
lli pa[MX1+1];
lli table[MX1+1][k+1];
lli table1[MX1+1][k+1];
lli table2[MX1+1][k+1];
lli depth[MX1+1];
lli N;
vlli id,Size;

lli root(lli x)
{
    while(x!=id[x])
    {
        x=id[id[x]];
    }

 return x;
}

void Kruskal()
{
    lli i;

    rep(i,0,V1.sz())
    {
        lli x=V1[i].S.F,y=V1[i].S.S,w=V1[i].F;

        lli Root_x=root(x);
        lli Root_y=root(y);

        if(Root_x!=Root_y)
        {
            if(Size[Root_x]<=Size[Root_y])
            {
                swap(Root_x,Root_y);
            }

            Size[Root_x]+=Size[Root_y];
            id[Root_y]=Root_x;

            V[x].pb(mp(y,w));
            V[y].pb(mp(x,w));
        }
    }
}

void Precompute()
{
    lli i;

    rep(i,0,N+1)
    {
        id.pb(i);
        Size.pb(1);
    }
}

void dfs(lli x,lli parent,lli dist)
{
    pa[x]=parent;
    table[x][0]=parent;
    depth[x]=dist;

    lli i;
    rep(i,0,V[x].sz())
    {
        lli y=V[x][i].F,w=V[x][i].S;

        if(y!=pa[x])
        {
            table1[y][0]=w;
            table2[y][0]=w;
            dfs(y,x,dist+1);
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

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli i,j,M;
        sf(N);
        sf(M);

        Precompute();

        rep(i,1,N+1)
        {
            rep(j,0,k+1)
            {
                table[i][j]=-1;
                table1[i][j]=Inf;
                table2[i][j]=0;
            }
        }

        while(M--)
        {
            lli x,y,w;
            sf2(x,y,w);

            V1.pb(mp(w,mp(x,y)));
        }

        sort(V1.begin(),V1.end());
        Kruskal();

        dfs(1,-1,0);

        for(j=1;j<=k;j++)
        {
            for(i=1;i<=N;i++)
            {
                if(table[i][j-1]!=-1)
                {
                    table[i][j]=table[table[i][j-1]][j-1];

                    if(table[i][j]==-1)
                    {
                        continue;
                    }

                    table1[i][j]=min(table1[i][j-1],table1[table[i][j-1]][j-1]);
                    table2[i][j]=max(table2[i][j-1],table2[table[i][j-1]][j-1]);
                }
            }
        }

        printf("Case %lld:\n",t++);

        lli Q;
        sf(Q);

        while(Q--)
        {
            lli x,y;
            sf1(x,y);

            if(depth[x]<depth[y])
            {
                swap(x,y);
            }

            lli Min=Inf,Max=0;
            for(i=k;i>=0;i--)
            {
                if(depth[x]-(1<<i)>=depth[y])
                {
                    Min=min(Min,table1[x][i]);
                    Max=max(Max,table2[x][i]);
                    x=table[x][i];
                }
            }

            if(x==y)
            {
                pf(Max);
                pn;
                continue;
            }

            for(i=16;i>=0;i--)
            {
                if(table[x][i]!=table[y][i] and table[x][i]!=-1)
                {
                    Min=min(Min,min(table1[x][i],table1[y][i]));
                    Max=max(Max,max(table2[x][i],table2[y][i]));

                    x=table[x][i];
                    y=table[y][i];
                }
            }

            Min=min(Min,min(table1[x][0],table1[y][0]));
            Max=max(Max,max(table2[x][0],table2[y][0]));

            pf(Max);
            pn;
        }

        rep(i,1,N+1)
        {
            V[i].clear();
        }
        id.clear();
        Size.clear();
        V1.clear();
    }




 return 0;
}
