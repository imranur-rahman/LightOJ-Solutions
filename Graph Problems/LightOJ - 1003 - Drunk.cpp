#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair
#define ll long long
#define FOR(i, n) for(int i=0; i<(int)n; ++i)
#define MEM(array, value) memset(array, value, sizeof(array))

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}

const int MAX = 10000 + 1;
const ll MAXINT = 1e18;

enum{WHITE, BLACK, GRAY};
bool hasCycle = false;
map<string, int>imap;
vi ar[MAX];
int visited[MAX];
vi topSortedArray;
set<int>topSortedSet;


int t, caseno = 0, flag = 0, m, kid1, kid2;
string a, b;


int dfs(int n)
{
    if(visited[n] == GRAY) {

        hasCycle = true;
        return 0;
    }

    else if(visited[n] == WHITE){

        visited[n] = GRAY;

        for(vi::const_iterator it = ar[n].begin(); it != ar[n].end(); ++it){

            dfs(*it);
        }

        visited[n] = BLACK;

        //topSortedArray.pb(n);
        if(!topSortedSet.count(n))
            topSortedSet.insert(n);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){

        imap.clear();
        topSortedArray.clear();
        topSortedSet.clear();
        FOR(i, MAX)
            ar[i].clear();
        MEM(visited, WHITE);

        cin >> m;
        flag = 0;
        hasCycle = false;
        while(m--){

            cin >> a >> b;

            if(!imap.count(a))
                imap[a] = ++flag;
            kid1 = imap[a];

            if(!imap.count(b))
                imap[b] = ++flag;
            kid2 = imap[b];

            ar[kid2].pb(kid1);

        }

        for(map<string, int>::const_iterator it = imap.begin(); it != imap.end(); ++it){

            //topSortedArray.clear();
            //MEM(visited, WHITE);
            //if((int)topSortedSet.size() == (int)imap.size()  or  hasCycle) break;
            if(visited[it -> second] == WHITE){

                //if(hasCycle) hasCycle = false;


                dfs(it -> second);
            }

        }

        if(!hasCycle)
            cout << "Case " << ++caseno << ": Yes" << endl;
        else
            cout << "Case " << ++caseno << ": No" << endl;
    }

    return 0;
}
