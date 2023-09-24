#include "fenwick-tree.hpp"
#include <iostream>

int main() {
	FenwickTree ft{{0,1,0,1,2,3,2,1,1}};
	std::cout << ft.query(9) << "\n";
	ft.update_tree(5, 10);
	std::cout << ft.query(8) << "\n";
}


