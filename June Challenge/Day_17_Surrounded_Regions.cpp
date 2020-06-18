/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/


class Solution {
public:
	void floodFill(int i, int j, bool visited[1000][1000], vector<vector<char>> board, int n, int m) {
		if (i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false) {
			cout << "Tushar\n";
			visited[i][j] = true;
			if (i - 1 >= 0 && board[i - 1][j] == 'O') {
				floodFill(i - 1, j, visited, board, n, m);
			}
			if (i + 1 < n && board[i + 1][j] == 'O') {
				floodFill(i + 1, j, visited, board, n, m);
			}
			if (j - 1 >= 0 && board[i][j - 1] == 'O') {
				floodFill(i, j - 1, visited, board, n, m);
			}
			if (j + 1 < m && board[i][j + 1] == 'O') {
				floodFill(i, j + 1, visited, board, n, m);
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0) {
			return;
		}
		int m = board[0].size();
		bool visited[1000][1000];
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && visited[i][j] == false && board[i][j] == 'O') {
					floodFill(i, j, visited, board, n, m);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'O' && visited[i][j] == false) {
					board[i][j] = 'X';
				}
			}
		}
	}
};