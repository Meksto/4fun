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

	T& operator[](const int index);
	void pop_front();
	void pop_back();
	void clear();

	void push_back(T data);
	void push_front(T data);
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
T& List2<T>::operator[](const int index)
{
	if (index > size-1) { throw exception("You are out of range"); }

	if (index > size/2)
	{
		Node<T>* elem = tail;
		int counter = size-1;
		while (counter != index)
		{
			elem = elem->pprev;
			counter--;
		}
		return elem->data;
	}
	Node<T>* elem = head;
	int counter = 0;
	while (counter != index)
	{
		elem = elem->pnext;
		counter++;
	}
	return elem->data;
	// TODO: вставьте здесь оператор return
}

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
void List2<T>::pop_back()
{
	if (head != tail)
	{
		Node<T>* toDel = tail;
		tail = tail->pprev;
		tail->pnext = nullptr;
		delete toDel;
		size--;
		return;
	}
	delete tail;
	head = tail = nullptr;
	size--;
	return;

	
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
void List2<T>::push_front(T data)
{
	if (head == nullptr)
	{
		tail = head = new Node<T>(data);
		size++;
		return;
		
	}
	Node<T> *obj = head;
	head = new Node<T>(data, head);
	obj->pprev = head;
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
	lst.push_back(40);
	lst.push_back(30);
	lst.getList();


	try
	{
		cout << "Element is - " << lst[2] << endl;
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	



}

