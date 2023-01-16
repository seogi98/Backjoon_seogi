#include <iostream>

using namespace std;

int N, M;
int arr[5001];
bool chk[100000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		chk[arr[i]] = true;
	}

	bool isOk = chk[M];
	if (!isOk) {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (arr[i] + arr[j] == M) {
					isOk = true;
					break;
				}
				else if (arr[i] + arr[j] < M) {
					int diff = M - (arr[i] + arr[j]);
					if (chk[diff] && diff != arr[i] && diff != arr[j]) {
						isOk = true;
						break;
					}
				}
			}
			if (isOk) break;
		}
	}
	cout << isOk << '\n';

	return 0;
}