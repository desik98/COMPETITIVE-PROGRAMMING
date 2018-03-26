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

#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

vector<lli>V[100001];
bool visited[100001];
vlli level(100001);
vlli Value(100001);
lli cnt1,cnt;

void bfs(lli x)
{
    queue<lli>Q,Q1;
    lli i;
    level[x]=1;

    visited[x]=1;
    Q.push(x);

    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();

        Q1.push(x);

        rep(i,0,V[x].sz())
        {
            if(!visited[V[x][i]])
            {
                Q.push(V[x][i]);
                visited[V[x][i]]=1;

                level[V[x][i]]=level[x]+1;
            }
        }
    }

    while(!Q1.empty())
    {
        visited[Q1.front()]=0;
        Q1.pop();
        cnt1++;
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
    cin>>T;

    while(T--)
    {
        lli N,i,M,j;
        cin>>N>>M;

        while(M--)
        {
            lli x,y;
            cin>>x>>y;

            V[x].pb(y);
            V[y].pb(x);
        }

        lli Maximum=0;
        cnt=0;
        rep(i,1,N+1)
        {
            if(!level[i])
            {
                cnt1=0;
                bfs(i);
                cnt=max(cnt,cnt1);

                lli x=max_element(level.begin()+1,level.begin()+N+1)-level.begin();

                cnt1=0;
                bfs(x);

                Maximum=max(*max_element(level.begin()+1,level.begin()+N+1),Maximum);

                rep(j,0,cnt1+1)
                Value[j]=max(Value[j],Maximum);
            }
        }

        /*rep(i,1,N+1)
        {
            cout<<Value[i];sl;
        }
        nl;*/

        lli Q;
        cin>>Q;

        cout<<"Case "<<t++<<":";
        nl;

        while(Q--)
        {
            lli x;
            cin>>x;

            if(!x)
            {
                cout<<0;
                nl;

                continue;
            }

            if(x>cnt)
            {
                cout<<"impossible";
                nl;

                continue;
            }

            if(x<=Value[x])
            {
                cout<<x-1;
            }
            else
            {
                cout<<2*x-Value[x]-1;
            }
            nl;
        }

        rep(i,1,N+1)
        {
            V[i].clear();
            visited[i]=0;
            level[i]=0;
            Value[i]=0;
        }
    }



 return 0;
}
