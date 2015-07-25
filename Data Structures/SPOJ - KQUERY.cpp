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

int t, n, m, caseno = 0, a, b, c, d;
int fen[MAX];
int ar[MAX];

struct arr{
    int value, pos;
};

struct q_query{
    int x, y, k, pos;
};

bool cmp(const arr &a, const arr &b)
{
    return a.value > b.value;
}

bool compare(const q_query &a, const q_query &b)
{
    return a.k > b.k;
}

void update(int idx, int value)
{
    while(idx <= n)
    {
        fen[idx] += value;
        idx += idx & -idx;
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += fen[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    si(n);
    arr ar[n];
    FOR(i, 0, n){
        si(ar[i].value);
        ar[i].pos = i + 1; // as I am using BIT.
    }
    sort(ar, ar + n, cmp);

    si(m);
    q_query q[m];
    int result[m];
    FOR(i, 0, m){
        siii(q[i].x, q[i].y, q[i].k);
        q[i].pos = i;
    }
    sort(q, q + m, compare);

    int pos = 0;
    FOR(i, 0, m){

            while(pos < n  &&  ar[pos].value > q[i].k)
            {
                    update(ar[pos].pos, 1);
                    ++pos;
            }

            result[q[i].pos] = query(q[i].y) - query(q[i].x - 1);
    }

    FOR(i, 0, m)
        printf("%d\n", result[i]);

    return 0;
}
