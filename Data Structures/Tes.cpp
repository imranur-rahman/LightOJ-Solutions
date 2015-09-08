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




template <class T> inline T imax(T &a,T b){if(b>a) a=b;}
template <class T> inline T imin(T &a,T b){if(b<a) a=b;}

const int MAX = 150000 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;
int MOD = 1000000007;

int t, n, m, caseno = 0, a, b, c, d, q, s, pos, x, y, k;
int ar[MAX];

struct node{

    int ans, prefix, suffix;

};

node tree[4*MAX];

void mergeup(int id, node& l, node& r)
{
    tree[id].ans = abs(l.suffix - r.prefix);
    tree[id].prefix = l.prefix;
    tree[id].suffix = r.suffix;
}

void build(int id, int l, int r)
{
    if(l == r) {
        tree[id].ans = tree[id].prefix = tree[id].suffix = ar[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    mergeup(id, tree[2*id], tree[2*id+1]);
}

node mergeup(node& l, node& r)
{
    node tmp;

    tmp.ans = abs(l.suffix - r.prefix);
    tmp.prefix = l.prefix;
    tmp.suffix = r.suffix;

    return tmp;
}

node query(int id, int l, int r, int a, int b)
{
    if(l == a && r == b) return tree[id];

    int mid = (l+r)/2;
    if(b <= mid) return query(2*id, l, mid, a, b);
    if(a > mid) return query(2*id+1, mid+1, r, a, b);

    node u = query(2*id, l, mid, a, mid);
    node v = query(2*id+1, mid+1, r, mid+1, b);

    return mergeup(u, v);
}

int main()
{
    //ios_base::sync_with_stdio(false);

    si(t);
    while(t--){

            si(n);
            REP(i, n) si(ar[i]);

            build(1, 0, n-1);

            printf("Case %d: %d\n", ++caseno, query(1, 0, n-1, 0, n-1).ans);
    }

    return 0;
}
