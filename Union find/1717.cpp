#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

int getParent(int idx) {
	if (arr[idx] == idx) return idx;
	return arr[idx] = getParent(arr[idx]);
}
void unionParent(int a, int b) {
	int na = getParent(a);
	int nb = getParent(b);
	if (na < nb) arr[nb] = na;
	else arr[na] = nb;
}
void findParent(int a, int b) {
	int na = getParent(a);
	int nb = getParent(b);
	if (na == nb) {
		cout << "YES\n";
		return;
	}
	else {
		cout << "NO\n";
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		arr[i] = i;
	}
	for (int i = 0;i < m;i++) {
		int tmp, x, y;
		cin >> tmp;
		if (tmp == 0) {
			cin >> x >> y;
			unionParent(x, y);
		}
		else if (tmp == 1) {
			cin >> x >> y;
			findParent(x, y);
		}
	}
}