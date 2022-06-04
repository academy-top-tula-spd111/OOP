#pragma once
#include <iostream>

template <class T>
class List
{
	template <class T>
	struct Node
	{
		T value;
		Node<T>* next = nullptr;
	};

	Node<T>* tail;
	int size;
public:
	List() : tail{ nullptr }, size{ 0 }{}

	List(const List& list)
	{
		std::cout << "constructor copy\n";

		Node<T>* nodeNew = new Node<T>;
		nodeNew->value = list.tail->value;
		tail = nodeNew;

		Node<T>* listCurr = list.tail->next;
		Node<T>* nodeCurr = tail;

		while (listCurr)
		{
			nodeNew = new Node<T>;
			nodeNew->value = listCurr->value;
			nodeCurr->next = nodeNew;
			nodeCurr = nodeNew;

			listCurr = listCurr->next;
		}
	}

	List(List&& list)
	{
		std::cout << "constructor move\n";

		tail = list.tail;
		size = list.size;
		list.tail = nullptr;
		list.size = 0;
	}

	~List()
	{
		Node<T>* nodeDel{ tail };
		while (tail)
		{
			tail = tail->next;
			delete nodeDel;
			nodeDel = tail;
		}
			
	}
	
	void Insert(int index, T value)
	{
		Node<T>* nodeNew = new Node<T>;
		nodeNew->value = value;

		if (index == 0)
		{
			if (tail)
			{
				Node<T>* head = tail;
				while (head->next)
					head = head->next;
				head->next = nodeNew;
			}
			else
				tail = nodeNew;
			size++;
			return;
		}
		if (index >= size)
		{
			nodeNew->next = tail;
			tail = nodeNew;
			size++;
			return;
		}
		Node<T>* nodeCurr = tail;
		for (int i = 0; i < size - index - 1; i++)
			nodeCurr = nodeCurr->next;
		nodeNew->next = nodeCurr->next;
		nodeCurr->next = nodeNew;
		size++;
	}

	T Remove(int index)
	{

	}

	int Size()
	{
		return this->size;
	}

	int Find(T value)
	{
		int position{ -1 };
		int index{ size - 1 };
		Node<T>* nodeCurr{ tail };
		while (nodeCurr)
		{
			if (nodeCurr->value == value)
				position = index;
			nodeCurr = nodeCurr->next;
			index--;
			/*if (position != -1)
				break;*/
		}
		return position;
	}

	T At(int index)
	{
		Node<T>* nodeCurr = tail;
		for (int i = 0; i < size - index - 1; i++)
			nodeCurr = nodeCurr->next;
		return nodeCurr->value;
	}

	T& operator[](int index)
	{
		Node<T>* nodeCurr = tail;
		for (int i = 0; i < size - index - 1; i++)
			nodeCurr = nodeCurr->next;
		return nodeCurr->value;
	}

	void Print()
	{
		Node<T>* nodeCurr = tail;
		while (nodeCurr)
		{
			std::cout << nodeCurr->value << " ";
			nodeCurr = nodeCurr->next;
		}
		std::cout << "\n";
	}
};

