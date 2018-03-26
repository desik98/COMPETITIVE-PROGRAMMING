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
#define plli	pair<lli>
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

typedef pair<lli,plli > X;

vector<X > V[10001];
lli dist[10001][2];
lli N,D;

void Dijkstra()
{
    lli i,j;
    priority_queue<X,vector<X>,greater<X> >M;

    rep(i,0,N)
    {
        dist[i][0]=Inf;
        dist[i][1]=0;
    }

    dist[0][0]=0;
    M.push(mp(0,mp(0,0)));

    while(!M.empty())
    {
        X p = M.top();
        M.pop();

        lli  Node=p.S.F,cnt=p.S.S;
        lli Distance=p.F;

        if(cnt > D)
        {
            continue;
        }

        rep(i,0,V[Node].sz())
        {
            lli y=V[Node][i].F,w=V[Node][i].S.F,True=V[Node][i].S.S;

            if(cnt >= dist[y][1])
            {
                if(dist[y][0] > Distance+w)
                {
                    if(True)
                    {
                        if(cnt < D)
                        {
                            dist[y][0]=Distance+w;
                            dist[y][1]=cnt+1;

                            M.push(mp(dist[y][0],mp(y,cnt+1)));
                        }

                        continue;
                    }

                    dist[y][0]=Distance+w;
                    dist[y][1]=cnt;

                    M.push(mp(dist[y][0],mp(y,cnt)));
                }
            }
            else
            {
                if(True)
                {
                    if(dist[y][0] > Distance+w)
                    {
                        dist[y][0]=Distance+w;
                        dist[y][1]=cnt+1;
                    }
                    M.push(mp(Distance+w,mp(y,cnt+1)));

                    continue;

                    if(dist[y][0] == Distance+w and cnt != dist[y][1]-1)
                    {
                        dist[y][0]=Distance+w;
                        dist[y][1]=cnt+1;
                    }
                    M.push(mp(Distance+w,mp(y,cnt+1)));

                    continue;
                }

                if(dist[y][0] >= Distance+w)
                {
                    dist[y][0]=Distance+w;
                    dist[y][1]=cnt;
                }
                M.push(mp(Distance+w,mp(y,cnt)));
            }
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
    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli i,M,K;

        sf(N);
        sf(M);
        sf(K);
        sf(D);

        while(M--)
        {
            lli x,y,w;
            sf(x);
            sf(y);
            sf(w);

            V[x].pb(mp(y,mp(w,0)));
        }

        while(K--)
        {
            lli x,y,w;
            sf(x);
            sf(y);
            sf(w);

            V[x].pb(mp(y,mp(w,1)));
        }

        Dijkstra();

        printf("Case %lld: ",t++);

        if(dist[N-1][0] == Inf)
        {
            printf("Impossible\n");
        }
        else
        {
            pf(dist[N-1][0]);
            pn;
        }

        rep(i,0,N)
        {
            V[i].clear();
        }
    }










 return 0;
}
