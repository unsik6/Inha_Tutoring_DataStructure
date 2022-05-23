// 백준 2667번 단지번호 붙이기

// input: 한 변의 길이 (5 <= N <= 25)
//		  각 칸의 정보 (0 또는 1)
// 
// condition: 상하좌우로 연결되어 있는 집을 하나의 단지로 친다.
//			  단지의 개수와, 각 단지의 크기를 구하여라. 각 단지의 크기는 오름차순으로 정렬

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int countingGroupOfHouseBFS(bool** _houses, int _size, int _startHouseRow, int _startHouseCol)
{
	queue<int> lvlList;
	// the number of house = row * _size + col
	lvlList.push(_startHouseRow * _size + _startHouseCol);
	_houses[_startHouseRow][_startHouseCol] = false;

	int cnt = 0;
	while (!lvlList.empty())
	{
		int cur = lvlList.front();
		int curCol = cur % _size;
		int curRow = (cur - curCol) / _size;
		cnt++;
		lvlList.pop();
		if (curRow > 0)
		{
			if (_houses[curRow - 1][curCol])
			{
				_houses[curRow - 1][curCol] = false;
				lvlList.push((curRow - 1) * _size + curCol);
			}
		}
		if (curRow < _size - 1)
		{
			if (_houses[curRow + 1][curCol])
			{
				_houses[curRow + 1][curCol] = false;
				lvlList.push((curRow + 1) * _size + curCol);
			}
		}
		if (curCol > 0)
		{
			if (_houses[curRow][curCol - 1])
			{
				_houses[curRow][curCol - 1] = false;
				lvlList.push(curRow * _size + (curCol - 1));
			}
		}
		if (curCol < _size - 1)
		{
			if (_houses[curRow][curCol + 1])
			{
				_houses[curRow][curCol + 1] = false;
				lvlList.push(curRow * _size + (curCol + 1));
			}
		}
	}

	return cnt;
}

int main()
{
	int N;
	cin >> N;
	// data
	bool** houses = new bool*[N];
	for (int i = 0; i < N; i++)
		houses[i] = new bool[N] {false};
	
	for (int i = 0; i < N; i++)
	{
		string inputLine;
		cin >> inputLine;
		cin.ignore();
		for (int f = 0; f < N; f++)
		{
			bool parse = (inputLine[f] == '1' ? true : false);
			houses[i][f] = parse;
		}
	}

	int groupCnt = 0;
	int* eachGroupCnt = new int[N * N];
	for (int i = 0; i < N; i++)
	{
		for (int f = 0; f < N; f++)
		{
			if (houses[i][f])
			{
				eachGroupCnt[groupCnt++] = countingGroupOfHouseBFS(houses, N, i, f);
			}
		}
	}

	cout << groupCnt << '\n';
	sort(eachGroupCnt, eachGroupCnt + groupCnt);
	for (int i = 0; i < groupCnt; i++) cout << eachGroupCnt[i] << '\n';


	for (int i = 0; i < N; i++)
		delete[] houses[i];
	delete[] houses;
	delete[] eachGroupCnt;
}