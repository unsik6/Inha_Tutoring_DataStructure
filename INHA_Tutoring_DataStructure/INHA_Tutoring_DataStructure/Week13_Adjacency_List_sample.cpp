#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>

class Inhastagram
{
private:
	// 실제 그래프의 인접 리스트를 저장할 벡터
	std::vector<std::list<int>*> m_adjLists;

	void DFS(int _startV, bool* _visitedTable, std::stack<int>& _fStk)
	{
		_visitedTable[_startV] = true;
		for (int& adjV : *m_adjLists[_startV])
		{
			if (!_visitedTable[adjV])
			{
				_visitedTable[adjV] = true;
				DFS(adjV, _visitedTable, _fStk);
			}
		}
		std::cout << _startV << ' ';
		_fStk.push(_startV);
	}

public:
	Inhastagram(int _n = 2)
	{
		// 0은 사용하지 않아서 nullptr 처리
		m_adjLists.push_back(nullptr);

		for (int i = 0; i < _n; i++)
		{
			std::list<int>* adjacencyList = new std::list<int>();
			std::list<int>* tList = new std::list<int>();
			m_adjLists.push_back(adjacencyList);
		}
	}

	~Inhastagram()
	{
		for (int i = 1; i < (int)m_adjLists.size(); i++)
		{
			if (m_adjLists[i] != nullptr)
			{
				delete m_adjLists[i];
			}
		}
	}

	void insertEdge(int _srcV, int _dstV)
	{
		m_adjLists[_srcV]->push_back(_dstV);
	}
};