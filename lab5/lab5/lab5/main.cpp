#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <time.h>
#include <stdlib.h>

#include "BinarySearchTree.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(0));

	vector<int> v;

	for(int i = 0; i < 20; ++i)
	{
		v.push_back(rand() % 100);
	}

	for(auto i = v.begin(); i != v.end(); ++i)
	{
		cout << *i << " "; 
	}
	cout << endl;
	system("pause");
	system("cls");
	
	BinarySearchTree<int> tree;

	for(int i = 0; i < 10; ++i)
	{
		int j = rand() % 100;
		cout << "Inserting " << j << endl;
		tree.Insert(rand() % 100 + 1);
	}

	cout << "PreOrder Iterator:" << endl;
	for(auto i = tree.PreOrderIterator(); !i.Done(); i++)
	{
		cout << *i << " "; 
	}
	cout << endl;

	cout << "InOrder Iterator:" << endl;
	for(auto i = tree.InOrderIterator(); !i.Done(); i++)
	{
		cout << *i << " "; 
	}
	cout << endl;

	cout << "PostOrder Iterator: " << endl;
	for(auto i = tree.PostOrderIterator(); !i.Done(); i++)
	{
		cout << *i << " "; 
	}
	cout << endl;

	system("pause");
	return 0;
}