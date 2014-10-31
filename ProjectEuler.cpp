// ProjectEuler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Stack {
	
	int MaxStack;
	int EmptyStack;
	int top;
	int* items;
	int* LargestStack;

public:
	Stack(int);
	~Stack();
	void push(int);
	int pop();
	int empty();
	int full();
	int getMax();
};


Stack::~Stack() { delete[] items; }
Stack::Stack(int size) {
	MaxStack = size;
	EmptyStack = -1;
	top = EmptyStack;
	items = new int[MaxStack];
	LargestStack = new int[MaxStack];
}

void Stack::push(int x) {
	int largest = 0;
	
	items[++top] = x;
	if (items[top] > items[top - 1]){
		
		largest = x;
		
		LargestStack[top] = largest;
		cout << LargestStack[top] << endl;
	}
	
}

int Stack::pop() {
	/*if (LargestStack[top] == items[top]) {
		//LargestStack.pop();
	}*/
	return items[top--];
}

int Stack::full(){
	return top + 1 == MaxStack;
}

int Stack::empty(){
	return top == EmptyStack;
}

int Stack::getMax() {
	cout << LargestStack[top] << endl;
	return LargestStack[top];
}
int sequenceofMultiples(int n){
	int sum = 0;
	for (int i = 1; i < n; i++){
		if (i % 3 == 0 || i % 5 == 0){
			sum = sum + i;
		}
	}
	cout << sum;
	return n;
}

int fibonacciSeries(int n) {
	int sum = 0;
	int nextInteger = 0;
	int start1 = 1;
	int start2 = 2;
	while (nextInteger <= n){
		if (start2 % 2 == 0) {
			sum = sum + (start2);
		}
		nextInteger = start1 + start2;
		cout << "Fibonacci set:" << start1 << "+" <<  start2 << endl;
		start1 = start2;
		start2 = nextInteger;
		
	}
	
	cout << "Last fibonacci number:" << nextInteger << endl;
	cout << "Total of Evens:" << sum << endl;
	return sum;
}

char** create_Array() {
	
	char* char_array[] = { "Hello", "Apple", "Maple" };
	cout << char_array[0] << endl;
	cout << char_array[1] << endl;
	cout << char_array[2] << endl;
	return char_array;
}




int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	//sequenceofMultiples(10);
	//fibonacciSeries(100);
	Stack s(5);

	
	for (int i = 0; i < 5; i++) {
		if (!s.full()) {
			s.push(i);
			 }
	}	
	
	/*(while (!s.empty()) {
		cout << s.pop();
		

	}*/
	cout << endl;
	s.getMax();
	
	
	cin >> x;

	return 0;
}

