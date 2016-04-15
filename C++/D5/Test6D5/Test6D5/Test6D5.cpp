#include <iostream>
using namespace std;


class Node
{
	friend class LinkedList;
public:
	Node(void *pData = NULL):m_pPre(NULL),m_pNext(NULL),m_pData(pData)
	{
	}
private:
	Node *m_pPre;
	Node *m_pNext;
	void *m_pData;

};
class LinkedList
{
public:
	LinkedList():m_pTop(NULL), m_pBottom(NULL),m_iNodeCount(0)
	{
	}
	 ~LinkedList()
	 {
		 while(DeleteTop());
	 }
	bool InsertBefore(void *pData,Node *pCurrent=NULL)
	{
		Node * pNode = new Node(pData);
		if(m_pTop ==NULL)
		{
			m_pTop = m_pBottom= pNode;
		}
		else if(pCurrent ==m_pTop)
		{
			pCurrent->m_pPre = pNode;
			pNode->m_pNext = pCurrent;
			m_pTop=pNode;
		}
		else if(pCurrent ==NULL)
		{
			pNode->m_pPre=m_pBottom;
			m_pBottom->m_pNext = pNode;
			m_pBottom = pNode;
		}
		else
		{
			pNode->m_pPre = pCurrent ->m_pPre;
			pNode->m_pNext = pCurrent;
			pCurrent->m_pPre->m_pNext = pNode;
			pCurrent->m_pPre=pNode;
		}
		++m_iNodeCount;
		return true;
	}
	bool InsertTop(void *pData)
	{
		return InsertBefore(pData,m_pTop);
	}
	bool InsertBottom(void *pData)
	{
		return InsertBefore(pData,NULL);
	}
	bool DeleteAt(Node * pCurrent)
	{
		if(m_pTop ==NULL || pCurrent ==NULL)
			return false;
		if(m_pTop ==pCurrent && m_pBottom ==pCurrent)
		{
			m_pTop = m_pBottom =NULL;
		}
		else if ( m_pTop == pCurrent)
		{
			m_pTop = m_pTop->m_pNext;
			m_pTop->m_pPre = NULL;
		}
		else if ( m_pBottom == pCurrent)
		{
			m_pBottom = m_pBottom->m_pPre;
			m_pBottom ->m_pNext = NULL;
		}
		else
		{
			pCurrent->m_pPre->m_pNext = pCurrent->m_pNext;
			pCurrent->m_pNext->m_pPre = pCurrent->m_pPre;
		}
		delete pCurrent;
		--m_iNodeCount;
		return true;
	}
	bool DeleteTop()
	{
		return DeleteAt(m_pTop);
	}
	bool DeleteBottom()
	{
		return DeleteAt(m_pBottom);
	}
	int GetNodeCount() const
	{
		return m_iNodeCount;
	}
	Node *GetTop()
	{
		return m_pTop;
	}
	Node *GetBottom()
	{
		return m_pBottom;
	}
	void *GetNext(Node *& pStart)
	{
		if(pStart ==NULL)
			return NULL;
		void *pData = pStart->m_pData;
		pStart = pStart->m_pNext;
		return pData;
	}
	void *GetPre(Node *&pStart)
	{
		if(pStart ==NULL)
			return NULL;
		void *pData = pStart->m_pData;
		pStart = pStart->m_pPre;
		return pData;
	}
	void *GetAt(Node *pStart)
	{
		if(pStart ==NULL)
			return NULL;
		return pStart->m_pData;
	}
private:
	Node *m_pTop;
	Node *m_pBottom;
	int m_iNodeCount;
	
};
class Stack
{
private:
	LinkedList m_List;
public:
	bool Push(void *pData)
	{
		return m_List.InsertTop(pData);
	}
	bool Pop(void * & pData)
	{
		if(m_List.GetNodeCount()==0)
			return false;
		Node * pStart = m_List.GetTop();
		pData= m_List.GetAt(pStart);
		m_List.DeleteTop();
		return true;
	}
	bool Peek(void * pData)
	{
		if(m_List.GetNodeCount()==0)
			return false;
		Node * pStart = m_List.GetTop();
		pData= m_List.GetAt(pStart);
		//m_List.DeleteTop();
		return true;
	}
};
class Queue
{
private:
	LinkedList m_List;
public:
	bool enQueue(void *pData)
	{
		return m_List.InsertTop(pData);
	}
	bool deQueue(void * & pData)
	{
		if(m_List.GetNodeCount()==0)
			return false;
		Node * pStart = m_List.GetBottom();
		pData= m_List.GetAt(pStart);
		m_List.DeleteBottom();
		return true;
	}
	bool Peek(void * pData)
	{
		if(m_List.GetNodeCount()==0)
			return false;
		Node * pStart = m_List.GetBottom();
		pData= m_List.GetAt(pStart);
		//m_List.DeleteTop();
		return true;
	}
};
void main() //generic programming
{
	//LinkedList list;
	/*Stack s;

	for(int i=0; i <10; ++i)
	{
	list.InsertBefore((void*)i);
	}
	Node *pStart = list.GetTop();
	while(pStart)
	{
	void * pData = list.GetNext(pStart);
	cout<<(int)pData <<endl;
	}*/

	Stack s;
	for(int i = 0; i<10; ++i)
	{
		s.Push((void *)i);
	}
	void *pData;

	while(s.Pop(pData))
	{
		cout<<(int)pData<<endl;
	}

	Queue q;
	for(int i= 0;i<10;++i)
	{
		q.enQueue((void *)i);
	}
	
	while (q.deQueue(pData))
	{
		cout<<(int)pData<<endl;
	}
}