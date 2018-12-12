CXX = g++

LDFLAGS = -pthread
CXXFLAGS =
CXXFLAGS += -O3 -std=c++11 -Wall
# CXXFLAGS += -O3 -std=c++98 -Wall

CXXFLAGS += -Wno-unused-variable -Wno-unused-but-set-variable
CXXFLAGS += -Werror=vla # to disable VLA
#CXXFLAGS += -fno-elide-constructors # to disable RVO

SRC_DIR := src

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
TARGET_FILES := $(patsubst $(SRC_DIR)/%.cpp, %, $(SRC_FILES))

all: $(TARGET_FILES)

% : $(SRC_DIR)/%.cpp
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS)

clean:
	@rm -rf $(TARGET_FILES)

.PHONY: all clean
