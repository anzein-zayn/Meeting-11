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