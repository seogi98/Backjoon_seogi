#include <bits/stdc++.h>

typedef long long ll;
#define pii pair<int, int>
using namespace std;
const int INF = 987654321;

bool check(int r, int c, int n) { return !(r < 0 || r >= n || c < 0 || c >= n); };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(n));
	for (auto &x : board)
		for (auto &e : x)
			cin >> e;
	auto get_shapes = [&]() {
		set<set<pii>> shapes;
		unordered_set<size_t> memo;
		memo.reserve(50148);
		auto make_shape = [&](auto &&self, int r, int c, set<pii> selected) -> void {
			selected.insert({r, c});
			auto f = *selected.begin();
			if (f != make_pair(0, 0))
			{
				set<pii> nsel;
				for (auto &cd : selected)
				{
					nsel.insert({cd.first - f.first, cd.second - f.second});
				}
				selected = nsel;
			}
			// memoization
			auto hf = [](auto const &cont) {
				size_t seed = cont.size();
				for (auto &i : cont)
				{
					seed ^= i.first + 0x9e3779b9 + (seed << 6) + (seed >> 2);
					seed ^= i.second + 0x9e3779b9 + (seed << 6) + (seed >> 2);
				}
				return seed;
			};
			auto sel_hash = hf(selected);
			if (memo.count(sel_hash))
				return;
			else
				memo.insert(sel_hash);
			if (selected.size() == m)
			{
				shapes.insert(selected);
				return;
			}
			int nc, nr;
			for (auto &h : selected)
			{
				nr = h.first + 1, nc = h.second;
				if (!selected.count({nr, nc}))
					self(self, nr, nc, selected);
				nr = h.first - 1, nc = h.second;
				if (!selected.count({nr, nc}))
					self(self, nr, nc, selected);
				nr = h.first, nc = h.second - 1;
				if (!selected.count({nr, nc}))
					self(self, nr, nc, selected);
				nr = h.first, nc = h.second + 1;
				if (!selected.count({nr, nc}))
					self(self, nr, nc, selected);
			}
			selected.erase({r, c});
		};
		make_shape(make_shape, 0, 0, *new set<pii>());
		return shapes;
	};
	auto shapes = get_shapes();
	vector<vector<pii>> shapes_vec;
	shapes_vec.reserve(shapes.size());
	for (auto &shape : shapes)
	{
		shapes_vec.emplace_back(shape.begin(), shape.end());
	}
	int ans = 0;
	for (auto &s : shapes_vec)
	{
		int minr = INF, maxr = 0, minc = INF, maxc = 0;
		for (auto &cd : s)
		{
			minr = min(minr, cd.first);
			maxr = max(maxr, cd.first);
			minc = min(minc, cd.second);
			maxc = max(maxc, cd.second);
		}
		int sizer = maxr - minr;
		int sizec = maxc - minc;
		for (auto &cd : s)
		{
			cd.first -= minr;
			cd.second -= minc;
		}
		for (int row = 0; row < n - sizer; ++row)
		{
			for (int col = 0; col < n - sizec; ++col)
			{
				int sum = 0;
				for (const auto &cd : s)
				{
					if (!check(row + cd.first, col + cd.second, n))
						break;
					sum += board[row + cd.first][col + cd.second];
				}
				ans = max(ans, sum);
			}
		}
	}
	cout << ans;
	return 0;
}