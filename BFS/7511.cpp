#include <iostream>
using namespace std;

int arr[1000001];

int findParent(int idx) {
	if (arr[idx] == idx) return idx;
	return arr[idx] = findParent(arr[idx]);
}

void merge(int a, int b) {
	int na = findParent(a);
	int nb = findParent(b);
	if (na < nb) arr[nb] = na;
	else arr[na] = nb;
}

void check(int a, int b) {
	int na = findParent(a);
	int nb = findParent(b);
	if (na == nb) {
		cout << 1 << '\n';
		return;
	}
	cout << 0 << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	for(int i=0;i<tc;i++) {
		int n, k;
		cin >> n >> k;
		for (int j = 0;j < n;j++) {
			arr[j] = j;
		}
		for (int j = 0;j < k;j++) {
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		cout << "Scenario " << i + 1 << ":\n";
		int m;
		cin >> m;
		for (int j = 0;j < m;j++) {
			int x, y;
			cin >> x >> y;
			check(x, y);
		}
		cout << '\n';
	}
}
