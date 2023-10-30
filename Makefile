CXXFLAGS = -std=c++17 -Wall -O2
CXX = g++ $(CXXFLAGS)

SRC_DIR = app/src
SRC = $(shell find $(SRC_DIR) -name '*.cc')
LIBS = -L ./libs -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

BUILD_NAME = mclone

build: clean
	mkdir -p build
	$(CXX) -o build/$(BUILD_NAME) $(SRC) $(LIBS)

run:
	./build/mclone

clean:
	rm -rf build
