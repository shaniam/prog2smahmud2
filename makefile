T=prog2tree


$(T): $(T).o
	gcc -g $(T).o -o $(T)
$(T).o: $(T).c 
	gcc -g -c  $(T).c -o $(T).o

