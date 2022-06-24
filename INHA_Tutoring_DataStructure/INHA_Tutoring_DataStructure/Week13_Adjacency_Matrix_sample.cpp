#include <iostream>
using namespace std;

class Vertex
{
private:
	int m_data;
	int m_degree;
	Vertex* m_prev;
	Vertex* m_next;

public:
	Vertex(int data = -1)
	{
		this->m_degree = 0;
		this->m_data = data;
		m_prev = m_next = nullptr;
	}
	~Vertex() {}

	int getData() { return m_data; }
	void setData(int data) { m_data = data; }
	int getDegree() { return m_degree; }
	void setDegree(int deg) { m_degree = deg; }
	Vertex* getPrev() { return m_prev; }
	void setPrev(Vertex* p) { m_prev = p; }
	Vertex* getNext() { return m_next; }
	void setNext(Vertex* p) { m_next = p; }

	void increaseDegree() { m_degree++; }
	void decreaseDegree() { m_degree--; }
};

class Edge
{
private:
	Edge* m_prev;
	Edge* m_next;
	Vertex* m_source;
	Vertex* m_destination;
	string m_data;

public:
	Edge(string data = "", Vertex* src = nullptr, Vertex* dst = nullptr)
	{
		m_prev = m_next = nullptr;
		m_source = src;
		m_destination = dst;
		m_data = data;
	}
	~Edge() {}

	string getData() { return m_data; }
	void setData(string d) { m_data = d; }
	Edge* getPrev() { return m_prev; }
	void setPrev(Edge* p) { m_prev = p; }
	Edge* getNext() { return m_next; }
	void setNext(Edge* p) { m_next = p; }
	Vertex* getSrc() { return m_source; }
	void setSrc(Vertex* p) { m_source = p; }
	Vertex* getDst() { return m_destination; }
	void setDst(Vertex* p) { m_destination = p; }
};

template<typename Node>
class DLinkedList
{
private:
	Node* m_header;
	Node* m_trailer;
	int m_size;
public:
	DLinkedList()
	{
		m_header = new Node();
		m_trailer = new Node();
		m_header->setNext(m_trailer);
		m_trailer->setPrev(m_header);
		m_size = 0;
	}
	~DLinkedList()
	{
		delete m_header;
		delete m_trailer;
	}

	Node* getHeader() { return m_header; }
	void setHeader(Node* n) { m_header = n; }
	Node* getTrailer() { return m_trailer; }
	void setTrailer(Node* n) { m_trailer = n; }
	int getSize() { return m_size; }

	void insert(Node* node)
	{
		if (m_header == nullptr)
		{
			m_header = node;
			m_trailer = node;
			return;
		}

		m_trailer->getPrev()->setNext(node);
		node->setPrev(m_trailer->getPrev());
		m_trailer->setPrev(node);
		node->setNext(m_trailer);
		m_size++;
	}

	void remove(Node* node)
	{
		if (m_header == nullptr)
			return;
		else
		{
			Node* temp = m_header;
			while (temp != m_trailer)
			{
				if (temp == node)
				{
					temp->getPrev()->setNext(temp->getNext());
					temp->getNext()->setPrev(temp->getPrev());
					delete temp;
					m_size--;
					return;
				}
				temp = temp->getNext();
			}
			// ÇØ´çÇÏ´Â ³ëµå°¡ ¾øÀ½.
		}
	}
};

#define MappingSize 501
class Graph
{
private:
	Edge*** m_edgeMatrix;
	DLinkedList<Vertex>* m_vertexList;
	DLinkedList<Edge>* m_edgeList;
	int m_vertexSize;
	int m_mappingTable[MappingSize];

public:
	Graph()
	{
		m_vertexList = new DLinkedList<Vertex>();
		m_edgeList = new DLinkedList<Edge>();
		m_vertexSize = 0;
		for (int i = 0; i < MappingSize; i++)
			m_mappingTable[i] = -1;
		m_edgeMatrix = new Edge * *[1];
		m_edgeMatrix[0] = new Edge * [1];
		m_edgeMatrix[0][0] = nullptr;
	}
	~Graph()
	{
	}

	bool isFindVertex(int n)
	{
		Vertex* temp = m_vertexList->getHeader()->getNext();
		while (temp != m_vertexList->getTrailer())
		{
			if (temp->getData() == n)
			{
				return true;
			}
			temp = temp->getNext();
		}
		return false;
	}

	Vertex* findVertex(int n)
	{
		Vertex* temp = m_vertexList->getHeader()->getNext();
		while (temp != m_vertexList->getTrailer())
		{
			if (temp->getData() == n)
			{
				return temp;
			}
			temp = temp->getNext();
		}
		return nullptr;
	}

	void insertVertex(int n)
	{
		if (isFindVertex(n) == true) return;

		Edge*** tempMatrix = new Edge * *[++m_vertexSize];
		for (int i = 0; i < m_vertexSize; i++)
		{
			tempMatrix[i] = new Edge * [m_vertexSize];
			for (int j = 0; j < m_vertexSize; j++)
			{
				tempMatrix[i][j] = nullptr;
			}
		}

		for (int i = 0; i < m_vertexSize - 1; i++)
		{
			for (int j = 0; j < m_vertexSize - 1; j++)
			{
				tempMatrix[i][j] = m_edgeMatrix[i][j];
			}
		}

		Edge*** origin = m_edgeMatrix;
		m_edgeMatrix = tempMatrix;

		for (int i = 0; i < m_vertexSize - 1; i++)
		{
			delete[] origin[i];
		}
		delete origin;

		Vertex* newVertex = new Vertex(n);
		m_vertexList->insert(newVertex);
		m_mappingTable[m_vertexSize - 1] = n;
	}

	void eraseVertex(int n)
	{
		if (isFindVertex(n) == false || m_vertexSize == 0)
		{
			cout << -1 << endl;
			return;
		}

		Edge*** tempMatrix = new Edge * *[--m_vertexSize];
		for (int i = 0; i < m_vertexSize; i++)
		{
			tempMatrix[i] = new Edge * [m_vertexSize];
			for (int j = 0; j < m_vertexSize; j++)
			{
				tempMatrix[i][j] = nullptr;
			}
		}

		int targetIdx = 0;
		for (int i = 0; i < m_vertexSize + 1; i++)
		{
			if (m_mappingTable[i] == n) targetIdx = i;
		}
		for (int i = targetIdx; i < m_vertexSize + 1; i++)
		{
			m_mappingTable[i] = m_mappingTable[i + 1];
		}
		for (int i = 0; i < m_vertexSize + 1; i++)
		{
			if (this->m_edgeMatrix[targetIdx][i] != nullptr)
			{
				m_edgeList->remove(this->m_edgeMatrix[targetIdx][i]);
			}
		}

		for (int i = 0; i < m_vertexSize + 1; i++)
		{
			for (int j = 0; j < m_vertexSize + 1; j++)
			{
				if (i < targetIdx && j < targetIdx)
				{
					tempMatrix[i][j] = m_edgeMatrix[i][j];
				}
				else if (i > targetIdx && j > targetIdx)
				{
					tempMatrix[i - 1][j - 1] = m_edgeMatrix[i][j];
				}
				else if (j > targetIdx)
				{
					tempMatrix[i][j - 1] = m_edgeMatrix[i][j];
				}
				else if (i > targetIdx)
				{
					tempMatrix[i - 1][j] = m_edgeMatrix[i][j];
				}
			}
		}

		Edge*** origin = m_edgeMatrix;
		m_edgeMatrix = tempMatrix;

		for (int i = 0; i < m_vertexSize + 1; i++)
		{
			delete[] origin[i];
		}
		delete origin;

		m_vertexList->remove(findVertex(n));

		cout << this->getEdgeSize() << ' ';
		this->printAllEdges();
	}

	void printAllEdges()
	{
		Edge* temp = m_edgeList->getHeader()->getNext();
		while (temp != m_edgeList->getTrailer())
		{
			cout << temp->getData() << ' ';
			temp = temp->getNext();
		}
		cout << endl;
	}

	void insertEdge(int src, int dst, string data = "")
	{
		if (isFindVertex(src) == false || isFindVertex(dst) == false)
		{
			cout << -1 << endl;
			return;
		}

		int destination = -1;
		int source = -1;
		for (int i = 0; i < m_vertexSize; i++)
		{
			if (m_mappingTable[i] == src) source = i;
			if (m_mappingTable[i] == dst) destination = i;
			if (destination != -1 && source != -1) break;
		}

		if (m_edgeMatrix[source][destination] != nullptr ||
			m_edgeMatrix[destination][source] != nullptr)
		{
			cout << -1 << endl;
			return;
		}

		Edge* newEdge = new Edge(data, findVertex(src), findVertex(dst));
		m_edgeMatrix[source][destination] = newEdge;
		m_edgeMatrix[destination][source] = newEdge;

		newEdge->getSrc()->increaseDegree();
		newEdge->getDst()->increaseDegree();

		m_edgeList->insert(newEdge);
	}

	void eraseEdge(int src, int dst)
	{
		int destination = -1;
		int source = -1;
		for (int i = 0; i < m_vertexSize; i++)
		{
			if (m_mappingTable[i] == src) source = i;
			if (m_mappingTable[i] == dst) destination = i;
			if (destination != -1 && source != -1) break;
		}

		if (m_edgeMatrix[source][destination] == nullptr ||
			m_edgeMatrix[destination][source] == nullptr)
		{
			return;
		}

		findVertex(src)->decreaseDegree();
		findVertex(dst)->decreaseDegree();

		Edge* targetEdge = m_edgeMatrix[source][destination];
		m_edgeList->remove(targetEdge);

		m_edgeMatrix[source][destination] = nullptr;
		m_edgeMatrix[destination][source] = nullptr;
	}

	int isAdjacentTo(int src, int dst)
	{
		if (isFindVertex(src) == false || isFindVertex(dst) == false)
		{
			return -1;
		}

		int source = -1;
		int destination = -1;
		for (int i = 0; i < m_vertexSize; i++)
		{
			if (m_mappingTable[i] == src) source = i;
			if (m_mappingTable[i] == dst) destination = i;
			if (source != -1 && destination != -1) break;
		}

		if (m_edgeMatrix[source][destination] != nullptr) return 1;
		else return 0;
	}

	int getVertexSize() { return m_vertexSize; }
	int getEdgeSize() { return m_edgeList->getSize(); }
};

int main()
{
	
}
