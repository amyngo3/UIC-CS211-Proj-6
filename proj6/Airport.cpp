#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Airport.h"
#define ARRAY_SIZE 10

// Amy Ngo ango8
//  MyNode class functions

// return element
int MyNode::getElement(){
    return element;
}

// set next -- used by other classes
void MyNode::setNext(MyNode* n){
    next = n;
}

// return next code -- used by other classes
MyNode* MyNode::getNext(){
    return next;
}

// increase or decrease element
void MyNode::addElem(int num){
    element = element + num;
}

//  ========================================
//  MyList class functions

bool MyList::isEmpty(){
    if(head == nullptr){
        return false;
    } else {
        return true;
    }
}

// print airport list
void MyList::showList(){
    MyNode* temp = head;
    // check if list is empty
    if(isEmpty() == 1){
        printf("\tList is empty!\n");
        return;
    }
    while(temp != nullptr){
        printf("%d, ", temp->getElement());
        temp = temp->getNext();
    }
    printf("\n");
}

// add value to list
void MyList::insertValue(){
    head->addElem(1);   // increase
}

//  ========================================
//  Airport class functions

// check if value is in the list
int Airport::containInt(int x){
   MyNode *temp = apListHead;
    // check if apListHead points to nullptr
    if(apListHead == nullptr){
        return 0;
    }
    while(temp != nullptr){
        if(temp->getElement() == x){
            return 1;
        }
        temp = temp->getNext();
    }
}

// add data to the front of list
void Airport::push(int x){
    MyNode *temp = new MyNode(x);    // insert int in MyNode constructor
    visited = false;                // set bool visited to false
    temp->setNext(apListHead);
    apListHead = temp;
}

// return data value on top of list
int Airport::top(){
    if(apListHead != nullptr){
        return apListHead->getElement();
    } else {
        return -999;
    }
}

void Airport::pop(int x){
    MyNode *temp = apListHead;
    MyNode *prev = temp;
    /*if(isEmpty() == true){
        printf("\nCannot delete from an empty stack!\n");
        return;
    }*/
    // check front
    if(apListHead->getElement() == x){
        printf("\tSuccessfully pop in front.\n");
        apListHead = apListHead->getNext();
        return;
    }
    // check middle
    while(temp->getNext() != nullptr){
        if(temp->getElement() == x){
            printf("\tSuccessfully pop in the middle.\n");
            prev->setNext(temp->getNext());
            temp = nullptr;
            return;
        }
        prev = temp;
        temp = temp->getNext();
    }
    // check back
    if(temp->getElement() == x){
        prev->setNext(nullptr);
        printf("\tSuccessfully pop in the back.\n");
        return;
    }
    printf("\t%d was not in the stack.", x);
    return;
}

// make all nodes in list unvisited
void Airport::unvisitedList(){
    MyNode *temp = apListHead;

    if(temp == nullptr){
        return;
    }
    while(temp != nullptr){
        visited = false;            // set the airport to unvisited (?)
        temp = temp->getNext();     // ?
    }
}

bool Airport::getVisitedStatus(){
    return visited;
}

// change visited to false or true from status parameter
void Airport::setVisited(bool status){
    visited = status;
}

MyNode* Airport::getHead(){
    return apListHead;
}

 // make the whole linked list empty
void Airport::emptyList(){
    apListHead = nullptr;
}

// print all the nodes in a specific array
void Airport::printList(){
    MyNode* temp = apListHead;
    while(temp != nullptr){
        printf("%d, ", temp->getElement());
        temp = temp->getNext();
    }
}
