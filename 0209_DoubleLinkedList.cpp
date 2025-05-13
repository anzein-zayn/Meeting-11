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
        newNode -> previous = NULL;
    }
}