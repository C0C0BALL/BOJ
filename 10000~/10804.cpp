#include <iostream>
#include <vector>
using namespace std;

int main() {
	int arr[21];
	for (int i = 0;i < 21;i++) {
		arr[i] = i;
	}
	for (int i = 0;i < 10;i++) {
		int x, y;
		cin >> x >> y;
		vector<int>tmp;
		for (int i = y;i >= x;i--) {
			tmp.push_back(arr[i]);
		}
		for (int i = x;i <= y;i++) {
			arr[i] = tmp[i - x];
		}
	}
	for (int i = 1;i < 21;i++) {
		cout << arr[i] << ' ';
	}
}