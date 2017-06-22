CC = g++
CFLAGS = -std=c++14
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lgdi32 -lopengl32 -ljpeg -lfreetype -lFLAC -lvorbis -lvorbisfile -lvorbisenc -logg -lwinmm
EXEC = foret

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

foret: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper exe make makexe

clean:
	@del /Q *.o

mrproper: clean
	@del /Q $(EXEC).exe

exe: all
	@$(EXEC).exe

makexe: clean all
	@$(EXEC).exe

make: clean all
