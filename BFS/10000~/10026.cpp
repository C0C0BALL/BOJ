#include <iostream>
#include <algorithm>

#define MAX 100

using namespace std;

char graph[MAX][MAX];
bool visited[MAX][MAX];
bool visited_n[MAX][MAX];
int n;
int movex[4] = { -1,1,0,0 };
int movey[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	visited[x][y] = true;
	if (graph[x][y] == 'R' || graph[x][y] == 'G') {
		int mx, my;
		for (int i = 0;i < 4;i++) {
			mx = x + movex[i];
			my = y + movey[i];
			if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
			if ((graph[mx][my] == 'R' || graph[mx][my] == 'G') && visited[mx][my] == false) dfs(mx, my);
		}
	}

	else if (graph[x][y] == 'B') {
		int mx, my;
		for (int i = 0;i < 4;i++) {
			mx = x + movex[i];
			my = y + movey[i];
			if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
			if (graph[mx][my] == 'B' && visited[mx][my] == false) dfs(mx, my);
		}
	}
}

void dfs_n(int x, int y) {
	visited_n[x][y] = true;
	if (graph[x][y] == 'R') {
		int mx, my;
		for (int i = 0;i < 4;i++) {
			mx = x + movex[i];
			my = y + movey[i];
			if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
			if (graph[mx][my] == 'R' && visited_n[mx][my] == false) dfs_n(mx, my);
		}
	}

	else if (graph[x][y] == 'G') {
		int mx, my;
		for (int i = 0;i < 4;i++) {
			mx = x + movex[i];
			my = y + movey[i];
			if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
			if (graph[mx][my] == 'G' && visited_n[mx][my] == false) dfs_n(mx, my);
		}
	}

	else if (graph[x][y] == 'B') {
		int mx, my;
		for (int i = 0;i < 4;i++) {
			mx = x + movex[i];
			my = y + movey[i];
			if (mx < 0 || mx >= n || my < 0 || my >= n) continue;
			if (graph[mx][my] == 'B' && visited_n[mx][my] == false) dfs_n(mx, my);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	int count_n = 0;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if ((graph[i][j] == 'R' || graph[i][j] == 'G' || graph[i][j]=='B') && visited[i][j] == false) {
				dfs(i, j);
				count++;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if ((graph[i][j] == 'R' || graph[i][j] == 'G' || graph[i][j] == 'B') && visited_n[i][j] == false) {
				dfs_n(i, j);
				count_n++;
			}
		}
	}
	cout << count_n << " " << count;
}
