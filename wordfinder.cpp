// Author: Ari Bolton
// Started 6/19/14

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include "QuadraticProbing.h"
#include "QueueAr.h"
#include "substitution.h"

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

int main()
{
    ifstream dictionary("words");
    string nf;
    int choice;
    QuadraticHashTable< string > words(nf, 600000);

    init(&dictionary, &words);

    do
    {

	instructions();

	cin >> choice;

	switch(choice)
	{
	    case 0: 
		    break;
	    case 1: 
		    substitute(&words);
		    break;
	    default:
		    break;

	}

    } while (choice > 0);

    return 0;
}
