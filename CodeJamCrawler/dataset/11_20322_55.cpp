#include <iostream>

using namespace std;

char colors[101];
int positions[101];
int n;

int NextIndex(int curIndex, char color)
{
	if(curIndex == -1) return -1;
	for(int j = curIndex + 1; j <= n; ++ j)
	{
		if(colors[j] == color) return j;
	}
	return -1;
}

void Move(int curIndex, int& curPos, char color, int move)
{
	int nextIndex = NextIndex(curIndex, color);
	if(nextIndex == -1) return;
	int t = abs(curPos - positions[nextIndex]);
	if(t <= move)
	{
		curPos = positions[nextIndex];
	}
	else
	{
		if(curPos < positions[nextIndex])
		{
			curPos += move;
		}
		else 
		{
			curPos -= move;
		}
	}
}

int main()
{
	//	freopen("A-small-attempt0.in", "rb", stdin);
		freopen("A.out", "wb", stdout);
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++ tt)
	{
		cin >> n;
		for(int i = 1; i <= n; ++ i)
		{
			cin >> colors[i] >> positions[i];
		}
		int curIndexB = 0;
		int curIndexO = 0;
		int curPosB = 1;
		int curPosO = 1;

		int nextB = NextIndex(curIndexB, 'B');
		int nextO = NextIndex(curIndexO, 'O');
		int ans = 0;
		while(nextO != -1 || nextB != -1)
		{
			if(nextO == -1)
			{
				ans += 1 + abs(positions[nextB] - curPosB);
				curPosB = positions[nextB];
				curIndexB = nextB;
			}
			else if(nextB == -1)
			{
				ans += 1 + abs(positions[nextO] - curPosO);
				curPosO = positions[nextO];
				curIndexO = nextO;
			}
			else
			{
				if(nextB < nextO)
				{
					int move = abs(positions[nextB] - curPosB) + 1;
					ans += move;
					curPosB = positions[nextB];
					curIndexB = nextB;
					Move(curIndexO, curPosO, 'O', move);
				}
				else
				{
					int move = abs(positions[nextO] - curPosO) + 1;
					ans += move;
					curPosO = positions[nextO];
					curIndexO = nextO;
					Move(curIndexB, curPosB, 'B', move);
				}
			}
			nextB = NextIndex(curIndexB, 'B');
			nextO = NextIndex(curIndexO, 'O');
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}