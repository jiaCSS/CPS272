#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

#define SIZE 10
class Queue {
private:
	int* arr;
	int capacity;
	int front;
	int rear;
	int count;
public:
	Queue(int size = SIZE);
	~Queue() {
		delete[] arr;
	}

	void enqueue(int item);
	void dequeue();
	int peek();
	int size();
	bool isEmpty();
	bool isFull();

};

