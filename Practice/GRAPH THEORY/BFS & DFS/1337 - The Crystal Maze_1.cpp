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
#define S  		second

#define Inf     100000000000
#define mod		1000000007
using namespace std;

lli cnt=0;
lli a[502][502];
bool visited[502][502];

void dfs(lli x,lli y)
{
    visited[x][y]=1;

    if(a[x-1][y] && !visited[x-1][y])
    {
        if(a[x-1][y]==2)
        {
            cnt++;
            cout<<x<<' '<<y<<' '<<x-1<<' '<<y;
            nl;
        }

        dfs(x-1,y);
    }

    if(a[x][y-1] && !visited[x][y-1])
    {
        if(a[x][y-1]==2)
        {
            cnt++;
            cout<<x<<' '<<y<<' '<<x<<' '<<y-1;
            nl;
        }

        dfs(x,y-1);
    }

    if(a[x][y+1] && !visited[x][y+1])
    {
        if(a[x][y+1]==2)
        {
            cnt++;
            cout<<x<<' '<<y<<' '<<x<<' '<<y+1;
            nl;
        }

        dfs(x,y+1);
    }

    if(a[x+1][y] && !visited[x+1][y])
    {
        if(a[x+1][y]==2)
        {
            cnt++;
        }

        dfs(x+1,y);
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
        lli N,M,Q,i,j;
        cin>>N>>M>>Q;

        rep(i,0,N+1)
        {
            rep(j,0,M+1)
            {
                visited[i][j]=0;
                a[i][j]=0;
            }
        }

        lli x,y;

        rep(i,1,N+1)
        {
            string s;
            cin>>s;

            rep(j,0,M)
            {
                char ch=s[j];

                if(ch=='C')
                {
                    a[i][j+1]=2;
                    continue;
                }

                if(ch=='.')
                {
                    a[i][j+1]=1;
                }
                else
                {
                    a[i][j+1]=0;
                }
            }
        }

        cout<<"Case "<<t++<<": ";
        nl;

        while(Q--)
        {
            lli x,y;
            cin>>x>>y;

            cnt=0;

            dfs(x,y);

            rep(i,1,N+1)
            {
                rep(j,1,M+1)
                {
                    visited[i][j]=0;
                }
            }

            cout<<cnt;

            nl;
        }
    }





 return 0;
}
