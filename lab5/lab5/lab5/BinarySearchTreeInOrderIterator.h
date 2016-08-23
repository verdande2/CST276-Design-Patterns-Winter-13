#pragma once

#include <stack>
using std::stack;

template <class T>
class BinarySearchTree;

template <class T>
class BinarySearchTreeNode;

template <class T>
class BinarySearchTreeInOrderIterator
{
public:
	BinarySearchTreeInOrderIterator(const BinarySearchTree<T>& tree, BinarySearchTreeNode<T> &start_node);
	BinarySearchTreeInOrderIterator(const BinarySearchTreeInOrderIterator<T> &copy);
	~BinarySearchTreeInOrderIterator();
	
	BinarySearchTreeInOrderIterator<T>& operator=(const BinarySearchTreeInOrderIterator<T> &rhs);
	BinarySearchTreeInOrderIterator<T> operator++(); // post
	BinarySearchTreeInOrderIterator<T> operator++(int); // pre
	const T & operator*() const;

	bool Done() const;

	void Reset();

private:
	BinarySearchTreeInOrderIterator();

	void Next();

	const BinarySearchTree<T>* m_tree;

	stack<BinarySearchTreeNode<T>*> m_nodesToVisit;
};

//template <class T>
//BinarySearchTreeInOrderIterator<T>::BinarySearchTreeInOrderIterator()
//	: m_tree(nullptr)
//{
//	
//}

template <class T>
BinarySearchTreeInOrderIterator<T>::BinarySearchTreeInOrderIterator(const BinarySearchTree<T> &tree, BinarySearchTreeNode<T> &start_node)
	: m_tree(&tree),
	m_nodesToVisit()
{
	m_nodesToVisit.push(&start_node);
}

template <class T>
BinarySearchTreeInOrderIterator<T>::BinarySearchTreeInOrderIterator(const BinarySearchTreeInOrderIterator<T> &copy)
{
	*this = copy; // DRY, use assignment operator
}

template <class T>
BinarySearchTreeInOrderIterator<T>::~BinarySearchTreeInOrderIterator()
{
	
}

template <class T>
BinarySearchTreeInOrderIterator<T>& BinarySearchTreeInOrderIterator<T>::operator=(const BinarySearchTreeInOrderIterator<T> &rhs)
{
	m_tree = rhs.m_tree;
	m_nodesToVisit = rhs.m_nodesToVisit;

	return *this;
}

template <class T>
BinarySearchTreeInOrderIterator<T> BinarySearchTreeInOrderIterator<T>::operator++(int)
{
	Next();
	return *this;
}

template <class T>
BinarySearchTreeInOrderIterator<T> BinarySearchTreeInOrderIterator<T>::operator++()
{
	BinarySearchTreeInOrderIterator<T> temp(*this);
	Next();
	return temp;
}

template <class T>
const T & BinarySearchTreeInOrderIterator<T>::operator*() const
{
	return m_nodesToVisit.top()->GetData();
}

template <class T>
bool BinarySearchTreeInOrderIterator<T>::Done() const
{
	return m_nodesToVisit.empty();
}

template <class T>
void BinarySearchTreeInOrderIterator<T>::Next()
{
	if(m_nodesToVisit.empty())
	{
		throw Exception("Can't access next element. End of tree.");
	}

	BinarySearchTreeNode<T>* node = m_nodesToVisit.top();
	m_nodesToVisit.pop();

	if(node->m_right != nullptr)
	{
		for(BinarySearchTreeNode<T>* ptr = node->m_right; ptr != nullptr; ptr = ptr->m_left)
		{
			m_nodesToVisit.push(ptr);
		}
	}
}

template <class T>
void BinarySearchTreeInOrderIterator<T>::Reset()
{
	// clear the stack
	while(!m_nodesToVisit.empty())
	{
		m_nodesToVisit.pop();
	}

	m_nodesToVisit.push(m_tree->m_root);
}