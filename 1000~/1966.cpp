#include <iostream>
#include <queue>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>>q;
		priority_queue<int>pq;
		for (int i = 0;i < n;i++) {
			int x;
			cin >> x;
			pq.push(x);
			q.push({ i,x });
		}
		int ans = 0;
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (val == pq.top()) {
				pq.pop();
				ans++;
				if (idx == m) {
					cout << ans << '\n';
					break;
				}
			}
			else {
				q.push({ idx,val });
			}
		}
	}
}
