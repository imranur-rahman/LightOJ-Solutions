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

const int MAX = 30000 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d, k;
vector<int>v[4 * MAX];
int ar[MAX];

void build(int id, int l, int r)
{
    if(l == r){
            v[id].pb(ar[l]);
            return;
    }

    int mid = (l + r)/2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    merge(v[2 * id].begin(), v[2 * id].end(), v[2 * id +1].begin(), v[2 * id + 1].end(), back_inserter(v[id]));
    //in this merge function we merge two sorted container into a sorted container and push that back in another container
}

int query(int id, int l, int r, int x, int y,int k)
{
    if(l>y || r<x) return 0;
    if(l>=x && r<=y){

            return v[id].sz - ( upper_bound(all(v[id]), k) - v[id].begin());
    }

    int mid = (l + r)/2;
    return query(2 * id, l, mid, x, y, k) +
           query(2 * id + 1, mid + 1, r, x, y, k);
}

// INCOMPLETE

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    si(n);
    FOR(i, 0, n){
        si(ar[i]);
    }
    build(1, 0, n-1);


    si(m);
    int ans = 0;
    FOR(i, 0, m){
            siii(a, b, k);
            //if(a != 0) --a;
            //if(b != 0) --b;
            //--a, --b;
            a ^= ans;
            b ^= ans;
            k ^= ans;
            //if(a != 0) --a;
            //if(b != 0) --b;
            ans = query(1, 0, n-1, --a, --b, k);
            printf("%d\n", ans);
    }


    return 0;
}
