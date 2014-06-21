// Author: Ari Bolton
// Started 6/19/14

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "QuadraticProbing.h"
#include "QueueAr.h"

using namespace std;

void init(ifstream * dict, QuadraticHashTable< string > * ht)
{
    string word, prev;
    bool ins;
    int i, n = 0;

    (*dict) >> prev;

    while((*dict) >> word)
    {
	ins = true;
	n++;

	if(isupper(prev[0]))
	{
	    prev[0] = tolower(prev[0]);

	    if(prev == word)
		ins = false;

	    for(i = 1; i < prev.length(); i++)
	    {
		if(prev[i] == '-')
		    ins = false;
	    }

	}
	
	if(ins)
	    ht->insert(prev);

	prev = word;
    }

    ht->insert(word);

    //cout << n << endl;
}

void instructions()
{

    cout << "0. Exit\n"
         << "1. Substitute letters\n"
	 << ">> ";

}

void testperm(string inp, int index, int places[5], int numQ, QuadraticHashTable< string > * w,
	      Queue< string > * q);

void substitute(QuadraticHashTable< string > * w)
{
    string entry;
    int places[5], numQ = 0, i;
    Queue< string > queue(8);

    cout << "\nUse \"?\" or \"_\" to represent unknown letters.\n>> ";

    cin >> entry;

    for(i = 0; i < entry.length(); i++)
    {
	if(entry[i] == '_')
	    entry[i] = '?';
    }

    cout << "\nPossible replacements:\n\n";

    for(i = 0; i < entry.length(); i++)
    {
	if(entry[i] == '?')
	    places[ numQ++ ] = i;
    }

    testperm(entry, 0, places, numQ, w, &queue);

    while(queue.currentSize > 0)
	cout << queue.dequeue() << "    ";

    cout << endl << endl;
}

void testperm(string inp, int index, int places[5], int numQ, QuadraticHashTable< string > * w,
	      Queue< string > * q)
{
    int i;
    string curr = inp;

    if(index == numQ) // word is completed
    {
	string temp = w->find(inp);

	//if(temp != "")
	//    cout << temp << endl;

	if(temp!= "")
	    q->enqueue(temp);

	if(q->currentSize == 8)
	{
	    for(i = 0; i < 8; i++)
		cout << q->dequeue() << "    ";

	    cout << endl;
	}
    }
    else // compute more perms
    {
	int qplace = places[ index ];

	curr[ qplace ] = 'a' - 1;

        for(i = 0; i < 26; i++)
        {

	    curr[ qplace ]++;

	    testperm(curr, index + 1, places, numQ, w, q); 

        }
    }

}

int main()
{
    ifstream dictionary("words");
    string nf;
    int choice;
    QuadraticHashTable< string > hashTable(nf, 600000);

    init(&dictionary, &hashTable);

    do
    {

	instructions();

	cin >> choice;

	switch(choice)
	{
	    case 0: 
		    break;
	    case 1: 
		    substitute(&hashTable);
		    break;
	    default:
		    break;

	}

    } while (choice > 0);

    return 0;
}
