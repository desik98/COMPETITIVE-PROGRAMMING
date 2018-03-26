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

#define Inf     100000000000
#define mod		1000000007
using namespace std;

char a[15][15];
bool visited[15][15];
lli level[15][15];

void bfs(lli x1,lli y1,char ch2)
{
    visited[x1][y1]=1;
    level[x1][y1]=0;

    lli i,j;
    queue<plli >Q;

    char ch=ch2;

    Q.push(mp(x1,y1));

    while(!Q.empty())
    {
        plli p=Q.front();

        lli x=p.F,y=p.S;

        Q.pop();

        if(!visited[x-1][y] and (a[x-1][y]<=ch and a[x-1][y]!='#'))
        {
            Q.push(mp(x-1,y));
            visited[x-1][y]=1;

            level[x-1][y]=level[x][y]+1;
        }

        if(!visited[x][y-1] and (a[x][y-1]<=ch and a[x][y-1]!='#'))
        {
            Q.push(mp(x,y-1));
            visited[x][y-1]=1;

            level[x][y-1]=level[x][y]+1;
        }

        if(!visited[x][y+1] and (a[x][y+1]<=ch and a[x][y+1]!='#'))
        {
            Q.push(mp(x,y+1));
            visited[x][y+1]=1;

            level[x][y+1]=level[x][y]+1;
        }

        if(!visited[x+1][y] and (a[x+1][y]<=ch and a[x+1][y]!='#'))
        {
            Q.push(mp(x+1,y));
            visited[x+1][y]=1;

            level[x+1][y]=level[x][y]+1;
        }
    }
}

void Initialize()
{
    memset(a,'#',szof(a));
    memset(visited,0,szof(visited));
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
        lli N,i,j,k;
        cin>>N;

        Initialize();

        I flag1=1;

        //memset(a,szof(a),'#');

        rep(i,1,N+1)
        {
            rep(j,1,N+1)
            {
                cin>>a[i][j];
            }
        }

        cout<<"Case "<<t++<<": ";

        char ch='#';

        rep(i,1,N+1)
        {
            rep(j,1,N+1)
            {
                if(a[i][j]>='A' and a[i][j]<='Z')
                {
                    ch=max(ch,a[i][j]);
                }
            }
        }

        //cout<<ch;

        lli i1,j1,i2,j2;

        lli Sum=0;
        rep(i,0,ch-65)
        {
            char ch1=i+65;

            I flag=0;

            rep(j,1,N+1)
            {
                rep(k,1,N+1)
                {
                    if(a[j][k]==ch1)
                    {
                        i1=j;
                        j1=k;

                        flag=1;

                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
            }

            char ch2=i+66;
            flag=0;

            //cout<<ch1;
            rep(j,1,N+1)
            {
                rep(k,1,N+1)
                {
                    if(a[j][k]==ch2)
                    {
                        i2=j;
                        j2=k;

                        flag=1;

                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
            }

            /*cout<<i2<<' '<<j2;
            nl;*/

            memset(level,0,szof(level));
            memset(visited,0,szof(visited));

            bfs(i1,j1,ch2);

            if(level[i2][j2])
            {
                Sum+=level[i2][j2];
            }
            else
            {
                flag1=0;
                break;
            }
        }

        if(flag1)
        {
            cout<<Sum;
        }
        else
        {
            cout<<"Impossible";
        }

        nl;
    }



 return 0;
}
