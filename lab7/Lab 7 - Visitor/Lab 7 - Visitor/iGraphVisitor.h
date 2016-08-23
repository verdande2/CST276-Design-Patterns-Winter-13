#pragma once

#include "GraphNode.h"

template <class DataType, class DescType, class WeightType>
class iGraphVisitor
{
public:
	virtual bool VisitNode(GraphNode<DataType, DescType, WeightType> &node) = 0;
private:
};