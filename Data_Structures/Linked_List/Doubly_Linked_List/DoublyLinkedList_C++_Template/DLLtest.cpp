/* tester */

#include "DLL.h"
#include <iostream>

int main(void) {
	DLL<int> regular;
	Sentinel<int> sentinel;

	/* DLL class test */
	std::cout << "testing regular doubly linked list" << std::endl;
	
	// test push_front();
	for (int i = 0; i < 3; i++) {
		regular.push_front(i);
		regular.print(); 				
	}
	regular.reversePrint();    

	//test push_back();
	for (int i = 3; i < 6; i++) {
		regular.push_back(i);
		regular.print();
	}
	regular.reversePrint();

	//test pop_front() & pop_back()
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 0) {
			regular.pop_front();
		}
		else {
			regular.pop_back();
		}
		regular.print();
	}
	regular.reversePrint();

	//test push_back();
	for (int i = 0; i < 3; i++) {
		regular.push_back(i);
		regular.print();
	}
	regular.reversePrint();
	

	for (int i = 3; i < 6; i++) {
		regular.push_front(i);
		regular.print();
	}
	regular.reversePrint();

	//test pop_front()
	for (int i = 0; i < 7; i++) {
		if (i % 2) {
			regular.pop_front();
		}
		else {
			regular.pop_back();
		}
		regular.print();
	}
	regular.reversePrint();

   
	for (int i = 0; i < 3; i++) {
		regular.push_front(i);
		regular.print();
	}
	regular.reversePrint();


	/* Sentinel class test */

	std::cout << "testing sentinel list" << std::endl;

	//test push_front()
	for (int i = 0; i < 3; i++) {
		sentinel.push_front(i);
		sentinel.print();
	}
	sentinel.reversePrint();

	//test push_back()
	for (int i = 3; i < 6; i++) {
		sentinel.push_back(i);
		sentinel.print();
	}
	sentinel.reversePrint();

	//test pop_front() & pup_back()
	for (int i = 0; i < 7; i++) {
		if (i % 2 == 0) {
			sentinel.pop_front();
		}
		else {
			sentinel.pop_back();
		}
		sentinel.print();
	}
	sentinel.reversePrint();

	for (int i = 0; i < 3; i++) {
		sentinel.push_back(i);
		sentinel.print();
	}
	sentinel.reversePrint();

	for (int i = 3; i < 6; i++) {
		sentinel.push_front(i);
		sentinel.print();
	}
	sentinel.reversePrint();

	for (int i = 0; i < 7; i++) {
		if (i % 2) {
			sentinel.pop_front();
		}
		else {
			sentinel.pop_back();
		}
		sentinel.print();
	}
	sentinel.reversePrint();

	for (int i = 0; i < 3; i++) {
		sentinel.push_front(i);
		sentinel.print();
	}
	sentinel.reversePrint();


	return 0;
}
