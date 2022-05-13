#include <iostream>
#include <queue>
using namespace std;

int n, m;
int visited[1001][1001];
int field[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>>q;

void bfs() {
   while (!q.empty()) {
      int nx = q.front().first;
      int ny = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
         int newx = nx + dx[i];
         int newy = ny + dy[i];
         if (newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
         if (visited[newx][newy] == 1) continue;
         if (field[newx][newy] == 0) {
            q.push({ newx,newy });
            visited[newx][newy] = 1;
            field[newx][newy] = field[nx][ny] + 1;
         }
      }
   }
}

int main() {
   cin >> m >> n;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> field[i][j];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (field[i][j] == 1) q.push({i, j});
      }
   }
   bfs();
   int result = 0;
   bool flag = false;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (field[i][j] == 0) flag = true;
         if (field[i][j] > result) result = field[i][j];
      }
   }
   if (flag) cout << -1;
   else cout << result - 1;
}