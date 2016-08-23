/************************************************************************
* Class: GraphNode
*
* Purpose: This class is essentially a node structure with a constructor 
*	bolted on. It is treated in the same way a struct would be (public 
*	members and no member functions), but opted to be a class for better 
*	constructor management. It holds a bit of data and a list of adjacent edges.
*
* Manager functions:	
* 	GraphNode()
*	GraphNode(const GraphNode &)
*	~GraphNode()
*	operator=()
*
* Methods:
*	None.
*	
*************************************************************************/
#pragma once

#include <list>
using std::list;
#include "GraphEdge.h"
#include "iGraphVisitor.h"

template <class DataType, class DescType, class WeightType>
class iGraphVisitor;

template <class DataType, class DescType, class WeightType>
class GraphNode
{
public:
	template <class DataType, class DescType, class WeightType> friend class Graph;
	template <class DataType, class DescType, class WeightType> friend class UndirectedGraph;

	DataType m_data;
	list<GraphEdge<DataType, DescType, WeightType>> m_edges;
	
	DataType GetData() const;

	GraphNode();
	GraphNode(DataType const& data);
	GraphNode(GraphNode<DataType, DescType, WeightType> const& copy);
	~GraphNode();

	GraphNode<DataType, DescType, WeightType> const& operator=(const GraphNode<DataType, DescType, WeightType> &rhs);
	
	void Accept(iGraphVisitor<DataType, DescType, WeightType>* visitor);
};

template <class DataType, class DescType, class WeightType>
GraphNode<DataType, DescType, WeightType>::GraphNode()
	: m_data(DataType())
{
	
}

template <class DataType, class DescType, class WeightType>
GraphNode<DataType, DescType, WeightType>::GraphNode(DataType const& data)
	: m_data(data)
{
	
}

template <class DataType, class DescType, class WeightType>
GraphNode<DataType, DescType, WeightType>::GraphNode(GraphNode<DataType, DescType, WeightType> const& copy)
{
	*this = copy;
}

template <class DataType, class DescType, class WeightType>
GraphNode<DataType, DescType, WeightType>::~GraphNode()
{
	m_data = DataType();
	m_edges.clear();
}

template <class DataType, class DescType, class WeightType>
GraphNode<DataType, DescType, WeightType> const& GraphNode<DataType, DescType, WeightType>::operator=(GraphNode<DataType, DescType, WeightType> const& rhs)
{
	if(this != &rhs)
	{
		m_data = rhs.m_data;

		for(list<GraphEdge<DataType, DescType, WeightType>>::iterator i = m_edges.begin(); i != m_edges.end(); ++i)
		{
			m_edges.push_back(*i);
		}
	}
	return *this;
}

template <class DataType, class DescType, class WeightType>
void GraphNode<DataType, DescType, WeightType>::Accept(iGraphVisitor<DataType, DescType, WeightType>* visitor)
{
	if(visitor->VisitNode(*this))
	{
		for(auto i = m_edges.begin(); i != m_edges.end(); i++)
		{
			(*i).GetDestination()->Accept(visitor);
		} 
	}
}

template <class DataType, class DescType, class WeightType>
DataType GraphNode<DataType, DescType, WeightType>::GetData() const
{
	return m_data;
}