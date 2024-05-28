# List of directories
DIRS := Chapter-16-Classes chapter-23-templates

# Automatically find all .cpp files in the specified directories
CPP_FILES := $(wildcard $(addsuffix /*.cpp, $(DIRS)))

# Define .out files by replacing .cpp with .out
OUT_FILES := $(CPP_FILES:.cpp=.out)

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -std=c++17

# Default target: build all .out files
all: $(OUT_FILES)

# Rule to convert .cpp to .out
%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean target to remove all .out files
clean:
	rm -f $(OUT_FILES)
