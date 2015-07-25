#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <queue>
#include <memory.h>
#include <iostream>
#include <stack>
#include <complex>
#include <list>


using namespace std;

void ASS(bool b) {
    if (!b) {
        ++*(int*)0;// crash
    }
}

typedef vector<int> vi;
typedef long long LL;

#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)


int posOfLast[(int)2e6]; // = {-1, -1 ....};

const int n = 6;
int a[n] = {1, 2, 3, 4, 1, 2};
int cnt[n];

struct Q {
    int id;
    int L, R;
};

vector<Q> qq[n];

vector<int> ans;

void AddQ(int L, int R) {
    Q q;
    q.L = L;
    q.R = R;

    q.id = (int)ans.size();
    ans.push_back(0);

    qq[R].push_back(q);
}


int main()
{
    memset(posOfLast, 0xFF, sizeof(posOfLast)); // = {-1, -1 ....};

    AddQ(1, 1);
    AddQ(1, 5);
    AddQ(2, 5);
    AddQ(0, 4);

    for (int j = 0; j < n; ++j)
        printf("%d ", a[j]);
    printf("\n");

    for (int i = 0; i < n; ++i) {
        if (posOfLast[a[i]] != -1)
            cnt[posOfLast[a[i]]]--;
        posOfLast[a[i]] = i;
        cnt[posOfLast[a[i]]]++;

        printf("i = %d\ncnt = {", i);
        for (int j = 0; j < n; ++j)
            printf("%d ", cnt[j]);
        printf("// ");

        for (int query = 0; query < (int)qq[i].size(); ++query) {
            Q q = qq[i][query];
            ASS(q.R == i); // always true;
            int sum = 0;

            for (int j = q.L; j <= q.R; j++)
                sum += cnt[j];
            ans[q.id] = sum;
            printf("answer for [%d, %d] is %d; ", q.L, q.R, ans[q.id]);
        }
        printf("\n");
    }

    return 0;
}
