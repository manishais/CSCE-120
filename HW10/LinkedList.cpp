#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	clear() ;
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
	head = nullptr ;
	tail = nullptr ;

}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function

	clear();
	
	for (Node* nodee = source.head; nodee != nullptr; nodee = nodee -> next) 
	{
		TemperatureData& data = nodee -> data;
		insert(data.id, data.year, data.month, data.temperature);
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) 
{
	// Implement this function
	if (temperature == -99.99)
	{
		return ;
	}
	else {
		Node* newNode = new Node(location, year, month, temperature);
		if (head == nullptr && tail == nullptr) 
		{
			head = newNode;
			tail = newNode;
		} 
	}
}

void LinkedList::clear() {
	// Implement this function
	while (head != nullptr)
	{
		Node* temp = head -> next;
		delete head;
		head = temp;
	}
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	string outputString;

	// Implement this function
	stringstream stringy;
	Node* nodee = head;

	while(nodee != head)
	{
		stringy << nodee -> data.id << " " << nodee -> data.year << " " << nodee -> data.month << " " << nodee -> data.temperature << endl;
		nodee = nodee -> next;
	}

	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
