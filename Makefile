
CXXFLAGS = -g -Wall

OBJS = src/key.cpp src/gencrypt.cpp src/genericcrpyto.cpp src/rot13.cpp

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