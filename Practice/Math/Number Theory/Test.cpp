#include <bits/stdc++.h>
#define _CRT_SECURE_NO_DEPRECATE
#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define LSOne(S) (S & (-S))

using namespace std;
typedef pair<int, int> ii;
typedef pair<ii,ii> pp;

const int MAXN = 100007;
const int BLOCK = 320;

int arr[MAXN],counter[MAXN],a[MAXN],ans[MAXN],BIT[MAXN];
vector<pp> vec;


bool cmp(const pp &a,const pp &b){
    if(a.first.first/BLOCK != b.first.first/BLOCK){
        return a.first.first/BLOCK < b.first.first/BLOCK;
    }
    return a.first.second < b.first.second;
}

int main(){
    int t,n,q,u,v,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        memset(counter,0,sizeof(counter));
        memset(BIT,0,sizeof(BIT));
        vec.clear();
        REP(i,0,n-1){
            scanf("%d",&arr[i]);
        }
        a[0] = 1;
        int ctr = 1;
        REP(i,1,n-1){
            if(arr[i] == arr[i-1])a[i] = a[i-1];
            else{
                ctr++;
                a[i] = ctr;
            }
        }
        REP(i,1,q){
            scanf("%d %d %d",&u,&v,&w);
            u--;v--;
            vec.push_back(pp(ii(u,v),ii(w,i)));
        }
        sort(vec.begin(),vec.end(),cmp);

        int currentL = 0, currentR = 0;

        REP(i,0,vec.size()-1){
            int L = vec[i].first.first,R = vec[i].first.second;

            while(currentR <= R){
                counter[a[currentR]]++;
                BIT[counter[a[currentR]]]++;
                currentR++;
            }
            while(currentR > R+1) {
                BIT[counter[a[currentR-1]]]--;
                counter[a[currentR-1]]--;
                currentR--;
            }
            while(currentL > L) {
                counter[a[currentL-1]]++;
                BIT[counter[a[currentL-1]]]++;
                currentL--;
            }
            while(currentL < L){
                BIT[counter[a[currentL]]]--;
                counter[a[currentL]]--;
                currentL++;
            }
            ans[vec[i].second.second] = BIT[vec[i].second.first];
            //cerr<<val<<endl;
        }
        REP(i,1,q){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
