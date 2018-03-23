//Marawan El Sharkawi
//CSCI 301-Section 1
//#cs301175
//Project 5

/*
Ordered lists are lists that holds items all arranged according to the value of each item after the other,
Linked List data structure is useful to implement ordered lists.This program uses an ordered list ADT in a class with a
linked list. The program uses this class to get offer a broad range of actions to perform on the list.

 The program uses five data structures:

•   One class object with linked lists which has all the required functions to get the actions done chosen by the user.

•	Two integer variables in the main program called "quit" which acts like an exit key when incremented and the other called
 "number" to get the integer input from the user and pass this variable to different functions.

•   One char variable called "choice" to get the choice of the action the user want to implement on the list.

•	Node which is of the building units of the linked lists where each integer lies in a node and a pointer points to that node
and another points to the next node to form the linked list.

•	Linked lists to hold the content of the ordered list.


The program uses eight functions:
•	make_list_empty( ):It makes a list which already has integers inside it empty.

•	insert ( const Item& entry ): It takes a constant item passed by reference as a parameter and it inserts the value of that
item in a list by creating node and saving these values inside them.

•	remove( const Item& entry ): It takes a constant item passed by reference as a parameter and it removes this item from the
 linked list.

•	length( ): It gets the length of the list (how many items in the list).

•   kth(int k): It gets the value of th kth value in the list.

•	exists( const Item& target ): It take a constant item passed by reference as a parameter and it checks if a given integer
exists in the list.

•	get_node ( const Item& entry, Node* link ): It takes a constant item passed by reference and a Struct Node as parameter and
it creates a new node and puts this item in it.

•   menu( ): It prints the menu options for the user to choose from.

The program creates one List class object, two integer variables and one char variable. It shows the user the menu with options
to choose from and asks the user to choose an option from the list. It read the user's input and apply the action the user
has chosen on the list, the program after that shows the menu options again and asks the user to choose an action. It repeats
this process until the user decides to quit the program.The program also checks if the user has entered a wrong menu option
and asks the user to renter a correct menu option every time the user enters a wrong menu option.

*/

#include <iostream>
#include"Linked_List.h"
using namespace std;
void menu(){ //Prints the menu options for the user to choose from,
            //post-condition: The menu has been printed to the user and the user is ready to choose an action from the menu.
cout<<endl;
cout<<"e -- Re-initialize the list to be empty."<<endl;
cout<<"i -- Insert an integer into the list."<<endl;
cout<<"r -- Remove certain integer from the list."<<endl;
cout<<"c -- Check if the list is empty."<<endl;
cout<<"l -- Check how many integers are in the list."<<endl;
cout<<"p -- Check if a certain integer is present in the list"<<endl;
cout<<"k -- Report the kth value in the list."<<endl;
cout<<"w -- Print out the content of list."<<endl;
cout<<"h -- See this menu."<<endl;
cout<<"q -- Quit."<<endl;
cout<<"Please enter the letter of the command in the list you want to perform: ";
}

int main()
{
    List l;
    int quit=0;
    int number;
    char choice;

    while(quit==0){
       menu();
       cin>>choice;
       cout<<endl;
       switch(choice){

   case 'e':
       l.make_empty();
       cout<<"The list has been re-initialized to be empty successfully."<<endl;
        break;

   case 'i':
        cout<<"Please enter the integer you want to place in the list: ";
        cin>>number;
        l.insert(number);
        cout<<"The integer has been placed in the list successfully."<<endl;
        break;

   case 'r':
        cout<<"Please enter the integer you want to remove from the list: ";
        cin>>number;
        if(l.exists(number)==true){
        l.remove(number);
        cout<<"The integer has been removed from the list successfully."<<endl;
        }else{
        cout<<"The integer you entered already is not in the list."<<endl;
        }
        break;

   case 'c':
        if(l.empty()==true){
            cout<<"The list is empty."<<endl;
        }else{
            cout<<"The list is not empty."<<endl;
        }
        break;

   case 'l':
        cout<<"There are "<<l.length()<<" integer/s in the list."<<endl;
        break;

   case 'p':
        cout<<"Please enter the integer you want to check if it is present the list: ";
        cin>>number;
        if(l.exists(number)==true){
            cout<<number<<" is present in the list."<<endl;
        }else{
            cout<<number<<" is not present in the list."<<endl;
        }
        break;

   case 'k':
        cout<<"Please enter the kth value you want to know from the list: ";
        cin>>number;
        if(l.length()==0){
            cout<<"There are no integers in the list to show the kth value of."<<endl;
        }else{
        cout<<"The "<<number<<"th value in the list is "<<l.kth(number)<<endl;
        }
        break;

   case 'w':
       if(l.length()!=0){
        cout<<"The list: "<<l<<endl;
       }else{
       cout<<"There are no elements in the list to print out."<<endl;
       }
        break;

   case 'h': break;

   case 'q':
        cout<<"Thanks for using the List program come back again :)"<<endl;
        quit++;
        break;

   default :
        cout<<"You entered a letter choice not from the choices in the list please enter a valid letter option."<<endl;

       }

    }

    return 0;
}
