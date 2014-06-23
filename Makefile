wordfinder.out: wordfinder.o set.o substitution.o boggle.o completiontree.o
	g++ -Wall -o wordfinder.out wordfinder.o set.o substitution.o boggle.o completiontree.o

wordfinder.o: wordfinder.cpp
	g++ -Wall -c wordfinder.cpp

set.o: set.cpp set.h
	g++ -Wall -c set.cpp

substitution.o: substitution.cpp substitution.h
	g++ -Wall -c substitution.cpp

boggle.o: boggle.cpp boggle.h 
	g++ -Wall -c boggle.cpp

completiontree.o: completiontree.cpp completiontree.h
	g++ -Wall -c completiontree.cpp

clean:
	rm -f wordfinder.out *.o
