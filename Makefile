# first target: all, this targe will compile all the file
CC = g++
CFLAGS = -Wall
EXE_NAME = class_exe
DEPS = cat.h
OBJ = main.o cat.o

#all: 
##	g++ -Wall main.cpp cat.cpp -o $(EXE_NAME)
#	$(CC) $(CFLAGS) $(wildcard *.cpp) -o $(EXE_NAME)

# -c: generate object files
# -o $@: put putout of the ciompilation in the file named on the left side of the ":"
# $<: the first item in the dependencies list 
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# $@: the file name of the target
# $^: the name of all the prereqruisites(duplicate prerequisites are omitted)
$(EXE_NAME): $(OBJ)
	$(CC) -o $@ $^ 

clean:
	rm -rf *.o  $(EXE_NAME)
# rm: remove command


