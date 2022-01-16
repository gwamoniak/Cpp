#include <iostream>

using namespace std;

struct Node
{
	int Value;
	Node* nextNode;
	
}; 

void printList(Node* node)
{
	while (node != nullptr)
	{
		cout << node->Value << endl;
		node = node->nextNode;
	}
}

void insertAtTheFront(Node** head, int newValue)
{
	// prepare a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	//put it in front
	newNode->nextNode = *head;
	// mode head of the list to point to the newNode
	*head = newNode;

}

void insertAtTheEnd(Node** head, int newValue)
{
	// prepare a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	newNode->nextNode = nullptr;
	if (*head == nullptr)
	{
		*head = newNode;
		return;
	}
	//find the last node
	Node* last = *head;
	while (last->nextNode != nullptr)
	{
		last = last->nextNode;
	}

	// mode head of the list to point to the newNode
	last->nextNode = newNode;

}
void insertAfter(Node* previous, int newValue)
{
	//check if previouse node is nullptr
	if (previous == nullptr)
	{
		cout << "Previouse can not be nullptr";
		return;
	}
	//prepare a newNode
	Node* newNode = new Node();
	newNode->Value = newValue;
	// Insert newNode after previouse
	newNode->nextNode = previous->nextNode;
	previous->nextNode = newNode;

}

int main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->Value = 1;
	head->nextNode = second;
	second->Value = 2;
	second->nextNode = third;
	third->Value = 3;
	third->nextNode = nullptr;

	insertAtTheFront(&head, -1);
	insertAtTheFront(&head, -2);
	insertAtTheEnd(&head, 4);
	insertAfter(second, -1);
	printList(head);

	system("pause>0");

}