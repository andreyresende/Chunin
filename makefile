run: arvore.c main.c

	gcc -g -c arvore.c && gcc -g -o main main.c arvore.o && ./main

clean:

	rm arvore.o && rm main