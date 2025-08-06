# compiler 
CC = gcc
CFLAGS = -Wall -Wextra -g

#Directores
BUILD_DIR = build
SOURCE_DIR = src

# source files
SRCS = $(SOURCE_DIR)/main.c 

#object files
OBJS = $(BUILD_DIR)/main.o

#target executable
TARGET = $(BUILD_DIR)/a

#build target
all: $(TARGET)

#linking object files to create the final executable
$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)


#compile each .c file into .o file
$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/main.c -o $(BUILD_DIR)/main.o

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# clean build files	
clean:
	rm -f $(OBJS) $(TARGET)
	rm -rf $(BUILD_DIR)

# run the executable file
run:
	$(BUILD_DIR)/a.exe




