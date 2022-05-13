#include <iostream>
#include <algorithm>
#include <vector>
#define INF 100000000
#define MAX 51

using namespace std;

int arr[MAX][MAX];

int main() {
	int n;
	cin >> n;
	int a, b;
	fill(&arr[0][0], &arr[MAX - 1][MAX], INF);
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		arr[a - 1][b - 1] = 1;
		arr[b - 1][a - 1] = 1;
	}


	for (int k = 0;k < n;k++) {
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (i == j || j == k || i == k)
					continue;
				else if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i == j) arr[i][j] = 0;
		}
	}
	vector<int>v;
	vector<int>vv;
	for (int i = 0;i < n;i++) {
		int max_ = 0;
		for (int j = 0;j < n;j++) {
			max_ = max(arr[i][j], max_);
		}
		v.push_back(max_);
	}
	int count = 0;
	int min_value = *min_element(v.begin(), v.end());
	for (int i = 0;i < v.size();i++) {
		if (v[i] == min_value) {
			count++;
			vv.push_back(i + 1);
		}
	}
	sort(vv.begin(), vv.end());
	cout << min_value << ' ' << count << '\n';
	for (int i = 0;i < vv.size();i++) {
		cout << vv[i] << ' ';
	}
}
