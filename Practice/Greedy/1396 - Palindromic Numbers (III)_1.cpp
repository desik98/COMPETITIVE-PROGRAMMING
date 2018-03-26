#include <bits/stdc++.h>
using namespace std;

/*------- Constants---- */
#define LMT             100005
#define ll              long long
#define ull             unsigned long long
#define mod             1000000007
#define MEMSET_INF      63
#define MEM_VAL         1061109567
#define FOR(i,n)            for( int i=0 ; i < n ; i++ )
#define mp(i,j)         make_pair(i,j)
#define lop(i,a,b)      for( int i = (a) ; i < (b) ; i++)
#define pb(a)           push_back((a))
#define gc              getchar_unlocked
#define PI              acos(-1.0)
#define inf             1<<30
#define lc              ((n)<<1)
#define rc              ((n)<<1 |1)
#define msg(x)          cout<<x<<endl;

/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
/*------ template functions ------ */
inline void sc(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 | c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

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


char str[LMT];
char out[LMT];

int main()
{
    int tc,cs = 0;
    sc(tc);
    while (tc -- ) {

        scanf("%s",str);
        int len = 0 ;
        bool flag = true;

        for( ; str[len] ; len ++ ){
            if( str[len] !='9') {
                flag = false;
            }
        }

        printf("Case %d: ",++cs);

        if(len == 1) {
            if(str[0] <'9' )printf("%c\n" ,str[0] +  1);
            else printf("11\n");
            continue;
        }

        if(flag == true ){
            printf("1");
            for(int i = 1; i < len ; i ++) printf("0");
            printf("1\n");
            continue;
        }
        else {

            out[len] = '\0';

            bool isbig=true , iseq = 1;
            for(int i = (len - 1)/2 ; i >=0  ;i -- ){
                if(str[i]!= str[len-1-i]) {
                    isbig = str[i] > str[len-1-i];
                    iseq = 0;
                    break;
                }
                if(str[i] != str[len - 1 - i ]) iseq = 0;
            }

            if(isbig && iseq == 0) {
                for(int i = 0 ; i <= (len - 1)/2 ;i ++ ) out[i] = out[len-1-i] = str[i];
                printf("%s\n",out);
                continue;
            }


            int ink , pos = 0;
            for(int i = (len-1)/2 ; i >=0 ; i -- ) {

                if( str[i] !='9') {
                    ink = str[i] +1 ;
                    pos = i ;
                    flag = true;
                    break;
                }
            }



            for(int i = 0 ; i < pos ; i ++ ) out[i] = out[len-1-i] = str[i];
            out[pos]= out[len -1 - pos]  = ink;
            for(int i = pos + 1; i < len -1 - pos ; i ++ ) out[i] = '0';

            printf("%s\n",out);

        }

    }
    return 0;
}
