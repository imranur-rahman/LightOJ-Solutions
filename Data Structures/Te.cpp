#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ll long long
#define FOR(i, k, n) for(int i=(int) k ; i<(int)n; ++i)
#define REP(i, n) for(int i=0; i<n; ++i)
#define MEM(array) memset(array, -1, sizeof(array))
#define CLR(array) memset(array, 0, sizeof(array))
#define all(v) v.begin(), v.end()
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)





template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 1e7 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;

int lazy[4*MAX];
set<int>s;

void update(int id, int l, int r, int a, int b, int color)
{
    if(a>r || b<l) return;
    if(l>=a && r<=b) {
        lazy[id] = color;
        return;
    }

    if(lazy[id]){

            lazy[2*id] = lazy[2*id+1] = lazy[id];
            lazy[id] = 0;
    }

    int mid = (l+r)/2;
    update(2*id, l, mid, a, b, color);
    update(2*id+1, mid+1, r, a, b, color);

}

void query(int id, int l, int r)
{
    if(lazy[id]){
        s.insert(lazy[id]);
        return;
    }

    if(l == r) return;

    int mid = (l+r)/2;
    query(2*id, l, mid);
    query(2*id+1, mid+1, r);

}

int main()
{
    //ios_base::sync_with_stdio(false);

    si(t);
    while(t--){

            si(n);

            CLR(lazy);

            REP(i, n){

                    sii(a, b);
                    update(1, 1, 10000000, a, b, i+1);
            }

            s.clear();
            query(1, 1, 10000000);

            printf("%d\n", ++caseno, s.sz);
    }


    return 0;
}
