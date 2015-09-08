#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int N,Q;
int a[100010];
int cnt[100010];

int sz;
int x[500];
int sum[500][100010];

int main(void){
    int i,j;

    scanf("%d%d",&N,&Q);
    REP(i,N) scanf("%d",&a[i]);

    REP(i,N) if(a[i] <= N) cnt[a[i]]++;
    for(i=1;i<=N;i++) if(cnt[i] >= i){
        x[sz] = i;
        sz++;
    }

    REP(i,sz) REP(j,N) sum[i][j+1] = sum[i][j] + ((a[j] == x[i]) ? 1 : 0);

    REP(i,Q){
        int L,R;
        scanf("%d%d",&L,&R);
        L--;

        int ans = 0;
        REP(j,sz) if(sum[j][R] - sum[j][L] == x[j]) ans++;
        printf("%d\n", ans);
    }

    return 0;
}
