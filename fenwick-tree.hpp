#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <cstddef>
#include <cstdint>
#include <vector>
#include <iostream>

template<typename Integer>
inline Integer get_last_set_bit(Integer i) {
	return (i & -i);
}

template<typename Integer = uint32_t>
class FenwickTree {
private:
	std::vector<Integer> array;

public:
	FenwickTree(std::vector<Integer> const && frequency_list) {
		array = std::vector<Integer>(frequency_list.size() + 1);
		std::copy(frequency_list.begin(), frequency_list.end(), array.begin() + 1);
		for(Integer i = 0; i < array.size(); i++) {
			if(i + get_last_set_bit(i) < array.size()) {
				array[i + get_last_set_bit(i)] += array[i];
			}
		}
	}

	Integer query(Integer num) {
		Integer result = 0;
		for(Integer i = num; i > 0; i = i - get_last_set_bit(i)) {
			result += array[i];
		}
		return result;
	}

	Integer range_query(Integer begin, Integer end) {
		return query(end) - query(begin);
	}

	void update_tree(Integer number_to_update, Integer change_amount) {
		while(number_to_update + get_last_set_bit(number_to_update) < array.size()) {
			array[number_to_update + get_last_set_bit(number_to_update)] += change_amount;
			number_to_update = number_to_update + get_last_set_bit(number_to_update);
		}
	}
};


#endif
