fenwick-tree : fenwick-tree.o
	c++ -o fenwick-tree fenwick-tree.o
fenwick-tree.o : fenwick-tree.cpp fenwick-tree.hpp
	c++ -c fenwick-tree.cpp
clean :
	rm fenwick-tree.o
