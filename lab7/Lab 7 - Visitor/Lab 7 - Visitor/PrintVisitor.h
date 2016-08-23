#pragma once

#include "iGraphVisitor.h"

#include <set>
using std::set;

#include <vector>
using std::vector;

template <class DataType, class DescType, class WeightType>
class PrintVisitor : public iGraphVisitor<DataType, DescType, WeightType>
{
public:
	PrintVisitor(Graph<DataType, DescType, WeightType>& graph);
	bool VisitNode(GraphNode<DataType, DescType, WeightType> &node);

	void DisplayPath() const;
private:
	vector<GraphNode<DataType, DescType, WeightType>*> m_visitedNodes;

	set<DataType> m_nodesNotYetVisited;

	Graph<DataType, DescType, WeightType>& m_graph;
};

template <class DataType, class DescType, class WeightType>
PrintVisitor<DataType, DescType, WeightType>::PrintVisitor(Graph<DataType, DescType, WeightType>& graph)
	: m_graph(graph)
{
	vector<DataType> listOfNodes = m_graph.GetListOfNodes();
	for(auto i = listOfNodes.begin(); i != listOfNodes.end(); i++)
	{
		m_nodesNotYetVisited.insert(*i);
	}
}

template <class DataType, class DescType, class WeightType>
bool PrintVisitor<DataType, DescType, WeightType>::VisitNode(GraphNode<DataType, DescType, WeightType> &node)
{
	if(m_nodesNotYetVisited.empty() && m_visitedNodes.front() == m_visitedNodes.back())
	{
		return false; // if our goal is done, we can cease visiting more nodes
	}

	
	
	bool alreadyVisited = find(m_visitedNodes.begin(), m_visitedNodes.end(), &node) != m_visitedNodes.end();
	
	// add the current node to the ordered vector of nodes
	m_visitedNodes.push_back(&node);

	
	
	if( alreadyVisited )
	{
		return false; // already visited
	}
	else
	{
		// remove the node from the list of unvisited nodes
		auto i = find(m_nodesNotYetVisited.begin(), m_nodesNotYetVisited.end(), node.GetData());
		m_nodesNotYetVisited.erase(i);
	}

	

	
	

	// do stuff here (the actual visiting code)
	cout << "Currently visiting node '" << node.GetData() << "' (Address: " << &node << ")." << endl;
	
	

	if(m_visitedNodes.front() == &node)
	{
		// the node we're currently visiting is the same one we started with (ie. closed path)
		// we're only done if we've visited all the nodes in the graph, so check that now.
		// stuff here
		cout << "FULL CIRCLE" << endl;
	}
	

	return true;
}

template <class DataType, class DescType, class WeightType>
void PrintVisitor<DataType, DescType, WeightType>::DisplayPath() const
{
	for(auto it = m_visitedNodes.begin(); it != m_visitedNodes.end(); it++)
	{
		//cout << (*it)->GetData() << endl;
	}
	//return;

	auto i = m_visitedNodes.begin();
	auto j = m_visitedNodes.begin();
	j++;

	cout << "Starting at '" << (*i)->GetData() << "'." << endl;
	while(j != m_visitedNodes.end())
	{
		GraphEdge<DataType, DescType, WeightType>* edge = m_graph.FindEdge((*i)->GetData(), (*j)->GetData());
		cout << edge << endl;
		//cout << "Taking '" << m_graph.GetDescription((*i)->GetData(), (*j)->GetData()) << "' to '" << (*j)->GetData() << "'." << endl;
		
		i++;
		j++;
	}
}