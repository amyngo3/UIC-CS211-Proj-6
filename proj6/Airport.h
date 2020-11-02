#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>


// Amy Ngo ango8

class MyNode{
private:
    int element;        // airport number
    MyNode *next;       // next pointer

public:
    // constructor
    MyNode(int x){
        element = x;
        next = nullptr;
    }
    // return element
    int getElement();
    // set next -- used by other classes
    void setNext(MyNode* n);
    // return next code -- used by other classes
    MyNode* getNext();
    // increase or decrease element
    void addElem(int num);
};

class MyList{
private:
    MyNode* head;      // relies on the Airport class

public:
    // constructor
    MyList(){
        head = nullptr;
    }
    bool isEmpty();
    // print airport list
    void showList();
    // add value to list
    void insertValue();
    // remove value from list
    void deleteValue();
};

// List Class for the linked list
class Airport{
private:
    // instances
    MyNode* apListHead;
    MyList* nodeList;
    bool visited;       // true = visited   |   false = not visited

public:
    // nest the node class in list class
    TravelNetwork();
    //constructor
    Airport(){
        apListHead = nullptr;
        visited = false;
    }

    int getSize();
    // check if value is in the list
    int containInt(int x);
    // add data to the front of list
    void push(int x);
    // return data value on top of list
    int top();
    void pop(int x);
    // make all nodes in list unvisited
    void unvisitedList();
    bool getVisitedStatus();
    // change visited to false or true from status parameter
    void setVisited(bool status);
    MyNode* getHead();
    // make the whole linked list empty
    void emptyList();
    // print all the nodes in a specific array
    void printList();

};
#endif // AIRPORT_H_INCLUDED
