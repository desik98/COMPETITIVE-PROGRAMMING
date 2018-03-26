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
#define Inf     100000000000000000LL
#define mod		1000000007LL
using namespace std;

vplli Graph[1001];
lli dist[1001];
vplli Graph1[1001];
lli dist1[1001];

bool visited[1001],visited1[1001];

bool Change[1001],Change1[1001];

lli N;

void BellManFord()
{
    lli i,j,k;

    rep(i,0,N)
    {
        dist[i]=mod;
        dist1[i]=mod;
    }

    //dist[0]=dist1[0]=0;

    rep(i,1,N+1)
    {
        lli cnt=0;

        rep(j,0,N)
        {
            rep(k,0,Graph[j].sz())
            {
                if(dist[Graph[j][k].F] > dist[j]+Graph[j][k].S)
                {
                    dist[Graph[j][k].F] = dist[j]+Graph[j][k].S;
                    cnt++;

                    if(i == N)
                    {
                        Change[Graph[j][k].F]=1;
                    }
                }
            }
        }

        if(!cnt)
        {
            break;
        }
    }

    rep(i,1,N+1)
    {
        lli cnt=0;

        rep(j,0,N)
        {
            rep(k,0,Graph1[j].sz())
            {
                if(dist1[Graph1[j][k].F] > dist1[j]+Graph1[j][k].S)
                {
                    dist1[Graph1[j][k].F] = dist1[j]+Graph1[j][k].S;
                    cnt++;

                    if(i == N)
                    {
                        Change1[Graph1[j][k].F]=1;
                    }
                }

            }
        }

        if(!cnt)
        {
            break;
        }
    }
}

void Initialize()
{
    lli i;

    rep(i,0,N)
    {
        Graph1[i].clear();
        Graph[i].clear();
        visited1[i]=0;
        visited[i]=0;
        Change1[i]=0;
        Change[i]=0;
    }
}

void dfs(lli x)
{
    visited1[x]=1;

    lli i;
    rep(i,0,Graph1[x].sz())
    {
        if(!visited1[Graph1[x][i].F])
        {
            dfs(Graph1[x][i].F);
        }
    }
}

int main()
{
    opt;

    #ifndef ONLINE_JUDGE
    freopen("Instant.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        cout<<"Case "<<t++<<": ";

        lli i,j,k;
        cin>>N;

        Initialize();

        lli M;
        cin>>M;
//
//        if(t == 36)
//        {
//            cout<<N<<' '<<M<<'\n';
//        }

        while(M--)
        {
            lli x,y,w;
            cin>>x>>y>>w;
//
//            if(t == 36)
//            {
//                cout<<x<<' '<<y<<' '<<w<<'\n';
//            }

            Graph[x].pb(mp(y,w));
            Graph1[y].pb(mp(x,w));
        }

        BellManFord();

//        if(t == 36)
//        {
//            rep(i,0,N){
//                cout<<dist[i]<<" ";
//            }
//            nl;
//            rep(i,0,N){
//                cout<<dist1[i]<<" ";
//            }
//            nl;
//            rep(i,0,N)
//            cout<<Change[i]<<' ';
//            nl;
//
//            rep(i,0,N)
//            cout<<Change1[i]<<' ';
//        }
//        nl;

        rep(i,0,N)
        {
            if(!visited1[i] and Change1[i] and Change[i])
            {
                dfs(i);
            }
        }

        vlli True;
        rep(i,0,N)
        {
            if(visited1[i])
            {
                True.pb(i);
            }
        }

        if(!True.sz())
        {
            cout<<"impossible\n";
            continue;
        }

        rep(i,0,True.sz()-1)
        {
            cout<<True[i]<<' ';
        }
        cout<<True.back();
        nl;
    }







 return 0;
}
