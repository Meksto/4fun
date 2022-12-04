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
		tail = nullptr;
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
	void insert(T data, const int index);
	void removeAt(const int index);
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
void List2<T>::insert(T data, const int index)
{
	if (index > size - 1) { throw exception("You are out of range"); }
	if (index == 0) { push_front(data); return; }
	if (index == size - 1) { push_back(data); return; }

	if (index > size / 2)
	{
		int counter = size-1;
		Node<T>* prevElem = tail;
		Node<T>* nextElem = tail;
		while (counter != index-1) // находим предыдущий элемент от заданного
		{
			prevElem = prevElem->pprev;
			counter--;
		}
		nextElem = prevElem->pnext;
		prevElem->pnext = new Node<T>(data, prevElem->pnext, nextElem->pprev);
		nextElem->pprev = prevElem->pnext;

		size++;
		return;

	}
	Node<T>* prevElem = head;
	Node<T>* nextElem = head;
	int counter = 0;
	while (counter != index-1)
	{
		prevElem = prevElem->pnext;
		counter++;
	}
	nextElem = prevElem->pnext;
	prevElem->pnext = new Node<T>(data, prevElem->pnext, nextElem->pprev);
	nextElem->pprev = prevElem->pnext;

	size++;
	return;

}

template<typename T>
void List2<T>::removeAt(const int index)
{
	if (index > size - 1) { throw exception("You are out of range"); }
	if (index == 0) { pop_front(); return; }
	if (index == size - 1) { pop_back(); return; }

	if (index > size/2)
	{
		int counter = size - 1;
		Node<T>* prevElem = tail;
		Node<T>* nextElem = tail;
		Node<T>* toDel = nullptr;
		while (counter != index - 1) // находим предыдущий элемент от заданного
		{
			prevElem = prevElem->pprev;
			counter--;
		}
		toDel = prevElem->pnext;
		nextElem = toDel->pnext;
		prevElem->pnext = nextElem;
		nextElem->pprev = prevElem;
		delete toDel;
		size--;
		return;

	}
	Node<T>* prevElem = head;
	Node<T>* nextElem = head;
	Node<T>* toDel = nullptr;
	int counter = 0;
	while (counter != index - 1)
	{
		prevElem = prevElem->pnext;
		counter++;
	}
	toDel = prevElem->pnext;
	nextElem = toDel->pnext;
	prevElem->pnext = nextElem;
	nextElem->pprev = prevElem;
	delete toDel;
	size--;
	return;
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
	lst.push_back(11);
	lst.push_back(12);
	lst.push_back(13);
	lst.push_back(14);
	lst.push_back(15);
	lst.push_back(16);
	lst.push_back(17);
	lst.push_back(18);

	lst.getList();

	lst.removeAt(1);
	lst.getList();
	lst.removeAt(5);
	lst.getList();
	lst.removeAt(1);
	lst.getList();
	



}

