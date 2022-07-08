#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = 123456789;
	}
	for (int i = 1; i * i <= n; i++) {
		for (int j = i * i; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
	}
	cout << dp[n];
}
