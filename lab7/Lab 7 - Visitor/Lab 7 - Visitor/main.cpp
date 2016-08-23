#include <iostream>
using std::cout;
using std::endl;

#include <exception>
using std::exception;

#include <string>
using std::string;

#include "PrintVisitor.h"
//#include "VisitorFriendlyGraph.h"

#include "UndirectedGraph.h"

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC


void split(const string& str, const string& delim, vector<string>& parts);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	const char* inputFilePath = "lab7.txt";

	UndirectedGraph<> graph;
	
	// first, we deal with the file input, and toss all the data into the graph
	ifstream input(inputFilePath);

	if(!input.is_open())
	{
		// file isn't open, throw stl exception
		throw exception("File failed to open.");
	}

	unsigned lineCount = 0;

	string buffer;
	vector<string> parts;
	while(!input.eof())
	{
		// read the whole line into the buffer
		getline(input, buffer);
		
		if(buffer != "") // make sure the line isn't blank...
		{
			++lineCount;
			
			// deal with the contents of the buffer, by splitting it, and then inputting it into the graph
			split(buffer, ",", parts);

			// now, parts has elements in this order: source, destination, description, weight
			// so force insert each of those edges into the graph
			cout << "Inserting Edge from " << parts[0] << " to " << parts[1] << " called '" << parts[2] << "' (length: " << atoi(parts[3].c_str()) << "mi)" << endl;
			graph.ForceInsertEdge(parts[0], parts[1], parts[2], atoi(parts[3].c_str()));
			
			parts.clear(); // remove contents of parts
		}
	}
	cout << "Read in " << lineCount << " records." << endl;

	system("pause");
	system("cls");

	cout << "Sending visitor to each node of the graph..." << endl;
	PrintVisitor<string, string, unsigned> visitor(graph);
	graph.Accept(&visitor);

	system("pause");
	system("cls");
	visitor.DisplayPath();

	system("pause");
	return 0;
}

/**********************************************************************	
* Purpose: Splits a string into a vector of strings, based on a delimiter
*
* Entry: str can be any string
*		 delim can be any string
*		 parts is a vector of strings (assumed to be empty when func called)
*
* Exit: parts now contains str broken up into substrings, based on delim
*
************************************************************************/
// used from SO user tgamblin from: http://stackoverflow.com/questions/289347/using-strtok-with-a-string-argument-instead-of-char
// NOTE: Not my code, copied from StackOverflow, licensed under CC http://creativecommons.org/licenses/by-sa/3.0/
// with attribution required, I felt it simpler to use pre-existing code than to reinvent the wheel, even though this is a simple func
// Also, why is this not part of the STL?
void split(const string& str, const string& delim, vector<string>& parts) {
	size_t start, end = 0;
	while (end < str.size()) {
		start = end;
		while (start < str.size() && (delim.find(str[start]) != string::npos)) {
			start++;  // skip initial whitespace
		}
		end = start;
		while (end < str.size() && (delim.find(str[end]) == string::npos)) {
			end++; // skip to end of word
		}
		if (end-start != 0) {  // just ignore zero-length strings.
			parts.push_back(string(str, start, end-start));
		}
	}
}