TITLE=Breakdown
BINDIR=bin/
OBJDIR=obj/
SRC=main.cpp Bullet.cpp ObjectManager.cpp Object.cpp SpellCard.cpp MathVector.cpp
CC=g++
CXXFLAGS=-W -Wall -Wextra -std=c++11
LDFLAGS=-lsfml-window -lsfml-graphics -lsfml-system
OBJ=$(addprefix $(OBJDIR), $(SRC:.cpp=.o))
EXEC=$(addprefix $(BINDIR), $(TITLE))

all:$(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(addprefix $(OBJDIR), main.o): main.cpp Pattern.h
	$(CC) -o $@ -c $< $(CXXFLAGS)

$(addprefix $(OBJDIR), %.o) : %.cpp %.h
	$(CC) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJDIR)
	mkdir $(OBJDIR)

mrproper: clean
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
	rm .*.sw*
