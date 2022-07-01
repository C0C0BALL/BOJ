#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
#define INF 123456789
using namespace std;

int arr[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		fill(&arr[0][0], &arr[MAX - 1][MAX], INF);
		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			arr[a][b] = c;
			arr[b][a] = c;
		}
		for (int k = 1;k <= n;k++) {
			for (int i = 1;i <= n;i++) {
				for (int j = 1;j <= n;j++) {
					if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				if (i == j) arr[i][j] = 0;
			}
		}
		int k;
		cin >> k;
		vector<int>friends(k);
		vector<bool>location(n + 1);
		for (int i = 0;i < k;i++) {
			cin >> friends[i];
			location[friends[i]] = true;
		}
		int minv = 123456789;
		for (int i = 1;i <= n;i++) {
			int sum = 0;
			for (int j = 0;j < k;j++) {
				sum += arr[friends[j]][i];
			}
			minv = min(sum, minv);
		}
		for (int i = 1;i <= n;i++) {
			int sum = 0;
			for (int j = 0;j < k;j++) {
				sum += arr[friends[j]][i];
			}
			if (sum == minv) {
				cout << i << '\n';
				break;
			}
		}
	}
}
