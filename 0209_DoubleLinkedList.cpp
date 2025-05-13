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
}