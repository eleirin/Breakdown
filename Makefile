TITLE=Breakdown
BINDIR=bin/
OBJDIR=obj/
SRC=main.cpp Bullet.cpp Constant.cpp Heroin.cpp MathVector.cpp Object.cpp ObjectManager.cpp SpellCard.cpp 
CC=g++
CXXFLAGS=-W -Wall -Wextra -std=c++11 -g
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

.PHONY: clean mrproper rebuild

clean:
	rm -rf $(OBJDIR)*
	rm -rf .*.sw*

mrproper: clean
	rm -rf $(BINDIR)*

rebuild: clean all
