# first target: all, this targe will compile all the file
CC = g++
CFLAGS = -Wall -I/src
LFLAGS = -lm
EXE_NAME = class_exe



SRC_DIR = src
BUILD_DIR = build
# BIN_DIR = bin

SOURCE = $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE = $(wildcard $(SRC_DIR)/*.h)

OBJ = $(SOURCE:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

#$(BIN_DIR)/$(EXE_NAME): $(OBJ) #uncomment if there is a bin directory
$(EXE_NAME): $(OBJ) 
	$(CC) -o $@ $(LFLAGS) $(OBJ) 

$(OBJ): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp 
	$(CC) $(CFLAGS) -c $< -o $@  




#all: 
##	g++ -Wall main.cpp cat.cpp -o $(EXE_NAME)
#	$(CC) $(CFLAGS) $(wildcard *.cpp) -o $(EXE_NAME)

# # -c: generate object files
# # -o $@: put out of the ciompilation in the file named on the left side of the ":"
# # $<: the first item in the dependencies list 	
# $(BUILD_DIR)/%.o: %.cpp $(DEPS)
# 	mkdir -p $(BUILD_DIR)
# 	$(CC) $(CFLAGS) -c -o $@ $< 

# # $@: the file name of the target
# # $^: the name of all the prereqruisites(duplicate prerequisites are omitted)
# $(EXE_NAME): $(BUILD_DIR)/$(OBJ) 
# 	$(CC) -o $@ $^ 

clean:
	rm -rf *.o  $(EXE_NAME) $(BUILD_DIR)
	clear
# rm: remove command


