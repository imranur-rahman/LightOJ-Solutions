#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii >
#define pb push_back
#define mp make_pair
#define ll long long
#define FOR(i, n) for(int i=0; i<(int)n; ++i)

template <class T> inline T imax(T a,T b){return (a>b)?a:b;}

const int MAX = 100 + 1;
const ll MAXINT = 1e18;

vector<vector<pair<int, int> > > ar(MAX);
vector<ll>dist(MAX, MAXINT); // ei 2D array te <weight, adjacent node> evabe rakha ache
vector<int>parent(MAX, 0);

void dijkstra(int st)
{
    set<pii>s;

    dist[st] = 0;
    s.insert(pii(0, st)); // set er moddhe <weight, node> evabe rakhchi

    while(!s.empty()){

            pii top = *s.begin(); // begin(), end() egula function iterator return kore
            //int weight = top.first;
            int father = top.second;
            s.erase(s.begin());

            for(vpii::const_iterator it = ar[father].begin(); it != ar[father].end(); ++it){

                    ll cost = it -> first;
                    int child = it -> second;

                    //int maxi = imax(dist[father], cost);

                    if(dist[father] + cost < dist[child]){

                            if(dist[child] != MAXINT){

                                    s.erase(s.find(pii(dist[child], child))); // amar set er moddhe jodi <(MAXINT chara onno value), node> thake tahole oitar (MAXINT chara onno value) ke update korar jonno prothome muche porer line e addition korar por abar insert kora hoyeche
                            }

                            dist[child] = dist[father] + cost;
                            //parent[child] = father;
                            s.insert(pii(dist[child], child));
                    }
            }
    }

}

int main()
{
    //freopen("out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m, t ,caseno = 0, u, v, w;
    cin >> t;

    while(t--){

        cin >> n >> m;

        FOR(i, MAX)
            ar[i].clear();
        dist.assign(MAX, MAXINT);
        //parent.assign(MAX, 0);

        for(int i=0; i<m; i++){

            cin >> u >> v >> w;
            ar[u].pb(pii(w, v));
            ar[v].pb(pii(w, u));
        }

        /*int s;
        cin >> s;*/

        dijkstra(1);

        //printf("Case %d:\n", ++caseno);


        /*FOR(i, n){
            if(dist[i] != MAXINT)
                cout << dist[i] << endl;
            else
                cout << "Impossible" << endl;
        }*/

        if(dist[n] == MAXINT)
            cout << "Case " << ++caseno << ": Impossible" << endl;
        else
            cout << "Case " << ++caseno << ":" << dist[n] << endl;
    }

    return 0;
}

