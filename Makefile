DESTDIR?=/usr/local/bin

TicTacToe: Main.o Board.o Utils.o
	clang++ -o $@ $^

Main.o: Main.cpp
	clang++ -c Main.cpp

Board.o: Board.cpp Board.h
	clang++ -c Board.cpp

Utils.o: Utils.cpp Utils.h
	clang++ -c Utils.cpp

.PHONY: clean install

clean:
	$(RM) TicTacToe Main.o Board.o Utils.o

install:
	cp TicTacToe $(DESTDIR)/TicTacToe
