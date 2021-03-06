#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;

	length = 0;
}

void LinkedList::addItem(int a)
{
	if (!head) {
		head = new Node;
		(*head).data = a;
		(*head).prev = nullptr;
		(*head).next = nullptr;

		tail = head;
		length++;
	}
	else {
		Node *temp = new Node;
		(*tail).next = temp; // this line fucks it up. awesome. OH HEY I THINK I KNOW WHY
		(*temp).data = a;
		(*temp).prev = tail;
		(*temp).next = nullptr;
		tail = temp;
		length++;
	}
}

int LinkedList::getItem(int a)
{
	if (a > length - 1) {
		throw 0;
	}

	Node *temp;
	temp = head;
	for (int i = 0; i < a; i++) {
		temp = (*temp).next;
	}

	return (*temp).data;
}

int LinkedList::delItem(int a) // a == index to delete, returns deleted node
{
	if (a > length - 1) {
		throw 0;
	}

	int finalData;

	if (a == 0) { // if deleting first node
		Node *temp;
		temp = head;
		finalData = (*head).data;
		head = (*head).next;
		delete temp; // need to clear up memory
		(*head).prev = nullptr;
	}

	else if (a < length - 1) { // deleting random node in memory

		Node *temp;
		temp = head;
		for (int i = 0; i < a - 1; i++) { // goes to location before it
			temp = (*temp).next;
		}

		Node *temp2;
		temp2 = (*temp).next;
		finalData = (*temp2).data;
		(*temp).next = (*((*temp).next)).next;
		(*((*temp).next)).prev = temp;
		delete temp2;
	}

	else { // deleting tail
		Node *temp = tail;
		(*((*tail).prev)).next = nullptr;
		finalData = (*tail).data;

		tail = (*tail).prev;
		delete temp;
	}
	
	length--;

	return finalData;
}

int LinkedList::setItem(int a, int stuff)
{
	if (a > length - 1) {
		throw 0;
	}

	Node *temp;
	temp = head;
	for (int i = 0; i < a - 1; i++) { // goes to location before it
		temp = (*temp).next;
	}

	int b = (*temp).data;
	(*temp).data = stuff;

	return b;
}

int LinkedList::size()
{
	return length;
}

string LinkedList::toString()
{
	string s = to_string(length) + ": {";

	Node *temp;
	temp = head;

	for (int i = 0; i < length - 1; i++) {
		s += "\n\t" + to_string((*temp).data) + ", "; // this is throwing the exception?
		temp = (*temp).next;
	}
	if(length > 1)
		s += "\n\t" + to_string((*temp).data) + "\n}";
	else
		s += "\n}";
	
	return s;
}
