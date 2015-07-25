#include<bits/stdc++.h>
using namespace std;

char grid[500][500];
int visited[500][500];
int result[500][500];
int m, n, q, flag = 0;
map<pair<int,int>, int>mp;
set<pair<int,int> >s;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x, int y)
{
    if(x>=0 and x<m and y>=0 and y<n  and  grid[x][y] != '#'  and  !visited[x][y]){

            if(grid[x][y] == 'C'){

                    flag++;
            }

            visited[x][y] = 1;

            for(int j=0; j<4; j++){
                dfs(x+dx[j], y+dy[j]);
            }
            s.insert(make_pair(x, y));

            //mp[make_pair(x, y)] = flag;

    }
}

int main()
{
    int t, caseno = 0;
    cin >> t;
    while(t--){

            cin >> m >> n >> q;

            memset(grid, '\0', sizeof(grid));
            memset(visited, 0, sizeof(visited));
            memset(result, 0, sizeof(result));
            mp.clear();

            getchar();
            for(int i=0; i<m; i++){

                    for(int j=0; j<n; j++)
                        grid[i][j] = getchar();

                    getchar();
            }

            printf("Case %d:\n", ++caseno);

            int x, y;
            for (int i=0; i<q; i++){


                scanf("%d%d", &x, &y);

                if(result[x-1][y-1] == 0){
                //if(!mp.count(make_pair(x-1, y-1))){

                    flag = 0;
                    dfs(x-1, y-1);

                    //for(set<pair<int,int> >:: iterator it = s.begin(); it != s.end(); ++it)
                        //mp[make_pair(it -> first, it -> second)] = flag;
                    for(set<pair<int,int> >::iterator it = s.begin(); it != s.end(); ++it)
                        result[it -> first][it -> second] = flag;
                    s.clear();

                    printf("%d\n", flag);
                }

                else{
                    printf("%d\n", result[x-1][y-1]);
                    //printf("%d\n", mp[make_pair(x-1, y-1)]);
                }
            }

    }
    return 0;
}
