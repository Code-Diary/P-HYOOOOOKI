#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> arr;

	int m = moves.size();
	int n = board.size();
	int cnt = 0;


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[j][moves[i] - 1] != 0)
			{
				if (arr.empty())
				{
					arr.push(board[j][moves[i] - 1]);
                }
				else if (arr.top() == board[j][moves[i] - 1])
				{
					arr.pop();
					cnt++;
				}
				else
				{
					arr.push(board[j][moves[i] - 1]);
				}
                board[j][moves[i] - 1] = 0;
                break;
			}
		}
	}

	answer = cnt * 2;

	return answer;
}