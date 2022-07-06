#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100001
#define INF 123456789

int n, k;
int visited[MAX], arrival[MAX];
vector<pair<int, int>>v;

void bfs(int a, int k) {
	fill(arrival, arrival + MAX, INF);
	queue<pair<int, int>>q;
	q.push(make_pair(a, 0));
	while (!q.empty()) {
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == k) {
			cout << cnt << '\n';
			int count = 1;
			while (!q.empty()) {
				if (q.front().first == k && q.front().second == cnt) count++;
				q.pop();
			}
			cout << count << "\n";
			return;
		}
		if (num - 1 >= 0 && !visited[num - 1]) {
			if (cnt + 1 <= arrival[num - 1]) {
				arrival[num - 1] = cnt + 1;
				q.push(make_pair(num - 1, cnt + 1));
			}
		}
		if (num + 1 < MAX && !visited[num + 1]) {
			if (cnt + 1 <= arrival[num + 1]) {
				arrival[num + 1] = cnt + 1;
				q.push(make_pair(num + 1, cnt + 1));
			}
		}
		if (num * 2 < MAX && !visited[num * 2]) {
			if (cnt + 1 <= arrival[num * 2]) {
				arrival[num * 2] = cnt + 1;
				q.push(make_pair(num * 2, cnt + 1));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	bfs(n, k);
}
