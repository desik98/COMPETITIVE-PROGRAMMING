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

lli a[502][502];
bool visited[502][502];
lli level[502][502];
lli level1[502][502];

void bfs(lli x,lli y)
{
    lli i;
    queue<plli>Q;

    Q.push(mp(x,y));
    visited[x][y]=1;

    while(!Q.empty())
    {
        plli p=Q.front();
        Q.pop();

        lli x=p.F;
        lli y=p.S;

        if(a[x-1][y] && !visited[x-1][y])
        {
            Q.push(mp(x-1,y));
            visited[x-1][y]=1;

            level[x-1][y]=level[x][y]+1;
        }

        if(a[x][y-1] && !visited[x][y-1])
        {
            Q.push(mp(x,y-1));
            visited[x][y-1]=1;

            level[x][y-1]=level[x][y]+1;
        }

        if(a[x][y+1] && !visited[x][y+1])
        {
            Q.push(mp(x,y+1));
            visited[x][y+1]=1;

            level[x][y+1]=level[x][y]+1;
        }

        if(a[x+1][y] && !visited[x+1][y])
        {
            Q.push(mp(x+1,y));
            visited[x+1][y]=1;

            level[x+1][y]=level[x][y]+1;
        }
    }
}

void bfs1(lli x,lli y)
{
    lli i;
    queue<plli>Q;

    Q.push(mp(x,y));
    visited[x][y]=1;

    while(!Q.empty())
    {
        plli p=Q.front();
        Q.pop();

        lli x=p.F;
        lli y=p.S;

        if(a[x-1][y] && !visited[x-1][y])
        {
            Q.push(mp(x-1,y));
            visited[x-1][y]=1;

            level1[x-1][y]=level1[x][y]+1;
        }

        if(a[x][y-1] && !visited[x][y-1])
        {
            Q.push(mp(x,y-1));
            visited[x][y-1]=1;

            level1[x][y-1]=level1[x][y]+1;
        }

        if(a[x][y+1] && !visited[x][y+1])
        {
            Q.push(mp(x,y+1));
            visited[x][y+1]=1;

            level1[x][y+1]=level1[x][y]+1;
        }

        if(a[x+1][y] && !visited[x+1][y])
        {
            Q.push(mp(x+1,y));
            visited[x+1][y]=1;

            level1[x+1][y]=level1[x][y]+1;
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
        lli N,M,i,j;
        cin>>N>>M;

        memset(a,0,szof(a));
        memset(visited,0,szof(visited));
        memset(level,0,szof(level));
        memset(level1,0,szof(level1));

        lli x,y,x1,y1,x2,y2,x3,y3;

        rep(i,1,N+1)
        {
            string s;
            cin>>s;

            rep(j,0,M)
            {
                char ch=s[j];

                if(ch=='J' || ch=='.')
                {
                    if(ch=='J')
                    {
                        x1=i;y1=j+1;
                    }

                    a[i][j+1]=1;
                }
                else
                {
                    a[i][j+1]=0;
                }

                if(ch=='F')
                {
                    x=i;
                    y=j+1;

                    a[i][j+1]=1;
                }
            }
        }

         bfs(x,y);

        memset(visited,0,szof(visited));

         bfs1(x1,y1);

        rep(i,1,N+1)
        {
            rep(j,1,M+1)
            {
                cout<<level1[i][j]<<' ';
            }
            nl;
        }
        nl;

        rep(i,1,N+1)
        {
            rep(j,1,M+1)
            {
                cout<<level[i][j]<<' ';
            }
            nl;
        }


        lli Minimum=Inf;

        I flag=0;
        rep(i,1,N+1)
        {
            if(level[1][i]>level1[1][i])
            {
                flag=1;
                Minimum=min(Minimum,level1[1][i]);
            }
        }

        rep(i,1,N+1)
        {
            if(level[i][1]>level1[i][1])
            {
                flag=1;
                Minimum=min(Minimum,level1[i][1]);
            }
        }

        rep(i,1,N+1)
        {
            if(level[N][i]>level1[N][i])
            {
                flag=1;
                Minimum=min(Minimum,level1[N][i]);
            }
        }

        rep(i,1,N+1)
        {
            if(level[i][N]>level1[i][N])
            {
                flag=1;
                Minimum=min(Minimum,level1[i][N]);
            }
        }

        cout<<"Case "<<t++<<": ";

        if(flag)
        {
            cout<<Minimum;
        }
        else
        {
            cout<<"IMPOSSIBLE";
        }
        nl;
    }





 return 0;
}
