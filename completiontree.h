#ifndef COMPLETIONTREE_H
#define COMPLETIONTREE_H

#include <string>
#include "QuadraticProbing.h"

class CTreeNode
{
    public:
	CTreeNode();

	void del(CTreeNode * child);
	void findCompletions(std::string str);

	bool isWord;
	CTreeNode * children[27];
	CTreeNode * parent;

};

class CTree
{

    public:
	CTree();
	~CTree();
	
	bool hasCompletions(std::string str);
	bool insert(std::string str, QuadraticHashTable < std::string > * w);
	void comp();

    public:
	CTreeNode * root;
};

#endif
