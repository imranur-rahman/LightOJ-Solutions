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

const int MAX = 1e7 + 1;
const ll MAXINT = 1e18;
const int INF = 1e9;

int t, n, m, caseno = 0, a, b, c, d;
int lazy[4 * MAX];


void update(int idx, int a, int b, int x, int y, int color)
{
    if(x>b || y<a) return;
    if(a>=x && b<=y){

            lazy[idx] = color;
            return;
    }

    int mid = (a + b)/2;
    if(lazy[idx]){

            lazy[2 * idx] = lazy[2 * idx + 1] = lazy[idx];

            lazy[idx] = 0;
    }

    update(2 * idx, a, mid, x, y, color);
    update(2 * idx + 1, mid + 1, b, x, y, color);
}


set<int>s;
void query(int idx, int a, int b)
{
    if(lazy[idx]){
            s.insert(lazy[idx]);
            return;
    }
    if(a == b) return; // even if lazy[idx] is zero, then we don't need to count the child. Because we are updating color based on index 1

    int mid = (a + b)/2;
    query(2 * idx, a,  mid);
    query(2 * idx + 1, mid + 1, b);
}

int main()
{
    ios_base::sync_with_stdio(false);

    si(t);
    while(t--){

            MEM(lazy, 0);
            s.clear();
            si(m);

            FOR(i, 0, m){

                    sii(a, b);
                    update(1, 0, MAX - 1, --a, --b, i + 1);
            }

            query(1, 0, MAX - 1);

            printf("%d\n", s.sz);
    }

    return 0;
}
