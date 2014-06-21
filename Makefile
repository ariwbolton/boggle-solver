wordfinder.out: wordfinder.o set.o
	g++ -Wall -o wordfinder.out wordfinder.o set.o

wordfinder.o: wordfinder.cpp
	g++ -Wall -c wordfinder.cpp

set.o: set.cpp set.h
	g++ -Wall -c set.cpp

clean:
	rm -f wordfinder.out *.o
