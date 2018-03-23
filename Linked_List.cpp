#include<iostream>
#include"Linked_List.h"
using namespace std;

List:: ~List(){ //Destructor

Node *temp;

while(first!=NULL){ //While the first node holds an integer.
temp = first; //make the temporary empty node equal to the first node.
first = first->next; //the first node now is the one next to it.
delete temp; //delete the temporary node.
}

}

void List:: make_empty(){ //It makes a list which already has integers inside it empty.
                        //post-condition: a list which already has integers inside it now is empty.

Node *temp;

while (first!=NULL){ //while the first node has an integer saved in it.

temp=first; //the temporary node equals the first node.
first= first->next; //the first node now is the one next to it.
delete temp; //delete the temporary node.

}

}

void List:: insert(const Item &entry){ //It inserts values in a list by creating node and saving these values inside them.
                                        //post-condition: An integer has been added in order to the list.

Node *prev;

if(exists(entry)==true){ //check if the integer required to be added is already in the list.

    remove(entry);  //if it is in the list delete it.
}

if(first==NULL || entry<first->data){ //If the first node is NULL or the value of the integer is less than the value of the
                                    //integer in the first node, create a new node and put the new value in it and
                                    // make it the first node.

    first=get_node(entry, first);
}else{

prev = first; //make the previous node equals the first node.

while(prev->next != NULL && prev->next->data<entry) //while the node after the previous node is not NULL and
                                                    // the node after the previous node has integer value less than
                                                    //the value of the new integer. Make the previous node equals
                                                    //to the node after it and make a new node with the value of the
                                                    //new integer in the position of the node has just been shifted.
    prev = prev->next;

prev->next=get_node(entry,prev->next);

}
}

void List:: remove(const Item &entry){ //Removes certain integer from the linked list.
                                    //Post-Condition: the specified integer has been removed from the list
                                    //and the list has been reordered.

Node *prev;
Node *temp;

if(exists(entry)==true){ //if the specified integer exists in the list.

   if(first->data == entry){ //if the value of the integer of the previous node equals the value of the specified integer.

    temp = first; //make the temporary node from that integer equal to first node in the list.
    first= first->next; //make the first node equals to to the one after it.
    delete temp; //delete the temporary node.

   }else{

   prev = first; //make the previous node from that integer equal to first node in the list.

   while(prev->next !=NULL && prev->next->data<entry) //while the previous node is not NULL and the value of the integer
                                                    //inside the next node is smaller than the specified integer.

    prev= prev->next; //make the previous node equals to the next node.

   temp= prev->next; //also make the temporary node equals the next node.
   prev->next = temp->next; //the previous node equals to the node which the temporary node points to.
   delete temp; //delete the temporary node.


   }
}

}

int List:: length()const{ //Gets the length of the list (how many items in the list)
                        //post-condition: the number of items in the list has been returned.

Node *cursor;
int count=0;

cursor=first;

while(cursor!=NULL){

    cursor= cursor->next;
    count++;

}

return count;

}

bool List:: exists(const Item &entry)const{ //check if a given integer exists in the list.
                                            //post-condition: the function has checked if a certain integer exists in the list.

Node *cursor;

cursor=first;

while (cursor!=NULL && cursor->data!=entry){
    cursor= cursor->next;
}
    return (cursor!=NULL);


}

List::Item List::kth(int k)const{ //Tells the user the kth integer in the list.
                                //post-condition: The kth item in the list has been identified and returned by the function.

  Node *cursor;

  if(k>length() || k==0){

    return NULL;
  }

if(1<=k && k<=length()){

    cursor = first;

    for(int i=1; i<k; i++)
        cursor = cursor->next;

}
   return cursor->data;
}

ostream &operator <<(ostream &out_put, const List &l){ //assigns the << operator to be able to print out the List class.

List::Node *cursor;

cursor=l.first;

out_put<<"(";

while(cursor!=NULL && cursor->next!=NULL){
    out_put<<cursor->data<<", ";
    cursor=cursor->next;

}

if(cursor !=NULL){
    out_put<<cursor->data;
}
    out_put<<")";

    return out_put;
}

List::Node* List::get_node(const Item &entry, Node* link){ //creates a new node.
                                                        //post-condition: a new node has been created.

    Node *temp;

    temp= new Node;
    temp->data = entry;
    temp->next = link;

    return temp;

}






