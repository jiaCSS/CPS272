#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<time.h>
#include<new>

using namespace std;
struct node {
	int data;
	struct node* next;
};


//add first empty list
struct node* addToEmpty(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	
	return newnode;	
}


//insert function
struct node* insert(struct node* head, int data) {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	int key = data;
	struct node* temp;
	
	if (head == NULL || key < (head->data)) {
		head->next = head;
		head = newnode;
	}
	else {
		temp = head;
		while (temp->next != NULL && (temp->next->data) < key) {
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}

	return head;	
}


//merge two list
struct node* mergeTwoList(struct node* first, struct node* second) {
	struct node* dummy = (struct node*)malloc(sizeof(struct node));
	dummy->next = NULL;
	if (first == NULL) {
		return second;
	}
	if (second == NULL) {
		return first;
	}
	dummy->next = (first->data) > (second->data) ? first : second;
	struct node* temp = dummy;
	while (first != NULL && second != NULL) {
		if (first->data < second->data) {
			temp->next = first;
			temp = first;
			first = first->next;
		}
		else {
			temp->next = second;
			temp = second;
			second = second->next;
		}
		if (first != NULL) {
			temp->next = first;
		}
		if (second != NULL) {
			temp->next = second;
		}
	}//end while loop
	
	return dummy->next;
}


//removeduplicatoin
void removeDuplicateList(struct node* head) {
	struct node* current = head;
	struct node* next;
	if (current->next == NULL) {
		return;
	}
	while (current->next != NULL) {

		if (current->data == current->next->data) {
			next = current->next->next;			
			free(current->next);
			current->next = next;
		}
		else {
			current = current->next;
		}
	}
}

//merge function without duplication
struct node* sortedMergedListWithoutDuplicate(struct node* head1, struct node* head2) {
	
	struct node* head = mergeTwoList(head1, head2);
	removeDuplicateList(head);

	return head;
}

//print function
void print(struct node* head) {
	struct node* temp = head;
	while(temp->next != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << "\n";
}

//print merged function
void printMergedList(struct node* head) {
	struct node* temp = head;
	float sum = 0;
	int count=0;
	while (temp->next != NULL) {

		cout << temp->data << " ";
		sum = sum + temp->data;
		temp = temp->next;
		count++;
	}

	cout << "\n\n";
	cout << "The sum is : " << sum << endl;
	cout << "The average of the final list is: " << (sum / count) << endl;
	
}



//main function
int main() {
	//srand(time(NULL));
	srand(500);

	//print first list
	struct node* firstList = NULL;
	firstList = addToEmpty(1);
	int count1 = 0;
	for (int i = 1; i < 21; i++) {
		
		int data = rand() %100 + 0;	
		firstList =insert(firstList, data);
		count1++;
	}
	cout << "\nThe count for first list is: " << count1 << endl;
	cout << "The first list is: ";
	print(firstList);


	//print second list
	struct node* secondList = NULL;
	secondList = addToEmpty(2);
	int count2 = 0;
	for (int i = 1; i < 16; i++) {	
		int data = rand() % 100 + 0;
		secondList = insert(secondList, data);
		count2++;
		
	}
	
	cout << "\nThe count for second list is: " << count2 << endl;
	cout << "The second list is: " ;
	print(secondList);
	
	//struct node* head = NULL;
	//head = mergeTwoList(firstList, secondList);
	//cout << "The merged  list is: "<<endl;
	//print(head);
	// 

	//print without duplicate
	int mergedSize = count1 + count2;
	int count3;
	struct node*head3= sortedMergedListWithoutDuplicate(firstList, secondList);
	cout << "\nThe merged list is: " << endl;
	printMergedList(head3);
	



	return 0;
}