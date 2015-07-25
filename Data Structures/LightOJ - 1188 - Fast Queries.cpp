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
#define MEM(array, value) memset(array, value, sizeof(array))
#define all(v) v.begin(), v.end()
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d%d",&a,&b)
#define siii(a,b,c) scanf("%d%d%d",&a,&b,&c)



template <class T> inline T imax(T a,T b){return (a>b)?a:b;}
template <class T> inline T imin(T a,T b){return (a<b)?a:b;}

const int MAX = 1e5 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d, q;

set<int>tree[4 * MAX];
set<int>null;
int ar[MAX];

void build(int id, int l, int r)
{
    if(l == r){

            tree[id].insert(ar[l]);
            return;
    }

    int mid = (l + r)/2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    set_union(all(tree[2 * id]), all(tree[2 * id + 1]), inserter(tree[id], tree[id].end()));
}

set<int> query(int id, int l, int r, int x, int y)
{
    if(l>y || r<x){

            return null;
    }
    if(l>=x && r<=y) {

            return tree[id];
    }

    int mid = (l + r)/2;
    set<int>a = query(2 * id, l, mid, x, y);
    set<int>b = query(2 * id + 1, mid + 1, r, x, y);

    set<int>ret;
    set_union(all(a), all(b), inserter(ret, ret.end()));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    si(t);
    while(t--){

            FOR(i, 0, MAX) tree[i].clear();

            sii(n, q);
            FOR(i, 0, n) si(ar[i]);

            build(1, 0, n-1);
            printf("Case %d:\n", ++caseno);

            FOR(i, 0, q){

                    sii(a, b);
                    --a, --b;
                    //set<int>result = query(1, 0, n-1, a, b);
                    int p = (query(1, 0, n-1, a, b)).sz;
                    printf("%d\n", p);
                    //printf("%d\n", result.sz);

            }
    }

    return 0;
}













