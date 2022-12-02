#include"Queue.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>

using namespace std;

Queue::Queue(int size) {
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}
void Queue::enqueue(int item) {
	if (isFull()) {
		cout << "Overflow\nProgram Terminated\n";
	}

	cout << "Inserting: " << item << endl;

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}
void Queue::dequeue() {
	if (isEmpty()) {
		cout << "Underflow\nProgram Terminated\n";
	}
	cout << "Removing: " << arr[front] << endl;

	front = (front + 1) % capacity;
	count--;
}
int Queue::peek() {
	if (isEmpty()) {
		cout << "Underflow\nProgram Terminated\n";
	}

	return arr[front];
}
int Queue::size() {
	return count;
}
bool Queue::isEmpty() {
	return (size() == 0);


}
bool Queue::isFull() {
	return(size() == capacity);
}
