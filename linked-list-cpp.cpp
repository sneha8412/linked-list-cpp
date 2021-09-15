#include <iostream>
using namespace std;

//this linkedlist will have 3 elements
class Node {
//each element of linkedlist will store value and pointer to next node
public:
    int Value;
    Node* Next;

};

//print all elements of the linked list
void printList(Node*n) {
    //needs to recieve the head element as it has the pointer to the next element
    while (n!= NULL){
        cout << n->Value << endl;
        n = n->Next;
    }
}

//insert a new node in the linked list in the start, end and anywhere in between
void insertAtTheFront(Node**head, int newValue){
    //prepare a newNode
    Node * newNode = new Node();
    newNode->Value = newValue;
    //put it in front of a current head
    newNode->Next = *head;
    //Move the head of the list to point to the newNode
    *head = newNode;
};

//insert a new node at the end of the linked list
void insertAtTheEnd(Node**head, int newValue){
    //1. prepare a new node that will be added at the end
    Node* newNode = new Node();
    newNode->Value = newValue;
    newNode->Next = NULL;
    //2. check if the list is empty, newNode will be the head in that case
    if (*head == NULL){
        *head = newNode;
        return;
    }
    //3. Find the last node
    Node* last = *head;
    while(last->Next != NULL){
        last = last->Next;
    }
    //4. Insert the newNode after the last node (at the end)
    last->Next = newNode;
}

//insert a node inbetween
void insertAfter(Node*previous, int newValue){
    //1. check if the previous node is NULL
    if (previous ==NULL){
        cout <<"Previous can not be NULL";
        return;
    }
    //2. prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newValue;
    //3. Insert the new node after the previos element
    newNode->Next = previous->Next;
    previous->Next = newNode;

}


//find a linkedlist  that contains a node with specified value
//returns true if found, else false


int main()
{
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    //access values in the class instead of dot notation incase you are using pointers
    //head inside its value property
    //ading the values to a linked list
    head-> Value = 1;
    head -> Next = second;//linking to the second element, next value is second
    second-> Value = 2;
    second -> Next = third; 
    third-> Value = 3;
    third -> Next = NULL;

    printList(head);
    insertAfter(head, 7);
    insertAtTheFront(&head, -1 ); //invocation of the function passing address of a head
    insertAtTheEnd(&head, 5);
    // system("pause>0");
}