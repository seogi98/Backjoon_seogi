
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int get_min(int a, int b) { return a < b ? a : b;}

int main() {

    int t, a, b, i, j, k, n;
    vector<pair<int, int> > v;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        v.clear();

        for (j = 0; j < n; j++) {
            scanf("%d %d", &a, &b);
            v.push_back(make_pair(a, b));
        }

        sort(v.begin(), v.end(), comp);
        int cnt = n;
        int bound = v[0].second;

        for (k = 1; k < n; k++) {
            if (v[k].second > bound) cnt--;
            bound = get_min(bound, v[k].second);
        }

        printf("%d\n", cnt);
    }

    return 0;
}
