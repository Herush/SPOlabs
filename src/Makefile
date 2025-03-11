CXX = g++
CFLAGS = -Wall -Wextra -std=c++17 -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lprometheus-cpp-core -lprometheus-cpp-pull -lprometheus-cpp-push -lpthread
BUILD_DIR = ../usr/bin
TEST_DIR = ../cicd/tests
PACKAGE_DIR = ../debian-pkg

check-env:
	@which $(CXX) > /dev/null || (echo "Error: $(CXX) not found. Install with 'sudo apt install build-essential'"; exit 1)
	@dpkg -l libc6-dev > /dev/null || (echo "Error: libc6-dev not found. Install with 'sudo apt install libc6-dev'"; exit 1)

build: check-env
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CFLAGS) -o $(BUILD_DIR)/laba1spo main.cpp $(LDFLAGS)

test: build
	@echo "Running tests..."
	@bash $(TEST_DIR)/run_tests.sh $(BUILD_DIR)/laba1spo

clean:
	rm -rf $(BUILD_DIR) $(PACKAGE_DIR)

.PHONY: build test clean check-env
