# compiler and flags
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
TARGET = $(BUILD_DIR)/a.exe

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
run: $(TARGET)
	./$(TARGET)



# ---------- Test target ----------
# compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# Test directories
TEST_DIR = test

# Test files
TEST_SRCS = $(TEST_DIR)/main_test.cpp
TEST_OBJS = $(BUILD_DIR)/main_test.o
TEST_EXE = $(BUILD_DIR)/test.exe

# function file
FUNCTION_SRCS = $(SOURCE_DIR)/logic_function.c
FUNCTION_OBJS = $(BUILD_DIR)/logic_function.o

# compile test files
$(BUILD_DIR)/main_test.o: $(TEST_DIR)/main_test.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/main_test.cpp -o $(BUILD_DIR)/main_test.o

$(BUILD_DIR)/logic_function.o: $(SOURCE_DIR)/logic_function.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/logic_function.c -o $(BUILD_DIR)/logic_function.o

# Build test executable
tests: $(TEST_EXE)
$(TEST_EXE): $(TEST_OBJS) $(FUNCTION_OBJS)
	$(CXX) $(TEST_OBJS) $(FUNCTION_OBJS) -lgtest -lgtest_main -lpthread -o $(TEST_EXE)

runtest: $(TEST_EXE)
	./$(TEST_EXE)
