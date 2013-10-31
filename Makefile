CC = g++ -Wall -Werror -std=c++11
DFLAGS = -p -g
OFLAGS = -O1
NDEBUG = -O3 -DNDEBUG
OUTPUT = -o kohonen kohonen.cpp

main:
	$(CC) $(OUTPUT)
	
debug:
	$(CC) $(DFLAGS) $(OUTPUT)
	
maxdebug:
	$(CC) $(DFLAGS)3 $(OUTPUT)
	
optimise:
	 $(CC) $(OFLAGS) $(OUTPUT)
	
ndebug:
	$(CC) $(NDEBUG) $(OUTPUT)
	
clean:
	rm kohonen
