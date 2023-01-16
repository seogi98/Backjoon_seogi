#include <cstdio>

int main() {
	while (1) {
        int n, k, a[1111] = { -1 }, p[1111] = { -1 };
		scanf("%d %d", &n, &k);
		if (!n && !k) break;

		int cnt = -1, idx = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] == k) idx = i;
			if (a[i] != a[i - 1] + 1) cnt++;
			p[i] = cnt;
		}

		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (p[i] != p[idx] && p[p[i]] == p[p[idx]]) ans++;

		printf("%d\n", ans);
	}

	return 0;
}