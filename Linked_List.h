#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
using namespace std;
class List{

public:
    typedef int Item; // What can go in a list

    List(){first=NULL;}

    ~List();

    void make_empty();
    void insert(const Item &entry);
    void remove(const Item &entry);
    bool empty()const {return first==NULL;}
    int length() const;
    bool exists(const Item &entry) const;
    Item kth(int k) const;
    void print();
    friend ostream &operator << (ostream &out_put, const List &l);

private:
    struct Node{

    Item data;
    Node *next;

    };

    Node *first;

    Node* get_node(const Item &entry, Node *link);

};

#include"Linked_List.cpp"
#endif // LINKED_LIST_H_INCLUDED
