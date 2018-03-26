/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<bits/stdc++.h>
#define opt std::ios_base::sync_with_stdio(false)
#define I int
#define li		int32_t
#define lli		int
#define ulli unsigned long long

#define pn			printf("\n")
#define nl			cout<<'\n'
#define sf(N)       scanf("%d",&N)
#define pf(N)       printf("%d",N)
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

lli BIT[100001];
vlli V;
lli N;

void update(lli i,lli Value)
{
    for(;i<=N;i+=i&-i)
    {
        BIT[i]+=Value;
    }
}

lli Query(lli x)
{
    lli Sum=0;
    for(;x>0;x-=x&-x)
    {
        Sum+=BIT[x];
    }

 return Sum;
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
    freopen("Binary_Simulation.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        char s[100001];
        scanf("%s",s);

        printf("Case ");
        pf(t++);
        printf(":\n");

        N=strlen(s);
        lli i;
        V.pb(0);

        memset(BIT,0,szof(BIT));

        rep(i,0,N)
        {
            V.pb(s[i]-'0');
        }

        rep(i,2,N+1)
        {
            V[i]=s[i-1]-s[i-2];
        }

        rep(i,1,N+1)
        {
            update(i,V[i]);
        }

        lli Q;
        sf(Q);

        while(Q--)
        {
            char ch;
            scanf(" %c",&ch);

            if(ch=='I')
            {
                lli a,b;
                sf(a);
                sf(b);

                update(a,1);

                if(b!=N)
                {
                    update(b+1,-1);
                }
            }
            else
            {
                lli x;
                sf(x);

                lli a=Query(x);
                if(a%2)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
                pn;
            }
        }

        V.clear();
    }



 return 0;
}
