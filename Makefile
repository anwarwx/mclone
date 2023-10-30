CXXFLAGS = -std=c++17 -Wall -O2 -Wno-deprecated
CXX = g++ $(CXXFLAGS)

SRC_DIR = app/src
SRC = $(shell find $(SRC_DIR) -name '*.cc') $(LIB_DIR)/glad.c
LIB_DIR = ./libs
LIBS = -L $(LIB_DIR) -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

BUILD_NAME = mclone

all: build run

build: clean
	mkdir -p build
	$(CXX) -o build/$(BUILD_NAME) $(SRC) $(LIBS)

run:
	./build/mclone

clean:
	rm -rf build
