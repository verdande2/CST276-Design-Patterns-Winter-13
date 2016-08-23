#pragma once

#include <stack>
using std::stack;

template <class T>
class BinarySearchTree;

template <class T>
class BinarySearchTreeNode;

template <class T>
class BinarySearchTreePreOrderIterator
{
public:
	BinarySearchTreePreOrderIterator(const BinarySearchTree<T>& tree, BinarySearchTreeNode<T> &start_node);
	BinarySearchTreePreOrderIterator(const BinarySearchTreePreOrderIterator<T> &copy);
	~BinarySearchTreePreOrderIterator();
	
	BinarySearchTreePreOrderIterator<T>& operator=(const BinarySearchTreePreOrderIterator<T> &rhs);
	BinarySearchTreePreOrderIterator<T> operator++(); // post
	BinarySearchTreePreOrderIterator<T> operator++(int); // pre
	const T & operator*() const;

	bool Done() const;

	void Reset();

private:
	BinarySearchTreePreOrderIterator();

	void Next();

	const BinarySearchTree<T>* m_tree;

	stack<BinarySearchTreeNode<T>*> m_nodesToVisit;
};

//template <class T>
//BinarySearchTreePreOrderIterator<T>::BinarySearchTreePreOrderIterator()
//	: m_tree(nullptr)
//{
//	
//}

template <class T>
BinarySearchTreePreOrderIterator<T>::BinarySearchTreePreOrderIterator(const BinarySearchTree<T> &tree, BinarySearchTreeNode<T> &start_node)
	: m_tree(&tree),
	m_nodesToVisit()
{
	m_nodesToVisit.push(&start_node);
}

template <class T>
BinarySearchTreePreOrderIterator<T>::BinarySearchTreePreOrderIterator(const BinarySearchTreePreOrderIterator<T> &copy)
{
	*this = copy; // DRY, use assignment operator
}

template <class T>
BinarySearchTreePreOrderIterator<T>::~BinarySearchTreePreOrderIterator()
{
	
}

template <class T>
BinarySearchTreePreOrderIterator<T>& BinarySearchTreePreOrderIterator<T>::operator=(const BinarySearchTreePreOrderIterator<T> &rhs)
{
	m_tree = rhs.m_tree;
	m_nodesToVisit = rhs.m_nodesToVisit;

	return *this;
}

template <class T>
BinarySearchTreePreOrderIterator<T> BinarySearchTreePreOrderIterator<T>::operator++(int)
{
	Next();
	return *this;
}

template <class T>
BinarySearchTreePreOrderIterator<T> BinarySearchTreePreOrderIterator<T>::operator++()
{
	BinarySearchTreePreOrderIterator<T> temp(*this);
	Next();
	return temp;
}

template <class T>
const T & BinarySearchTreePreOrderIterator<T>::operator*() const
{
	return m_nodesToVisit.top()->GetData();
}

template <class T>
bool BinarySearchTreePreOrderIterator<T>::Done() const
{
	return m_nodesToVisit.empty();
}

template <class T>
void BinarySearchTreePreOrderIterator<T>::Next()
{
	if(m_nodesToVisit.empty())
	{
		throw Exception("Can't access next element. End of tree.");
	}

	BinarySearchTreeNode<T>* node = m_nodesToVisit.top();
	m_nodesToVisit.pop();

	if(node->m_right != nullptr)
	{
		m_nodesToVisit.push(node->m_right);
	}

	if(node->m_left != nullptr)
	{
		m_nodesToVisit.push(node->m_left);
	}
	
}

template <class T>
void BinarySearchTreePreOrderIterator<T>::Reset()
{
	// clear the stack
	while(!m_nodesToVisit.empty())
	{
		m_nodesToVisit.pop();
	}

	m_nodesToVisit.push(m_tree->m_root);
}