CC	= cc
ARG	= -g -Wall
INP	= src/*.c
OUT	= bin/Virus

make:
	@sh VIRUS_CyberTeam.sh
	@mkdir -p bin
	$(CC) $(ARG) -o $(OUT) $(INP)
