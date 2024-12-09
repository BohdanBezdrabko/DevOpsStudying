# Compiler to use
CXX = g++

# Compiler flags for warnings and C++11 standard
CXXFLAGS = -Wall -std=c++11

# Name of the target executable
TARGET = Function

# Source files for the project
SOURCES = main.cpp FuncA.cpp

# Object files derived from source files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target to build the project
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up build artifacts
clean:
	rm -f $(OBJECTS) $(TARGET)

# Declaring phony targets to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean
