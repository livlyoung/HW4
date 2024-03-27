all:
	g++ -Wall -g biggest_divisible_conglomerate.cpp main.cpp -o bdc

run:
	./bdc

try: all run
