#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>

class Inhastagram
{
private:
	// ���� �׷����� ���� ����Ʈ�� ������ ����
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
		// 0�� ������� �ʾƼ� nullptr ó��
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