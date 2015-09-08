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

const int MAX = 1e6 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;

string s;

struct node{

        int ans, unused_left, unused_right;

        void merge(const node &l, const node &r)
        {
            int tmp = min(l.unused_left, r.unused_right);
            ans = l.ans + r.ans + tmp;
            unused_left = l.unused_left + r.unused_left - tmp;
            unused_right = r.unused_right + r.unused_right - tmp;
        }
};

node tree[4*MAX];

int build(int id, int l, int r)
{
    if(l == r) {
        tree[id].ans = 0;
        tree[id].unused_left = (s[l] == '(') ? 1 : 0;
        tree[id].unused_right = (s[l] == ')') ? 1 : 0;
        return tree[id].ans;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    tree[id].merge(tree[2*id], tree[2*id+1]);

    return tree[id].ans;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s;

    cout << 2 * build(1, 0, s.sz-1) << '\n';
    
    FOR(i, 1, 14){
    	cout << i << " " << tree[i].ans << " " << tree[i].unused_left << " " << tree[i].unused_right << '\n';
    }

    //cout << tree[1].ans;

    return 0;
}
