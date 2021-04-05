/*
 * File: Sample.cpp
 * Project: TVJ_Vector
 * --------------------------
 *
 * @author: Teddy van Jerry
 * @licence: The MIT Licence
 * @compiler: at least C++/11 (tested on MSVC, MinGW and g++)
 *
 * @version 1.0 2021/03/24
 * - initial version
 *
 */

#include "TVJ_Vector.h"
#include <iostream>
using namespace std;

#define printVector(vec__) \
for (const auto& c__ : vec__) { \
	std::cout << c__ << ' '; \
} \
std::cout << std::endl;

int main()
{
	int arr[3] = { 13,-34,45 };
	tvj::vector<int> test(begin(arr), end(arr));        // initialize by iterators
	printVector(test);							        
	test.push_back(1024);                               // add element at the end
	test.push_front(2048);                              // add element at the front
	test.insert_after(test.back() - test.front(), 233); // insert element at a certain index
	printVector(test);
	*(test.end() - 2) = 3;                              // modify the value using iterator
	printVector(test);
	if (!test.sorted()) test.sort();                    // if not sorted, then sort it
	printVector(test);							        
	auto copied = test;                                 // copy
	copied.remove_at(2);                                // remove at a certain index
	copied[3] = -1000;                                  // modify the value using []
	test.clear();                                       // remove all elements
	printVector(copied);
	return 0;
}

// ALL RIGHTS RESERVED (C) 2021 Teddy van Jerry