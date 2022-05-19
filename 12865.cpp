#include <iostream>
#include <algorithm>
using namespace std;
int weight[101][2];
int dp[101][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		//0 무게 1 이익
		cin >> weight[i][0] >> weight[i][1];
	}
	for (int i = 1;i <= n ;i++) {
		int wei = weight[i][0];
		int val = weight[i][1];
		for (int j = 1;j <= k;j++) {
			if (wei<=j) {
				dp[i][j] = max(dp[i - 1][j], val + dp[i - 1][j - wei]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][k];
}