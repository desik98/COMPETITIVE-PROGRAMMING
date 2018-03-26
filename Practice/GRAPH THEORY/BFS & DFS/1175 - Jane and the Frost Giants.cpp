/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li      int32_t
#define lli     int
#define ulli unsigned long long

#define pn          printf("\n")
#define nl          cout<<'\n'
#define sf(N)       scanf("%d",&N)
#define pf(N)       printf("%d",N)
#define sl          cout<<' '
#define ps          printf(" ")

#define rep(i,a,b)  for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define elif        else if
#define mset(a,b)   memset(a,b,sizeof(a))

#define pb      push_back
#define pob     pop_back
#define itr     iterator
#define sz()    size()
#define szof    sizeof
#define lb      lower_bound
#define ub      upper_bound
#define mp      make_pair
#define vlli    vector<lli>
#define plli    pair<lli,lli>
#define vplli   vector<plli >
#define F       first
#define S       second
#define Dup erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000
#define mod     1000000007
using namespace std;

char a[202][202];
bool visited[202][202];
lli level[202][202];
lli level1[202][202];
lli level2[202][202];
vplli V;

void bfs(lli x1,lli y1)
{
    visited[x1][y1]=1;
    level[x1][y1]=0;

    lli i,j;
    queue<plli >Q;

    Q.push(mp(x1,y1));

    while(!Q.empty())
    {
        plli p=Q.front();

        lli x=p.F,y=p.S;

        Q.pop();

        if(!visited[x-1][y] and a[x-1][y]!='#')
        {
            Q.push(mp(x-1,y));
            visited[x-1][y]=1;

            level[x-1][y]=level[x][y]+1;
        }

        if(!visited[x][y-1] and a[x][y-1]!='#')
        {
            Q.push(mp(x,y-1));
            visited[x][y-1]=1;

            level[x][y-1]=level[x][y]+1;
        }

        if(!visited[x][y+1] and a[x][y+1]!='#')
        {
            Q.push(mp(x,y+1));
            visited[x][y+1]=1;

            level[x][y+1]=level[x][y]+1;
        }

        if(!visited[x+1][y] and a[x+1][y]!='#')
        {
            Q.push(mp(x+1,y));
            visited[x+1][y]=1;

            level[x+1][y]=level[x][y]+1;
        }
    }
}

void bfs1(lli x1,lli y1)
{
    visited[x1][y1]=1;
    level2[x1][y1]=0;

    lli i,j;
    queue<plli >Q;
    vplli V2;

    Q.push(mp(x1,y1));

    while(!Q.empty())
    {
        plli p=Q.front();

        lli x=p.F,y=p.S;
        V2.pb(mp(x,y));

        Q.pop();

        if(level1[x][y]>level2[x][y])
        {
            if(!visited[x-1][y] and a[x-1][y]!='#')
            {
                Q.push(mp(x-1,y));
                visited[x-1][y]=1;

                level2[x-1][y]=level2[x][y]+1;
            }

            if(!visited[x][y-1] and a[x][y-1]!='#')
            {
                Q.push(mp(x,y-1));
                visited[x][y-1]=1;

                level2[x][y-1]=level2[x][y]+1;
            }

            if(!visited[x][y+1] and a[x][y+1]!='#')
            {
                Q.push(mp(x,y+1));
                visited[x][y+1]=1;

                level2[x][y+1]=level2[x][y]+1;
            }

            if(!visited[x+1][y] and a[x+1][y]!='#')
            {
                Q.push(mp(x+1,y));
                visited[x+1][y]=1;

                level2[x+1][y]=level2[x][y]+1;
            }
        }
    }

    rep(i,0,V2.sz())
    {
        lli x=V2[i].F,y=V2[i].S;

        level1[x][y]=min(level1[x][y],level2[x][y]);
        level2[x][y]=Inf;
        visited[x][y]=0;
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
    //opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        lli R,C,i,j,k;
        sf(R);
        sf(C);

        rep(i,0,R+2)
        {
            rep(j,0,C+2)
            {
                visited[i][j]=0;
                level1[i][j]=Inf;
                level[i][j]=Inf;
                a[i][j]='#';
            }
        }
        V.clear();

        rep(i,1,R+1)
        {
            char s[200];
            scanf("%s",s);

            rep(j,1,C+1)
            {
                a[i][j]=s[j-1];
            }
        }

        printf("Case ");
        pf(t++);
        printf(": ");

        lli x,y,x1,y1;

        rep(i,1,R+1)
        {
            rep(j,1,C+1)
            {
                if(a[i][j]=='J')
                {
                    x=i,y=j;
                }
            }
        }

        rep(i,1,R+1)
        {
            rep(j,1,C+1)
            {
                if(a[i][j]=='F')
                {
                    V.pb(mp(i,j));
                }
            }
        }

        bfs(x,y);

        rep(i,1,R+1)
        {
            rep(j,1,C+1)
            {
                visited[i][j]=0;
            }
        }

        rep(k,0,V.sz())
        {
            x=V[k].F,y=V[k].S;

            bfs1(x,y);
        }

        I flag=0;
        lli Val=Inf;

        rep(i,1,R+1)
        {
            if(i==1 or i==R)
            {
                rep(j,1,C+1)
                {
                    if(level1[i][j]>level[i][j])
                    {
                        flag=1;

                        if(level[i][j]<Val)
                        {
                            Val=level[i][j];
                        }
                    }
                }
            }
            else
            {
                if(level1[i][1]>level[i][1])
                {
                    flag=1;

                        if(level[i][1]<Val)
                        {
                            Val=level[i][1];
                        }
                }

                if(level1[i][C]>level[i][C])
                {
                    flag=1;

                        if(level[i][C]<Val)
                        {
                            Val=level[i][C];
                        }
                }
            }
        }

        //cout<<Val;

        if(flag)
        {
            pf(Val+1);
        }
        else
        {
            printf("IMPOSSIBLE");
        }

        nl;
    }




 return 0;
}
