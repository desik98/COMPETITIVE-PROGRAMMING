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

vlli V[50001];
bool visited[50001];
lli dp[50001];

void bfs(lli x)
{
    queue<lli>Q;

    visited[x]=1;
    Q.push(x);

    lli i;

    while(!Q.empty())
    {
        x=Q.front();
        Q.pop();

        rep(i,0,V[x].sz())
        {
            if(!visited[V[x][i]])
            {
                visited[V[x][i]]=1;
                Q.push(V[x][i]);

                dp[V[x][i]]=x;
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
    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    cin>>T;

    while(T--)
    {
        lli N,i,j;
        cin>>N;

        vlli V1(N);
        lli maxi=-Inf;
        rep(i,0,N)
        {
            cin>>V1[i];
            maxi=max(maxi,V1[i]);
        }

        cout<<"Case "<<t++<<":";
        nl;

        rep(i,1,N)
        {
            lli x=V1[i];
            lli y=V1[i-1];

            V[x].pb(y);
            V[y].pb(x);
        }

        dp[V1[0]]=0;

        rep(i,1,maxi+1)
        {
            sort(V[i].begin(),V[i].end());
        }

        bfs(V1[0]);

        vlli V2;

        lli x=V1[N-1];
        while(x)
        {
            V2.pb(x);
            x=dp[x];
        }

        reverse(V2.begin(),V2.end());

        rep(i,0,V2.sz())
        {
            cout<<V2[i];

            if(i!=V2.sz()-1)sl;
        }
        nl;

        rep(i,1,maxi+1)
        {
            V[i].clear();
            visited[i]=0;
        }
    }




 return 0;
}
