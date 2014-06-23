#ifndef COMPLETIONTREE_H
#define COMPLETIONTREE_H

class CTreeNode
{
    public:
	CTreeNode();

	void del(CTreeNode * child);

	int numCompletions;
	CTreeNode * children[27];
	CTreeNode * parent;

};

class CTree
{

    public:
	CTree();
	~CTree();

	CTreeNode * root;
};

#endif
