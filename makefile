CC	= cc
ARG	= -g -Wall
INP	= src/*.c
OUT	= bin/Virus

make:
	@mkdir -p bin
	$(CC) $(ARG) -o $(OUT) $(INP)
