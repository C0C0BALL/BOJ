#include <iostream>
#define INF 123456789
using namespace std;

int arr[501][501];

int main() {
	int n, m;
	cin >> n >> m;
	fill(&arr[0][0], &arr[500][501], INF);
	while (m--) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		int count = 0;
		for (int j = 1;j <= n;j++) {
			if (arr[i][j] == 1 || arr[j][i] == 1) count++;
		}
		if (count == n - 1) ans++;
	}
	cout << ans;
}
