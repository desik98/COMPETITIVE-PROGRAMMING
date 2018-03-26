#include <bits/stdc++.h>
using namespace std;

/*------- Constants---- */
#define MX                      100005
#define ll                      long long
#define ull                     unsigned long long
#define mod                     1000000007
#define MEMSET_INF              63
#define MEM_VAL                 1061109567
#define FOR(i,n)                for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define lop(i,a,b)              for( int i = (a) ; i < (b) ; i++)
#define pb(a)                   push_back((a))
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define inf                     1<<30
#define lc                      ((n)<<1)
#define rc                      ((n)<<1 |1)

/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
/*------ template functions ------ */

template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

/*************************** END OF TEMPLATE ****************************/

const ll MAC = 1000000000LL;
vector<ll> lucky;

void cal(ll sum)
{
    if(sum > 0 && sum < MAC){
        lucky.push_back(sum);
    }
    if(sum > MAC) return;
    cal(sum * 10 + 4);
    cal(sum * 10 + 7);

}

vector<ll>vrLucky;
set<ll> Sk;
void backTr(ll ix, ll sum)
{
    if(sum > MAC ) return;

    if(sum < MAC && sum > 1) {
        Sk.insert(sum);
    }

    if(ix == lucky.size() ) {
        return;
    }

    if( sum <= MAC / lucky[ix] ) backTr(ix , sum * lucky[ix]); //Use the number more than one time
    if( sum <= MAC / lucky[ix] ) backTr(ix + 1, sum); // Don’t use this number
    if( sum <= MAC / lucky[ix] ) backTr(ix + 1, sum * lucky[ix]); // Use the once, go to the next number. As the numbers are sorted the following conditions always holds

    return;

}

ll bs(ll val)
{
    int L = 0, H = (int)vrLucky.size() , mid , ans = L - 1 ;
    while (L <= H ) {
        mid = (L + H ) >> 1;
        if(vrLucky[mid] <= val) {
            ans = mid;
            L = mid + 1;
        }
        else H = mid - 1;
    }
    return ans ;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("double_squares.txt","r",stdin);
    freopen("double_squares1_out.txt","w",stdout);
    #endif // ONLINE_JUDGE*/

    cal(0);
    sort(lucky.begin(), lucky.end());
    backTr(0 , 1);

    set<ll> ::iterator it= Sk.begin();
    while(it != Sk.end() ){
        vrLucky.push_back(*it);
        cout<<*it<<' ';
        it++;
    }
    cout<<'\n';
    cout<<'\n';

    cout<<vrLucky.size()<<' ';

    //Sk.clear();
    /*ll tc , cs = 0 , a , b ;
    sc(tc);
    while (tc -- ) {
        sc(a) ;sc(b);

        printf("Case %lld: %ld\n", ++cs , upper_bound(vrLucky.begin() , vrLucky.end() , b) - lower_bound(vrLucky.begin(), vrLucky.end(), a));

    }*/
    return 0;
}
