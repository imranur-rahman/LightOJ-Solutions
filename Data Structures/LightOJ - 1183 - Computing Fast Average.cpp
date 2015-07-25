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

int t, n, m, caseno = 0, a, b, c, d, q, v;

int tree[4 * MAX];
int lazy[4 * MAX];

void build(int id, int l, int r)
{
    if(l == r){
            tree[id] = 0;
            return;
    }

    int mid = (l + r)/2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    //printf("%d -> %d %d\n", id, 2 * id, 2 * id + 1);
    tree[id] = tree[2 * id] + tree[2 * id + 1] ;
}

void update(int id, int l, int r, int x, int y, int value)
{
    if(l>y || r<x) return;
    if(l>=x && r<=y){

            lazy[id] = value;
            tree[id] = lazy[id] * (r - l + 1);

            return;
    }

    if(lazy[id] != -1){
            //tree[id]  = lazy[id] * (r - l + 1);

            if(l != r){
                    lazy[2 * id] = lazy[id];
                    lazy[2 * id + 1] = lazy[id];

                    int m = (l + r)/2;
                    tree[2 * id] = (m - l + 1) * lazy[id];
                    tree[2 * id + 1] = (r - m) * lazy[id];
            }

            lazy[id] = -1;
    }

    int mid = (l + r)/2;
    update(2 * id, l, mid, x, y, value);
    update(2 * id + 1, mid + 1, r, x, y, value);

    tree[id] = tree[2 * id] + tree[2 * id + 1] ;
}

int query(int id, int l, int r, int x, int y)
{
    if(l>y || r<x) return 0;
    if(l>=x && r<=y){

            //printf("%d %d: %d\n", l, r, lazy[id] * (r - l + 1));
            return tree[id];// + lazy[id] * (r - l + 1);
    }

    if(lazy[id] != -1){
            //tree[id]  = lazy[id] * (r - l + 1);

            if(l != r){
                    lazy[2 * id] = lazy[id];
                    lazy[2 * id + 1] = lazy[id];

                    int m = (l + r)/2;
                    tree[2 * id] = (m - l + 1) * lazy[id];
                    tree[2 * id + 1] = (r - m) * lazy[id];
            }

            lazy[id] = -1;
    }

    int mid = (l + r)/2;
    int a = query(2 * id, l, mid, x, y);
    int b = query(2 * id + 1, mid + 1, r, x, y);

    //printf("%d %d: %d %d\n", l, r, a, b);
    //tree[id]  = tree[2 * id]  + tree[2 * id + 1] ;
    return a + b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);

    si(t);
    while(t--){

            sii(n, q);
            //build(1, 0, n-1);
            MEM(tree, 0);
            MEM(lazy, -1);
            printf("Case %d:\n", ++caseno);
            FOR(i, 0, q){

                    si(m);
                    if(m == 1){

                            siii(a, b, v);
                            update(1, 0, n-1, a, b, v);
                    }
                    else if(m == 2){
                            sii(a, b);
                            int tmp = query(1, 0, n-1, a, b);
                            int divisor = (b - a + 1);
                            while(__gcd(tmp, divisor) != 1){

                                    int ex = __gcd(tmp, divisor);
                                    tmp /= ex;
                                    divisor /= ex;
                            }
                            if(divisor == 1) printf("%d\n", tmp);
                            else if(tmp == 0) puts("0");
                            else printf("%d/%d\n", tmp, divisor);

                            //printf("%d\n", tmp);

                    }
                    /*FOR(i, 1, 26){
                                printf("Lazy %d: %d\n", i, lazy[i]);
                                //printf("Tree %d: %d\n", i, tree[i].numOfElements);
                    }*/

            }
    }


    return 0;
}
