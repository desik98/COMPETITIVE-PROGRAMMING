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
#define F   	first
#define S		second
#define ALL(V)  V.begin(),V.end()
#define Dup     erase(unique(V.begin(),V.end()),V.end())

#define Inf     1000000000000000
#define mod		1000000007
using namespace std;

vector<pair<plli,lli > >queries;
lli BLOCK_SIZE;
lli answer[200001];
lli current_answer;
lli cnt[1000001];
multiset<lli> M;
multiset<lli> :: itr it;

bool comp(const pair<plli ,lli> &a,const pair<plli,lli> &b)
{
    if(a.F.F/BLOCK_SIZE!=b.F.F/BLOCK_SIZE)
    {
        return(a.F.F/BLOCK_SIZE<b.F.F/BLOCK_SIZE);
    }

    return a.F.S<b.F.S;
}

void add(lli x)
{
    M.insert(x);

    current_answer=*M.begin();
}

void rem(lli x)
{
    it=M.find(x);

    M.erase(it);

    current_answer=*M.begin();
}

int main()
{
    lli T,t=1;
    sf(T);

    while(T--)
    {
        M.clear();

        lli N,i,Q;
        sf(N);
        sf(Q);

        BLOCK_SIZE=sqrt(N);

        vlli V(N+1);

        rep(i,1,N+1)
        {
            sf(V[i]);
        }

        lli q=Q-1;

        while(Q--)
        {
            lli L,R;
            sf(L);
            sf(R);

            queries.pb(mp(mp(L,R),q-Q));
        }

        sort(ALL(queries),comp);
        current_answer=0;

        lli mo_left=1,mo_right=0;

        Q=q+1;

        rep(i,0,q+1)
        {
            lli left=queries[i].F.F,right=queries[i].F.S;

            lli cnt1=0,cnt2=0;

            while(mo_left<left)
            {
                rem(V[mo_left]);
                mo_left++;
            }

            while(mo_left>left)
            {
                mo_left--;
                add(V[mo_left]);
            }

            while(mo_right<right)
            {
                mo_right++;
                add(V[mo_right]);
            }

            while(mo_right>right)
            {
                rem(V[mo_right]);
                mo_right--;
            }

            answer[queries[i].S]=current_answer;
        }

        printf("Case %d:\n",t++);
        rep(i,0,Q)
        {
            pf(answer[i]);
            pn;
        }
        queries.clear();
    }



 return 0;
}
