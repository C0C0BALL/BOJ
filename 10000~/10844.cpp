#include <iostream>
using namespace std;

long long arr[101][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++) {
		arr[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 < 0) arr[i][j] += arr[i - 1][j + 1] % 1000000000;
			else if (j + 1 > 9) arr[i][j] += arr[i - 1][j - 1] % 1000000000;
			else arr[i][j] += arr[i - 1][j - 1] + arr[i - 1][j + 1] % 1000000000;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += arr[n][i] % 1000000000;
	}
	cout << ans % 1000000000;
}
