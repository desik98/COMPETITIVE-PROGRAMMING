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
#define F   	first
#define S		second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     10000000000
#define mod		1000000007
using namespace std;

char a[20][20];
bool visited[20][20];
lli level[20][20];
lli level1[20][20];
vplli V;

void bfs(lli x,lli y)
{
    visited[x][y]=1;
    level1[x][y]=0;

    lli i;
    queue<plli >Q;

    Q.push(mp(x,y));

    while(!Q.empty())
    {
        plli p=Q.front();

        lli x=p.F,y=p.S;

        Q.pop();

        if(!visited[x+1][y+2] and a[x+1][y+2]!='#')
        {
            visited[x+1][y+2]=1;
            Q.push(mp(x+1,y+2));

            level1[x+1][y+2]=level1[x][y]+1;
        }

        if(!visited[x+1][y-2] and a[x+1][y-2]!='#')
        {
            visited[x+1][y-2]=1;
            Q.push(mp(x+1,y-2));

            level1[x+1][y-2]=level1[x][y]+1;
        }

        if(!visited[x+2][y+1] and a[x+2][y+1]!='#')
        {
            visited[x+2][y+1]=1;
            Q.push(mp(x+2,y+1));

            level1[x+2][y+1]=level1[x][y]+1;
        }

        if(!visited[x+2][y-1] and a[x+2][y-1]!='#')
        {
            visited[x+2][y-1]=1;
            Q.push(mp(x+2,y-1));

            level1[x+2][y-1]=level1[x][y]+1;
        }

        if(!visited[x-1][y+2] and a[x-1][y+2]!='#')
        {
            visited[x-1][y+2]=1;
            Q.push(mp(x-1,y+2));

            level1[x-1][y+2]=level1[x][y]+1;
        }

        if(!visited[x-1][y-2] and a[x-1][y-2]!='#')
        {
            visited[x-1][y-2]=1;
            Q.push(mp(x-1,y-2));

            level1[x-1][y-2]=level1[x][y]+1;
        }

        if(!visited[x-2][y+1] and a[x-2][y+1]!='#')
        {
            visited[x-2][y+1]=1;
            Q.push(mp(x-2,y+1));

            level1[x-2][y+1]=level1[x][y]+1;
        }

        if(!visited[x-2][y-1] and a[x-2][y-1]!='#')
        {
            visited[x-2][y-1]=1;
            Q.push(mp(x-2,y-1));

            level1[x-2][y-1]=level1[x][y]+1;
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
    cin>>T;

    while(T--)
    {
        lli M,N,i,j,k;
        cin>>M>>N;

        memset(a,'#',szof(a));
        memset(level,0,szof(level));
        V.clear();

        rep(i,2,M+2)
        {
            string s;
            cin>>s;

            rep(j,2,N+2)
            {
                a[i][j]=s[j-2];
            }
        }

        cout<<"Case "<<t++<<": ";

        rep(i,2,M+2)
        {
            rep(j,2,N+2)
            {
                if(a[i][j]!='.')
                {
                    V.pb(mp(i,j));
                }
            }
        }

        rep(i,0,V.sz())
        {
            lli x=V[i].F,y=V[i].S;

            rep(j,2,M+2)
            {
                rep(k,2,N+2)
                {
                    level1[j][k]=Inf;
                }
            }

            memset(visited,0,szof(visited));

            bfs(x,y);

            lli z=a[x][y]-'0';

            rep(j,2,M+2)
            {
                rep(k,2,N+2)
                    level[j][k]+=level1[j][k]/z;
                {

                    if(level1[j][k]%z)
                    {
                        level[j][k]++;
                    }
                }
            }
        }

        lli Minimum=Inf;

        rep(i,2,M+2)
        {
            rep(j,2,N+2)
            {
                if(Minimum>level[i][j])
                {
                    Minimum=level[i][j];
                }
            }
        }

        if(Minimum>=Inf)
        {
            cout<<-1;
        }
        else
        {
            cout<<Minimum;
        }
        nl;

    }



 return 0;
}
