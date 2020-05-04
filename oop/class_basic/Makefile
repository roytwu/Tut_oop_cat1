# Makefile
# programmer: Roy TWu

# In order to make this work: 
# source code (.cpp and .h) must be put in the 'src' folder
# make will put object files in 'obj folder' 

SRC_DIR = src
OBJ_DIR = obj
# BIN_DIR = bin

CC = g++
CFLAGS = -Wall -I/$(SRC_DIR)
LFLAGS = -lm
TARGET_EXE = class_exe


SOURCE = $(wildcard $(SRC_DIR)/*.cpp)
INCLUDE = $(wildcard $(SRC_DIR)/*.h)

OBJ = $(SOURCE:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

#$(BIN_DIR)/$(EXE_NAME): $(OBJ) #uncomment if there is a bin directory
$(TARGET_EXE): $(OBJ) 
	$(CC) -o $@ $(LFLAGS) $(OBJ) 
	@echo " Comiled successfully!"

$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR) 	
	$(CC) $(CFLAGS) -c $< -o $@ 
	@echo " Linking completed!"

.PHONY: clean

clean:
	rm -rf *.o  $(TARGET_EXE) $(OBJ_DIR)
	clear  #clear the console

# rm: remove command


