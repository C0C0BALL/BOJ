#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int arr[9];
	vector<int>v;
	int sum = 0;
	for (int i = 0;i < 9;i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 9;j++) {
			if (sum - arr[i] - arr[j] == 100) {
				for (int k = 0;k < 9;k++) {
					if (k != i && k != j) {
						cout << arr[k] << '\n';
					}
				}
				return 0;
			}
		}
	}
}