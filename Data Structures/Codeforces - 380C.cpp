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

const int MAX = 1e6 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;
//int fen[MAX];
//int ans[MAX];
string s;
//stack<int>st;
//vector<pii>ar[MAX];

struct node{
    int a, b, c;
    // a for the maximum length of the bracket subsequence (ans for this interval)
    // b for the number of '(' brackets that doesn't belong to the correct sequence
    // c for the number of ')' brackets that doesn't belong to the correct sequence
};

node tree[4 * MAX];

/*void update(int idx)
{
    while(idx <= MAX)
    {
        fen[idx]++;
        //idx += idx & -idx;
        idx |= idx + 1;
    }
}

int sum(int idx)
{
    int ret = 0;
    while(idx >= 0)
    {
        ret += fen[idx];
        //idx -= idx & -idx;
        idx = (idx & (idx + 1)) - 1;
    }
    return ret;
}*/

void build(int idx, int l, int r)
{
    if(l == r){

            tree[idx].a = 0;
            tree[idx].b = (s[l] == '(');
            tree[idx].c = (s[l] == ')');
            return;
    }

    int mid = (l + r) >> 1;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);

    int tmp = min(tree[2 * idx].b, tree[2 * idx + 1].c);

    tree[idx].a = tree[2 * idx].a + tree[2 * idx + 1].a + tmp;
    tree[idx].b = tree[2 * idx].b + tree[2 * idx + 1].b - tmp;
    tree[idx].c = tree[2 * idx].c + tree[2 * idx + 1].c - tmp;

}

node query(int idx, int l, int r, int x, int y)
{
    if(l>y || r<x) return (node){0, 0, 0};
    if(l>=x && r<=y){

            return tree[idx];
    }

    int mid = (l + r) >> 1;
    node left = query(idx<<1, l, mid, x, y);
    node right = query(2 * idx + 1, mid + 1, r, x, y);

    int A, B, C, tmp;
    tmp = min(left.b, right.c);

    A = left.a + right.a + tmp;
    B = left.b + right.b - tmp;
    C = left.c + right.c - tmp;

    return (node) {A, B, C};
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s;
    n = s.sz;
    build(1, 0, n-1);

    cin >> m;
    FOR(i, 0, m){
        cin >> a >> b;
        //ar[a].pb(mp(b, i));
        node ret = query(1, 0, n-1, --a, --b);
        printf("%d\n", ret.a << 1);
    }

    /*FOR(i, 0, n){
        if(s[i] == '(')
            st.push(i);
        else if(!st.empty()){
            update(st.top());
            st.pop();
        }
        FOR(j, 0, ar[i].sz){
            ans[ar[i][j].ss] = sum(ar[i][j].ff) * 2;
        }
    }

    FOR(i, 0, m)
        cout << ans[i] << endl;
    */
    return 0;
}
