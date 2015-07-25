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

int t, n, m, caseno = 0, a, b, c, d;

int ar[MAX];
ll tree[4*MAX];
ll lazy[4*MAX];

void build_tree(int node, int a, int b)
{
    //if(a > b) return;
    if(a == b){
        tree[node] = ar[a];
        return;
    }

    build_tree(2*node, a, (a+b)/2);
    build_tree(2*node+1, (a+b)/2 + 1, b);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void update_tree(int node, int a, int b, int i, int j, int value)
{
    if(a>j  or  b<i) return;

    if(a>=i  and  b<=j){ // je range e amar update korte hobe seta purapuri ekhonkar range er moddhe ache, so ar tree vangte hobe na
        lazy[node] += value;
        return;
    }

    update_tree(2*node, a, (a+b)/2, i, j, value);
    update_tree(2*node + 1,(a+b)/2 + 1, b, i, j, value);

    tree[node] += value*(imin(j,b) - imax(i,a) + 1);// amar je range e update korte hobe shudhu sei range er value update er jonno imin, imax use kora lagbe
}

ll query_tree(int node, int a, int b, int i, int j)
{
    if(a>j or b<i) return 0;

    if(lazy[node] != 0){ // ei lazy ke venge dicchi, karon eita amar query er range er moddhe ache
        tree[node] += lazy[node]*(b-a+1);

        if(a != b){
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(a>=i  and  b<=j) // purapuri query er range e
        return tree[node];

    return query_tree(2*node, a, (a+b)/2, i, j) + query_tree(2*node + 1, (a+b)/2 + 1, b, i, j);
}

void print(int a[])
{
    FOR(i, 0, n+1)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    ios_base::sync_with_stdio(false);

    si(t);
    while(t--){
        sii(n,m);
        //FOR(i, 0, n)
            //ar[i] = 0;
        //build_tree(1, 0, n-1);
        MEM(tree, 0);
        MEM(lazy, 0);
        printf("Case %d:\n", ++caseno);
        while(m--){
            si(a);
            if(a == 0){
                siii(b,c,d);
                update_tree(1, 0, n-1, b, c, d);
            }
            else if(a == 1){
                sii(b,c);
                printf("%lld\n", query_tree(1, 0, n-1, b, c));
            }
            //print(tree);
            //print(lazy);
        }
    }
    return 0;
}

