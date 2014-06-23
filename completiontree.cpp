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

}

bool CTree::insert(std::string str, QuadraticHashTable< std::string > * w)
{
    int i;
    CTreeNode * temp = root;

    for(i = 0; i < str.length() && temp->children[str[i] - 'a']; i++)
	temp = temp->children[str[i] - 'a'];

    if(i == str.length())
	return false;
    if(str[0] == 'a' && str[1] == 'b')
        std::cout << str << " " << temp << std::endl;

    for( i ; i < str.length(); i++)
    {
	if(str[0] == 'a' && str[1] == 'b')
	    std::cout << str << " and " << i << std::endl;
	temp->children[i] = new CTreeNode();

	if(w->find(str.substr(0,i)) != "")
	    temp->isWord = true;

	temp = temp->children[i];

    }

    return true;

} // insert

bool CTree::hasCompletions(std::string str)
{
    int i;
    CTreeNode * temp = root;

    for(i = 0; i < str.length(); i++)
	temp = temp->children[str[i] - 'a'];

    for(i = 0; (!(temp->children[i])) && i < 26; i++);

    return i < 26;

}


void CTree::comp()
{

    std::string temp;
    CTreeNode * ptr = root;
    int i;

    std::cout << "\nEnter a string\n>> ";

    std::cin >> temp;

    std::cout << ptr->children[temp[0] - 'a'] << std::endl;

    if(!(hasCompletions(temp)))
    {   
	std::cout << "This string has no completions.\n";
	return;
    }   
    else
    {   
	for(i = 0; i < temp.length(); i++)
	    ptr = ptr->children[temp[i] - 'a'];

        for(i = 0; i < 26; i++)
	{
	    if(ptr->children[i])
		ptr->children[i]->findCompletions(temp);
	}
    }
}



CTreeNode::CTreeNode()
{
    isWord = false;

    for(int i = 0; i < 27; i++)
	children[i] = NULL;

} // CTreeNode constructor

void CTreeNode::findCompletions(std::string str)
{
    int i;

    std::cout << "findComp, string = " << str <<  std::endl;

    if(isWord)
	std::cout << str << std::endl;

    for(i = 0; i < 26; i++)
    {
	if(children[i])
	    findCompletions(str + (char)('a' + i));
    }

}

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
