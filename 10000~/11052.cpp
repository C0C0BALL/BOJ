#include <iostream>
#include <algorithm>
using namespace std;

int price[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> price[i];
		dp[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = max(dp[j], dp[j - i] + price[i]);
		}
	}
	cout << dp[n];
}
