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
#define TIME(a) printf("Time %d\n", clock() - a)



template <class T> inline T imax(T &a,T b){if(b>a) a=b;}
template <class T> inline T imin(T &a,T b){if(b<a) a=b;}

const int MAX = 100 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;

struct node{

    int consecutive, bestPrefix, bestSuffix, totalConsecutive;
};

node tree[4*MAX];

void build_up(int id)
{
    node l = tree[2*id];
    node r = tree[2*id+1];

    tree[id].bestPrefix = max(l.bestPrefix, r.bestPrefix + l.totalConsecutive);
    tree[id].bestSuffix = max(r.bestSuffix, l.bestSuffix + r.totalConsecutive);
    tree[id].totalConsecutive = l.totalConsecutive + r.totalConsecutive;
    tree[id].consecutive = max()
}


void build(int id, int l, int r)
{
    if(l == r){
        tree[id].consecutive = tree[id].bestPrefix = tree[id].bestSuffix = tree[id].totalConsecutive = (s[l] == '.') ? 1 : 0;
        return;
    }

    build(2*id, l, (l+r)/2);
    build(2*id+1, (l+r)/2 + 1, r);


}

int main()
{
    ios_base::sync_with_stdio(false);

    sii(n, m);



    return 0;
}
