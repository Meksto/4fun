#include <iostream>
#include <string>
using namespace std;

template <typename T>
class List2
{
public:
	List2()
	{
		size = 0;
		head = nullptr;
	}
	~List2()
	{
		clear();
	}

	int getSize() { return size; }

	void pop_front();
	void clear();

	void push_back(T data);
	void getList();

private:

	template <typename T>
	class Node
	{
	public:
		Node(T data = T(), Node* pnext = nullptr, Node* pprev = nullptr)
		{
			this->pnext = pnext;
			this->pprev = pprev;
			this->data = data;
		}

		T data;
		Node* pnext;
		Node* pprev;
	};




	int size;
	Node<T>* head;
	Node<T>* tail;

};



template<typename T>
void List2<T>::pop_front()
{
	if (head->pnext != nullptr)
	{
		Node<T>* toDel = head;
		head = head->pnext;
		head->pprev = nullptr;
		delete toDel;
		size--;
		return;
	}
	Node<T>* toDel = head;
	head = head->pnext;
	delete toDel;
	size--; 
	
}

template<typename T>
void List2<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List2<T>::push_back(T data)
{
	if (head == nullptr)
	{
		tail = head = new Node<T>(data);
		
	}
	else
	{
		Node<T>* lastElem = head;
		while (lastElem->pnext != nullptr)
		{
			lastElem = lastElem->pnext;
		}
		lastElem->pnext = new Node<T>(data);
		tail = lastElem->pnext;
		tail->pprev = lastElem;

	}
	size++;
}

template<typename T>
void List2<T>::getList()
{
	cout << "Elenets in the List: " << getSize() << endl;
	Node<T>* elem = head;
	for (int i = 0; i < getSize(); i++)
	{
		cout << elem->data << endl;
		elem = elem->pnext;
	}
	cout << "======================" << endl;
}










int main()
{
	List2<int> lst;
	lst.push_back(50);
	lst.push_back(20);
	lst.push_back(10);
	lst.getList();
	lst.pop_front();
	lst.getList();
	lst.clear();
	lst.getList();
}

