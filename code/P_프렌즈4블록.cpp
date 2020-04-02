include <string>
#include <vector>
#include<iostream>

using namespace std;



int solution(int m, int n, vector<string> board) {
	int answer = 0;

	vector<vector<int>> visit(m, vector<int>(n, 0));
	string temp;
	char jum = ' ';
	int cnt = 0;

	bool chk = true;

	while (1)
	{
		if (chk == false)
			break;

		chk = false;

		for (int i = 0; i < m - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] != jum)
					if (board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j + 1])
					{
						visit[i][j] = 1;
						visit[i + 1][j] = 1;
						visit[i][j + 1] = 1;
						visit[i + 1][j + 1] = 1;
					}
			}
		}

		for (int i = 0; i < m; i++)
		{
			temp = "";
			for (int j = 0; j < n; j++)
			{
				if (visit[i][j] == 1)
				{
					temp += " ";
					cnt++;
					chk = true;
					visit[i][j] = 0;
				}
				else
				{
					temp += board[i][j];
				}
			}
			board[i] = temp;
		}

		if(chk==true)
			for (int i = 0; i < n; i++)
			{
				for (int j = m-1; 1 < j; j--)
				{
					int t = j;
					while (board[j][i] == ' ' && 0<t)
					{
						board[j][i] = board[t - 1][i];
						board[t - 1][i] = ' ';
						t--;
					}
				}
			}


	}
	answer = cnt;

	return answer;
}