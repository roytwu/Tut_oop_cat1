# first target: all, this targe will compile all the file

SRC_DIR = src

CC = g++
EXE_NAME = exe

DEPS += $(SRC_DIR)/main.h 
DEPS += $(SRC_DIR)/binaryTree.h 
# DEPS += $(SRC_DIR)/swarm.h

OBJ += $(SRC_DIR)/main.o 
OBJ += $(SRC_DIR)/binaryTree.o 

CFLAGS += -Wall
# CFLAGS += -I/usr/local/include/SDL2
# #CFLAGS += -L/usr/local/lib

# LDFLAGS += -lSDL2


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
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(SRC_DIR)/*.o *.o $(EXE_NAME)   # rm: remove command 
	clear                    # clear console