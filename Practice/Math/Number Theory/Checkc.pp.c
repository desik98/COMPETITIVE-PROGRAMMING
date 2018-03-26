/*
    AUTHOR:hruday pabbisetty
    NIT ROURKElA(My_College_Sucks)
*/
#include <bits/stdc++.h>
using namespace std;
#define opt ios_base::sync_with_stdio(0)
#define lli long long int
#define ulli unsigned long long int
#define I int
#define S string
#define D double
#define rep(i,a,b) for(i=a;i<b;i++)
#define repr(i,a,b) for(i=a;i>b;i--)
#define in(n) scanf("%lld",&n)
#define in2(a,b) scanf("%lld %lld",&a,&b)
#define in3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define out(n) printf("%lld",n)
#define inu(a) scanf("%lld",&a)
#define outu(a) printf("%llu",a)
#define ins(s) scanf("%s",&s)
#define outs(s) printf("%s",s)
#define nl printf("\n")
#define mod 1000000007
#define inf 100000000000000
typedef long long       ll;
typedef pair<lli, lli>  plli;
typedef vector<lli>     vlli;
typedef vector<ulli>    vulli;
typedef vector<ll>      vll;
typedef vector<string>  vs;
typedef vector<plli>     vplli;
#define MM(a,x)  memset(a,x,sizeof(a));
#define ALL(x)   (x).begin(), (x).end()
#define P(x)       cerr<<"{"#x<<" = "<<(x)<<"}"<<endl;
#define P2(x,y)       cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<"}"<<endl;
#define P3(x,y,z)  cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<"}"<<endl;
#define P4(x,y,z,w)cerr<<"{"#x" = "<<(x)<<", "#y" = "<<(y)<<", "#z" = "<<(z)<<", "#w" = "<<(w)<<"}"<<endl;
#define PP(x,i)     cerr<<"{"#x"["<<i<<"] = "<<x[i]<<"}"<<endl;
#define TM(a,b)     cerr<<"{"#a" -> "#b": "<<1000*(b-a)/CLOCKS_PER_SEC<<"ms}\n";
#define UN(v)    sort(ALL(v)), v.resize(unique(ALL(v))-v.begin())
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define sz() size()
lli power(lli a,lli b)
    {
    lli value;
    if(b==0)
        {
        return 1;
    }
    else if(b%2==0)
        {
        value=power(a,b/2)%mod;
        return(value*value)%mod;
    }
    else
        {
        value=power(a,b/2)%mod;
        return ((a*value)%mod*(value))%mod;
    }
}
lli r[10000002],dis[10000002],visited[10000002],n,t;
void BFS(lli k)
{
    visited[k]=1;
    lli i;
    dis[k]=0;
    queue<lli>q;
    q.push(k);
    while(q.sz())
    {
        lli p=q.front();
        q.pop();

        repr(i,r[p],0)
        {
            lli node=p+i;
            node%=n;
            if(!visited[node])
            {
               dis[node]=1+dis[p];
                visited[node]=1;
                if(!visited[(node+r[node])%n])
                {
                    q.push(node);
                }
                if(node==t)
                {
                    cout<<dis[t];
                    exit(0);
                }
            }
            else
            {
                break;
            }
        }
            repr(i,r[p],0)
            {
            lli node=(p-i+n)%n;
            if(!visited[node])
            {
                dis[node]=1+dis[p];
                visited[node]=1;
                if(!visited[(node-r[node]+n)%n])
                {
                    q.push(node);
                }
                if(node==t)
                {
                    cout<<dis[t];
                    exit(0);
                }
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
        /*#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif*/

    opt;
    lli s;
    cin>>n>>s>>t;

    lli seed,g,p,ans=0,diff,i;
    cin>>r[0]>>g>>seed>>p;

    rep(i,1,n)
    {
        r[i]=(r[i-1]*g+seed)%p;
    }

    BFS(s);

    if(visited[t])
    {
        cout<<dis[t];
    }
    else
    {
        cout<<-1;
    }
}
