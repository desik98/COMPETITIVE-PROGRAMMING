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

char a[60][60];
lli N;
I flag;

bool visited[60][60];
lli cnt;

void dfs(lli x,lli y)
{
    visited[x][y]=1;
    cnt++;

    if(a[x-1][y]=='?' and !visited[x-1][y])
    {
        dfs(x-1,y);
    }

    if(a[x+1][y]=='?' and !visited[x+1][y])
    {
        dfs(x+1,y);
    }

    if(a[x][y-1]=='?' and !visited[x][y-1])
    {
        dfs(x,y-1);
    }

    if(a[x][y+1]=='?' and !visited[x][y+1])
    {
        dfs(x,y+1);
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

void dfs1(lli x,lli y)
{
    visited[x][y]=1;

    if(a[x-1][y]!='.')
    {
        if(a[x-1][y]=='?')
        {
            if(!visited[x-1][y])
            {
                a[x-1][y]=a[x][y];
                dfs1(x-1,y);
            }
        }
        else
        {
            if(a[x-1][y]!=a[x][y])
            {
                flag=0;
            }
        }
    }

    if(a[x+1][y]!='.')
    {
        if(a[x+1][y]=='?')
        {
            if(!visited[x+1][y])
            {
                a[x+1][y]=a[x][y];
                dfs1(x+1,y);
            }
        }
        else
        {
            if(a[x+1][y]!=a[x][y])
            {
                flag=0;
            }
        }
    }

    if(a[x][y-1]!='.')
    {
        if(a[x][y-1]=='?')
        {
            if(!visited[x][y-1])
            {
                a[x][y-1]=a[x][y];
                dfs1(x,y-1);
            }
        }
        else
        {
            if(a[x][y-1]!=a[x][y])
            {
                flag=0;
            }
        }
    }

    if(a[x][y+1]!='.')
    {
        if(a[x][y+1]=='?')
        {
            if(!visited[x][y+1])
            {
                a[x][y+1]=a[x][y];
                dfs1(x,y+1);
            }
        }
        else
        {
            if(a[x][y+1]!=a[x][y])
            {
                flag=0;
            }
        }
    }

}

void dfs2(lli x,lli y)
{
    visited[x][y]=1;

    if(a[x-1][y]!='.')
    {
        flag=0;
    }

    if(a[x+1][y]!='.')
    {
        flag=0;
    }

    if(a[x][y-1]!='.')
    {
        flag=0;
    }

    if(a[x][y+1]!='.')
    {
        flag=0;
    }
}

int main()
{
    opt;

    /*#ifndef ONLINE_JUDGE
    freopen("double_squares.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T;
    cin>>T;

    while(T--)
    {
        lli i,j;
        cin>>N;

        flag=1;

        memset(a,'.',szof(a));
        memset(visited,0,szof(visited));

        rep(i,1,N+1)
        {
            string s;
            cin>>s;

            rep(j,1,N+1)
            {
                a[i][j]=s[j-1];
            }
        }

        I flag1=1;
        rep(i,1,N+1)
        {
            rep(j,1,N+1)
            {
                if(a[i][j]!='.')
                {
                    flag1=0;
                }
            }
        }

        if(flag1)
        {
            cout<<1;
            nl;

            continue;
        }

        rep(i,1,N+1)
        {
            rep(j,1,N+1)
            {
                if(!visited[i][j] and a[i][j]=='G')
                {
                    dfs2(i,j);

                    if(!flag)
                    {
                        break;
                    }

                    continue;
                }

                if(!visited[i][j] and a[i][j]!='.' and a[i][j]!='?')
                {
                    dfs1(i,j);

                    if(!flag)
                    {
                        break;
                    }
                }
            }

            if(!flag)
            {
                break;
            }
        }

        if(flag)
        {
            lli Product=1;

            memset(visited,0,szof(visited));
            rep(i,1,N+1)
            {
                rep(j,1,N+1)
                {
                    if(!visited[i][j] and a[i][j]=='?')
                    {
                        cnt=0;
                        dfs(i,j);

                        if(cnt==1)
                        {
                            Product*=3;
                        }
                        else
                        {
                            Product*=2;
                        }

                        Product%=mod;
                    }
                }
            }

            cout<<Product;
        }
        else
        {
            cout<<'0';
        }

        nl;

    }



 return 0;
}
