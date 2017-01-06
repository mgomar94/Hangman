# Makefile for the hangman game

all: main.cpp
	 g++ -g -Wall -std=c++11 -o hangman main.cpp
	 
clean:
	$(RM) hangman
