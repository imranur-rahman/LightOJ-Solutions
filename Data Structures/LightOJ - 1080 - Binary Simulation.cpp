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
char str[MAX];
int ar[MAX];
int tree[MAX];

void update(int idx)
{
    while(idx <= n){
        tree[idx] ^= 1;
        idx += (idx & -idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx){

        sum ^= tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    char ch;

    while(t--){

        scanf("%s", str);
        n = strlen(str);
        MEM(tree, 0);

        FOR(i, 0, n)
            ar[i] = str[i] - '0';

        si(q);
        printf("Case %d:\n", ++caseno);

        while(q--){

            getchar();
            scanf("%c", &ch);

            switch(ch){
                case 'I': sii(a, b);
                          update(a), update(b+1);
                          break;

                case 'Q': si(a);
                          printf("%d\n", ar[a-1] ^ query(a));
                          break;

            }
        }
    }
    return 0;
}
