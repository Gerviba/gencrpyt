
CXXFLAGS = -g -Wall

OBJS = $(wildcard src/*.cpp)

.PHONY: all
all: install

install: clean $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o gencrypt
	
test:

integration-test:

touch:
	touch src/*
	
clean:
	rm -f gencrypt
	
run:
	./gencrypt