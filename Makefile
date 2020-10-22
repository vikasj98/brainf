all: generate bf

generate:
	gcc -o generate generate.c -lm

bf:
	gcc -o bf bf.c -lm
