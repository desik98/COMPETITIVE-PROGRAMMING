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

lli BIT[100001];
lli V[100001];
lli N;

void update(lli x,lli Value)
{
    for(;x<=N;x+=x&-x)
    {
        BIT[x]+=Value;
    }
}

lli query(lli L)
{
    lli Sum=0;
    for(;L>0;L-=L&-L)
    {
        Sum+=BIT[L];
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
    freopen("Curious_Robin_Hood.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    lli T,t=1;
    sf(T);

    while(T--)
    {
        memset(BIT,0,szof(BIT));

        lli i,Q;
        sf(N);
        sf(Q);

        rep(i,1,N+1)
        {
            sf(V[i]);

            update(i,V[i]);
        }

        printf("Case ");
        pf(t++);
        printf(":\n");

        while(Q--)
        {
            lli x;
            sf(x);

            if(x==1)
            {
                lli index;
                sf(index);

                index++;

                pf(V[index]);
                pn;

                if(V[index])
                {
                    update(index,-V[index]);
                    V[index]=0;
                }
            }
            elif(x==2)
            {
                lli index,money;
                sf(index);
                sf(money);

                index++;
                V[index]+=money;

                update(index,money);
            }
            else
            {
                lli L,R;
                sf(L);
                sf(R);

                L++;
                R++;

                pf(query(R)-query(L-1));
                pn;
            }
        }
    }




 return 0;
}
