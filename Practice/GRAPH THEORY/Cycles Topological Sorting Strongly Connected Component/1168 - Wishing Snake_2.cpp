/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		int
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
#define F   	first
#define S		second
#define Dup     erase(unique(V.begin(),V.end()),V.end())

#define Inf     100000000000
#define mod		1000000007
using namespace std;

vlli V[2001];
vlli V1[2001];
vlli V2[2001];
vlli V3;
vlli V4[2001];
vlli V5[2001];
vlli postorder(2001);
bool visited[2001];
bool visited1[2001];
bool visited2[2001];
lli cnt,Time;
priority_queue<plli >Q;
lli a[2001][2001];

void dfs1(lli x)
{
    visited1[x]=1;

    lli i;

    rep(i,0,V1[x].sz())
    {
        if(!visited1[V1[x][i]])
        {
            dfs1(V1[x][i]);
        }
    }

 postorder[x]=Time++;
}

void dfs(lli x)
{
    visited[x]=1;

    lli i;

    rep(i,0,V[x].sz())
    {
        if(!visited[V[x][i]])
        {
            dfs(V[x][i]);
        }
    }

    V3.pb(x);
}

int main()
{
    opt;

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,j,k,l;
        cin>>N;

        lli Sum=0;
        rep(i,0,N)
        {
            lli K;
            cin>>K;

            Sum+=K;

            while(K--)
            {
                lli x,y;
                cin>>x>>y;

                visited2[x]=1;
                visited2[y]=1;

                a[x][y]=1;

                V[x].pb(y);
                V1[y].pb(x);
            }
        }

        cout<<"Case "<<t++<<": ";

        if(!Sum)
        {
            cout<<"YES";
            nl;

            continue;
        }

        if(!visited2[0])
        {
            cout<<"NO";
            nl;

            continue;
        }

        rep(i,0,2001)
        {
            if(visited2[i] and !visited1[i])
            {
                dfs1(i);
            }
        }

        rep(i,0,2001)
        {
            if(visited2[i])
            {
                Q.push(mp(postorder[i],i));
            }
        }

        while(!Q.empty())
        {
            lli x=Q.top().F;
            lli y=Q.top().S;

            if(!visited[y])
            {
                dfs(y);

                cnt++;
                rep(i,0,V3.sz())
                {
                    V2[cnt].pb(V3[i]);
                }
                V3.clear();
            }

            Q.pop();
        }

        rep(i,1,cnt+1)
        {
            rep(j,1,cnt+1)
            {
                if(i!=j)
                {
                    rep(k,0,V2[i].sz())
                    {
                        rep(l,0,V2[j].sz())
                        {
                            if(a[V2[i][k]][V2[j][l]])
                            {
                                V4[i].pb(j);
                                V5[j].pb(i);
                            }
                        }
                    }
                }
            }
        }

        I flag=1;
        rep(i,1,cnt+1)
        {
            if(V4[i].sz()>1 or V5[i].sz()>1)
            {
                flag=0;
            }
        }

        if(flag)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
        nl;

        rep(i,0,2001)
        {
            V[i].clear();
            V1[i].clear();
            V2[i].clear();
            V4[i].clear();
            V5[i].clear();
            visited1[i]=0;
            visited2[i]=0;
            visited[i]=0;
        }

        rep(i,0,2001)
        {
            rep(j,0,2001)
            {
                a[i][j]=0;
            }
        }

        cnt=0;
    }




 return 0;
}
