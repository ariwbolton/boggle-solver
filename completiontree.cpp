#include "completiontree.h"
#include <iostream>

CTree::CTree()
{
    root = new CTreeNode();

    root->parent = NULL;

} // CTree constructor

CTree::~CTree()
{
    for(int i = 0; i < 26; i++)
    {
	if(root->children[i])
	    root->del(root->children[i]);
    }

    delete root;

}

CTreeNode::CTreeNode()
{
    numCompletions = 0;

    for(int i = 0; i < 27; i++)
	children[i] = NULL;

} // CTreeNode constructor

void CTreeNode::del(CTreeNode * child)
{
    for(int i = 0; i < 26; i++)
    {
	if(children[i])
	{
	    del(children[i]);
	    children[i] = NULL;
	}

    }

    delete this;

}
