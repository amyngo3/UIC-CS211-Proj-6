#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "Airport.cpp"

#define ARRAY_SIZE 10
/*
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
    int getElement(){
        return element;
    }

    // set next -- used by other classes
    void setNext(MyNode* n){
        next = n;
    }

    // return next code -- used by other classes
    MyNode* getNext(){
        return next;
    }

    // increase or decrease element
    void addElem(int num){
        element = element + num;
    }
};

class MyList{
private:
    MyNode* head;      // relies on the Airport class

public:
    // constructor
    MyList(){
        head = nullptr;
    }

    bool isEmpty(){
        if(head == nullptr){
            return false;
        } else {
            return true;
        }
    }

    // print airport list
    void showList(){
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
    void insertValue(){
        head->addElem(1);   // increase
    }

    // remove value from list
    void deleteValue(){
        head->addElem(-1);  // decrease
    }
};

// List Class for the linked list
class Airport{
private:
    // instances
    MyNode* apListHead;
    bool visited;       // true = visited   |   false = not visited

public:
    // nest the node class in list class
    TravelNetwork();
    //constructor
    Airport(){
        apListHead = nullptr;
        visited = false;
    }

    // check if value is in the list
    int containInt(int x){
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
    void push(int x){
        MyNode *temp = new MyNode(x);    // insert int in MyNode constructor
        visited = false;                // set bool visited to false
        temp->setNext(apListHead);
        apListHead = temp;
    }

    // return data value on top of list
    int top(){
        if(apListHead != nullptr){
            return apListHead->getElement();
        } else {
            return -999;
        }
    }

    void pop(int x){
        MyNode *temp = apListHead;
        MyNode *prev = temp;
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
    void unvisitedList(){
        MyNode *temp = apListHead;

        if(temp == nullptr){
            return;
        }
        while(temp != nullptr){
            visited = false;            // set the airport to unvisited (?)
            temp = temp->getNext();     // ?
        }
    }

    bool getVisitedStatus(){
        return visited;
    }

    // change visited to false or true from status parameter
    void setVisited(bool status){
        visited = status;
    }

    MyNode* getHead(){
        return apListHead;
    }

    // make the whole linked list empty
    void emptyList(){
        apListHead = nullptr;
    }

    // print all the nodes in a specific array
    void printList(){
        MyNode* temp = apListHead;
        while(temp != nullptr){
            printf("%d, ", temp->getElement());
            temp = temp->getNext();
        }
    }

};
*/
// Node Class for the linked list
class TravelNetwork
{
 private:
   // Create the Data Members for the Travel Network here
   Airport *arrAirport;     // pointer to dynamic array
   char* filename;         // txt file
   int numAirports;

 public:

 // Use a constructor to initialize the Data Members for Travel Network
 TravelNetwork()
 {
    arrAirport = new Airport[ARRAY_SIZE];   // index 0 doesn't count as an airport
    numAirports = 0;
    // create and initialize array of linked lists
    /*for(int i = 0; i < 11; i++){
        arrAirport[i] = new Airport;
    }*/
 }

 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input

  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions
    char* command;
    command = strtok (input , " \n\t");

    printf ("*%s*\n", command);

    if ( command == NULL )
      printf ("Blank Line\n");

    else if ( strcmp (command, "q") == 0)
      exit(1);

    else if ( strcmp (command, "?") == 0)
      showCommands();

    else if ( strcmp (command, "t") == 0)
      doTravel(input);

    else if ( strcmp (command, "r") == 0)
      doResize();

    else if ( strcmp (command, "i") == 0)
      doInsert();

    else if ( strcmp (command, "d") == 0)
      doDelete(input);

    else if ( strcmp (command, "l") == 0)
      doList(input);

    else if ( strcmp (command, "f") == 0)
      doFile(input);

    else if ( strcmp (command, "#") == 0)
      ;

    else
      printf ("Command is not known: %s\n", command);

    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }

 bool dfs(int a, int b){
    MyNode* c = arrAirport[a-1].getHead();

    for(int i = 0; i < a; i++){
        if(c->getElement() == b){     // c must be int to compare
            return true;
        }
        if(arrAirport[a].getVisitedStatus() == false){
            arrAirport[a].setVisited(true);  // mark airport c as visited
            // recursive function
            if(dfs(c->getElement(),b) == true){
                return true;
            }
        }
    }
    return false;
 }

 // determine if a person can travel from airport x to airport y
 void depthFirstSearchHelper(int x, int y){
    // mark all airports as unvisited
    for(int i = 0; i < ARRAY_SIZE; i++){
        arrAirport[i].unvisitedList();      // goes to airport's linked list and set to false
    }
    if(dfs(x,y) == true){
        printf("You can get from air port %d to airport %d in one or more flights.\n", x, y);
    } else {
        printf("You can NOT get from air port %d to airport %d in one or more flights.\n", x, y);
    }
 }

 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }

 // 't' command
 void doTravel(char *input)
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }


   printf ("Performing the Travel Command from %d to %d\n",
            val1, val2);
    // check if airport val1 can travel to airport val2
    depthFirstSearchHelper(val1, val2);
 }

 void doResize()
 {
   int val1 = 0;

   char* next = strtok (NULL, " \n\t");
   if ( next == NULL ){
        printf ("Integer value expected\n");
        return;
   }
   val1 = atoi ( next );

   if ( val1 == 0 && strcmp (next, "0") != 0){
        printf ("Integer value expected\n");
        return;
   }
   //  =====================================================

   // remove all values from traffic network
   for(int i = 0; i< val1; i++){
        arrAirport[i].emptyList();
   }

   // check if val1 is greater than current size of array
   while(val1 > ARRAY_SIZE){
        // allocate new array for new size
        Airport* newArrAirport = new Airport[val1];
        // allocate each index of the array as linked list
        /*for(int i = 0; i < val1; i++){
            newArrAirport[i] = new Airport;
        }*/
        // set new identifier
        arrAirport = newArrAirport;
   }
    printf("Performing the resize command with %d.\n", val1);
 }

 void doInsert()
 {
    int val1 = 0;
    int val2 = 0;

   char* next = strtok (NULL, " \n\t");
   if ( next == NULL ){
        printf ("Integer value expected\n");
        return;
   }
   val1 = atoi ( next );

   if ( val1 == 0 && strcmp (next, "0") != 0){
        printf ("Integer value expected\n");
        return;
   }
   //  =====================================================
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL ){
        printf ("Integer value expected\n");
        return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0){
        printf ("Integer value expected\n");
        return;
   }
    // =====================================================

    // push airport as linked list in the index of array
    arrAirport[val1 - 1].push(val2);
    printf ("Performing the Insert Command from %d to %d.\n", val1, val2);
 }

 void doDelete(char *input)
 {
    int val1;
    int val2;

    char* next = strtok (NULL, " \n\t");
    if ( next == NULL ){
        printf ("Integer value expected\n");
        return;
    }
    val1 = atoi ( next );

    if ( val1 == 0 && strcmp (next, "0") != 0){
        printf ("Integer value expected\n");
        return;
    }
    //  =====================================================
    // get another integer value from the input
    next = strtok (NULL, " \n\t");
    if ( next == NULL ){
        printf ("Integer value expected\n");
        return;
    }
    val2 = atoi ( next );
    if ( val2 == 0 && strcmp (next, "0") != 0){
        printf ("Integer value expected\n");
        return;
    }
    // =====================================================
    // pop airport node in the linked list
    arrAirport[val1 - 1].pop(val2);
    printf("Performing Delete command from %d to %d\n", val1, val2);
 }

 void doList(char *input)
 {
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d: ", (i + 1));
        arrAirport[i].printList();      // print all nodes from the array
        printf("\n");
    }
 }

 // verify file name is not currently in use
 bool fileExists(const char* name){
    std::ifstream ifile(name);
    return (bool)ifile;
 }

 void doFile(char *input)
 {
   // get a filename from the input
   char* fname = strtok (NULL, " \n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }

   printf ("Performing the File command with file: %s\n", fname);

   // next steps:  (if any step fails: print an error message and return )
   //  1. verify the file name is not currently in use
   //  2. open the file using fopen creating a new instance of FILE*
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   //  4. close the file when processCommandLoop() returns

   // Part 1 - check if filename is not currently in use
   if(fileExists(fname)){
        printf("\t%c is currently in use!\n\n", fname);
        return;
   }

   // Part 2 - open file to create new instance of FILE
   FILE* pFile;
   pFile = fopen("myfile.txt", "r");    // open file for reading
   // check for file error
   if(pFile == NULL){
        printf("\n\tpFile did not open.\n"); // file did not open
        return;
   }

   // Part 3 - recursively call processCommandLoop
   FILE* inFile;
   inFile = fopen("myfile.txt", "r");
   // check for file error
   if(inFile == NULL){
        printf("\n\tinFile did not open.\n"); // file did not open
        return;
   }
   this->processCommandLoop(inFile);
   // runs and reads through the file
   while(input != NULL){
    if(fgets(filename, 100, pFile) != NULL){
        puts(filename);
    }
   }

   // Part 4 - close the inFile
   fclose(inFile);
 }
};

int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the airport adjcency list
  TravelNetwork airportData;

  // call the method that reads and parses the input
  airportData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  airportData.processCommandLoop (inFile);

  printf ("Goodbye\n");
  return 1;
 }
