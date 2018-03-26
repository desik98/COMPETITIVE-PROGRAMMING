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

vlli V[MX1+1];
lli pa[MX1+1];
bool visited[MX1+1];
lli table[MX1+1][k+1];
lli Value[MX1+1];

void dfs(lli x,lli parent)
{
    table[x][0]=parent;
    pa[x]=parent;

    lli i;
    rep(i,0,V[x].sz())
    {
        lli y=V[x][i];

        if(y!=pa[x])
        {
            dfs(y,x);
        }
    }
}

lli query(lli K,lli v)
{
    lli Store=K,i;

    if(Value[table[K][0]]<v)
    {
        return K;
    }

    for(i=16;i>=0;i--)
    {
        if(table[K][i]==-1)
        {
            continue;
        }

        if(Value[table[K][i]]>=v)
        {
            K=table[K][i];
            Store=K;
        }
    }

 return Store;
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
    freopen("double_squares.txt","r",stdin);*/

    freopen("double_squares_out.txt","w",stdout);

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli N,i,Q,j;
        sf1(N,Q);

        rep(i,0,N)
        {
            rep(j,0,k+1)
            {
                table[i][j]=-1;
            }
        }

        Value[0]=1;
        rep(i,1,N)
        {
            lli x,y;
            sf1(x,y);

            V[i].pb(x);
            V[x].pb(i);

            Value[i]=y;
        }

        dfs(0,-1);

        for(j=1;j<=k;j++)
        {
            for(i=0;i<N;i++)
            {
                if(table[i][j-1]!=-1)
                table[i][j]=table[table[i][j-1]][j-1];
            }
        }

        printf("Case %lld:\n",t++);

        while(Q--)
        {
            lli K,v;
            sf1(K,v);

            lli a=query(K,v);

            pf(a);
            pn;
        }

        rep(i,0,N)
        {
            V[i].clear();
        }
    }




 return 0;
}
