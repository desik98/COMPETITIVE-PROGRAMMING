/*I MAY NOT GET THE SUCCESS IMMEDIATELY BUT I WILL GET IT FOR SURE*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#define rep(i,a,b)	for(i=a;i<b;i++)
#define pb		push_back
#define sz()	size()
#define szof    sizeof
#define mp		make_pair
#define vlli    vector<lli>
using namespace std;

int BIT[200001];
int N;

void update(int i,int Value)
{
    while(i<=N)
    {
        BIT[i]+=Value;
        i+=i&-i;
    }
}

int query(int i)
{
    int Sum=0;

    while(i>0)
    {
        Sum+=BIT[i];
        i-=i&-i;
    }

 return Sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Diablo.txt","r",stdin);
    freopen("double_squares_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    int T,t=1;
    scanf("%d",&T);

    while(T--)
    {
        memset(BIT,0,szof(BIT));

        int i,Q;
        scanf("%d %d",&N,&Q);

        int cnt=0;

        vector<int> V;
        V.pb(0);

        for(i=1;i<N+1;i=i+1)
        {
            int x;
            scanf("%d",&x);

            V.pb(x);
        }
        N=N+Q;

        printf("Case %d:\n",t++);

        for(i=1;i<V.sz();i=i+1)
        {
            update(i,1);
        }
        cnt+=V.sz()-1;

        while(Q--)
        {
            char ch;
            scanf(" %c",&ch);

            int x;
            scanf("%d",&x);

            if(ch=='a')
            {
                V.pb(x);
                update(V.sz()-1,1);

                cnt++;
            }
            else
            {
                if(cnt<x)
                {
                    printf("none\n");

                    continue;
                }

                int low=1,high=V.sz()-1,ans=V.sz()-1;
                while(low<=high)
                {
                    int mid=(low+high)/2;

                    if(query(mid)>=x)
                    {
                        ans=min(ans,mid);
                        high=mid-1;
                    }
                    else
                    {
                        low=mid+1;
                    }
                }

                printf("%d\n",V[ans]);
                update(ans,-1);

                cnt--;
            }
        }

    }




 return 0;
}
