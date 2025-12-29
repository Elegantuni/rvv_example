main: main.c vec.S Makefile
	gcc -O main.c vec.S -o rvv_example -march=rv64gcv_zba -lm

clean:
	rm -f rvv_example

