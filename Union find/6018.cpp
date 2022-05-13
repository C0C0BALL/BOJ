#include <iostream>
using namespace std;

int arr[1001];

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
		cout << "Y" << '\n';
		return;
	}
	cout << "N" << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1;i <= n;i++) {
		arr[i] = i;
	}
	int x, y;
	for (int i = 0;i < a;i++) {
		cin >> x >> y;
		merge(x, y);
	}
	for (int i = 0;i < b;i++) {
		cin >> x >> y;
		check(x, y);
	}
}