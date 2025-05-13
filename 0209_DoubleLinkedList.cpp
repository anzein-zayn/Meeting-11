#include <iostream>
using namespace std;

//membuat struktur untuk object double LinkedList
struct Node
{
    //deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    //deklarasi pointer nest dan pref untuk penunjukan daa sebelum dan sesudah'
    Node *next;
    Node *previous;
};

// deklarasi pinter START dan pemberian nilai
Node *start = NULL;

void addNode()
{
    //pembuatan node dan pemberian value untuk data noMhs dan name
    Node *newNode = new Node();
    cout << "\nEnter the roll number of the Student: ";
    cin >> newNode-> noMhs;
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name;

    //Insert the new node in the list
    //kondisi jika start == null atau noMhs node baru <= noMhs start
    if (start == NULL || newNode->noMhs <= start-> noMhs)
    {
        //step 2: insert the new node at the beginning
        //kondisi jika start tidak kosong dan noMhs node baru sama dengan noMhs Lama
        if (start != NULL && newNode ->noMhs == start->noMhs)
        {
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" <<endl;
            return;
        }

        //jika listnya kosong, membuat new node nya adalah START
        newNode->next = start;
        //kondisi jika start tidak memiliki nilai atau tidak kosong
        if (start != NULL)
        {
            start -> previous = newNode;
        }
        //memberi nilai prev = null dan start = node baru
        newNode -> previous = NULL; //membuat new node point ke NUll
        start = newNode;
    }
    //kondisi jika semua kondisi if tidak terpenuho
    else
    {
        //set nilai current = start dan nilai prev =null
        Node *current =start; //step 1.a start from the first node
        Node *previous = NULL; //step 1.b previous node is NULL initially

        //looping selama current != null dan noMhs dari current lebih kecil dari noMhs dari newNode
        while (current != NULL && current ->noMhs < newNode->noMhs)
        {
            previous = current; // memindahkan previous ke current
            current = current -> next; // memindahkan current ke next node
        }

        //set nilai next node baru = current dan prev node baru = previous
        newNode->next = current; // Make the next field of the new node
        newNode-> previous = previous; // Make the previous field of the new node

        //kondisi jjika current tidak sama dengan null
        if (current != NULL)
        {
            current -> previous = newNode;
        }

        if (previous != NULL)
        {
            previous->next = newNode;
        }
        else
        {
            start = newNode; 
        }
    }
}

//pembuatan function search untuk mencari data
bool Search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = start;

    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current) ->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node *previous, *current;
    int rollNo;

    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    if (start == NULL)
    {
        cout << "List is empty" <<endl;
        return;
    }

    current = start;
    previous = NULL;

    while (current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current =current ->next;
    }

    if (current == NULL)
    {
        cout << "\033[31mThe record with roll number " << rollNo << "not found\033[0m" << endl;
        return;
    }

    if (current = start)
    {
        start = start->next;
        if(start != NULL)
        {
                start-> previous = NULL;
        }
    }
    else
    {
        previous ->next = current->next;
        if (current ->next != NULL)
        {
            current ->next ->previous = previous;
        }
    }

    delete current;
    cout << "x1b[32mRecord with roll number " <<rollNo <<"deleted\x1b[0m"<<endl;
}

bool listEmpty()
{
    return (start ==NULL);
}

void traverse()
{
    if (listEmpty())
    {
        cout << "\nList Kosong\n";
    }
    else
    {
        cout << "\nData didalam list adalah :\n";
        Node *currentNode = start;
        while (currentNode !=NULL)
        {
            cout << currentNode->noMhs <<endl;
            currentNode = currentNode->next;
        }
        cout <<endl;
    }
}

void retraverse()
{
    if(listEmpty())
        cout << "\nList is empty" << endl;
    else
    {
        cout << "\nRecords in descending order of roll number are: " <<endl;
        Node *currentnode = start;
        while ( currentnode ->next != NULL)
            currentnode = currentnode->next;

        while (currentnode != NULL)
        {
            cout << currentnode->noMhs << " " << currentnode->name <<endl;
            currentnode= currentnode ->previous;
        }
    }

}

void searchData()
{
    if(listEmpty())
    {
        cout << "\nList is empty" <<endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record you want to search: ";
    int num;
    cin>> num;
    if (Search(num, &prev, &curr) == false)
        cout << "\nRecord not found" <<endl;
    else{
        cout << "\nRecourd found" << endl;
        cout << "\nRoll number : " << curr ->noMhs <<endl;
        cout << "\nName : " << curr ->name <<endl;
    }

}