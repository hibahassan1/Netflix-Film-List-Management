#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

//Creating a node
struct Node{
    string film;
    Node*next;
    
    Node(string f){
        film=f; 
        next=NULL;
    }
   };
   
struct Node* head;

//Adding a new node
void addFilm(string f){

Node* temp=new Node(f);

temp->film=f;
temp->next=NULL;
if(head==NULL){
    head=temp;
}
else{
    Node* temp1=head;
    //Traversing to the last element
    while(temp1->next!=NULL)
    temp1=temp1->next;

    //Changing the last element to new one
    temp1->next=temp;
}
}


//Method to find the size of the linked list
int size(){
int count=0;
Node* temp=head;
while(temp!=NULL){
    count++;
    temp=temp->next;
}
return count;
}

//Adding a new node at a specific position
void addfilmatn(int pos,string f){
    Node* temp;
    Node* newnode=new Node(f);
    int i=1;
    int length=size();
    //Checking if position is greater than the length of the linked list
     if(pos>length && pos<1){
    cout<<"Index out of bounds\n";
     }
    else if(pos==1){
    Node* temp1=new Node(f);
    temp1->next=head;
    head=temp1;;
    }
    else{
    temp=head;
    //Traversing the list till the second last node
    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }}
    

//Method to display the film list
void displayFilmlist(){
    Node *temp=head;
   int count=size();
   if(head==NULL){
    cout<<"The film list is empty"<<endl;
    return;
    }
   
   //Loop to print the list
    for(int i=1;(i<=count && temp!=NULL);i++){
    cout<<i<<"."<<temp->film<<endl;
    temp=temp->next;
    }
    
}

//Finding a specific node by ID
void findatpos(int pos){
    Node* nextnode;
    Node* temp;
    temp=head;
    int i=1;
    //If position is 1 then print the head
    if(pos==1){
        cout<<head->film<<endl;
    }
    else{
    //Traversing till the second last element
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    cout<<nextnode->film<<endl;
    }   
}


//Deleting a node by ID
void removeatpos(int pos){
    Node* nextnode;
    Node* temp;
    temp=head;
    int i=1;
    if(head==NULL){
    cout<<"The film list is empty"<<endl;
    return;
    }
    else if(pos==1){
        Node* temp1=head;
        head=head->next;
        delete temp1;
    }
   else{ 
    while(i<pos-1){
    temp=temp->next;
    i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;
    delete nextnode;
   }    
}

//Delete all
void removethefilmlist()
{
    if(head==NULL){
    cout<<"The list is already empty\n";
}
else{
    head = NULL;
    cout<<"The list has been deleted\n";
}
}

//Sorting alphabetically using bubble sort
//Method to swap
void swap(Node *a, Node *b)
{
    string temp = a->film;
    a->film = b->film;
    b->film = temp;
}
//Method to sort
void alphabetically()
{
    //Checking if the list is empty
    if(head==NULL) 
    return;
    int s, i;
    Node *temp;
    Node *temp1 = NULL;
    do
    {
        s = 0;
        temp = head;
        while (temp->next != temp1)
        {
            if (temp->film > temp->next->film)
            {
                swap(temp, temp->next);
                s = 1;
            }
            temp = temp->next;
        }
        temp1 = temp;
    }
    while (s);
}

//Check if the list is empty
void checkEmpty(){
if(head==NULL){
    cout<<"The list is empty\n";
}
else{
    cout<<"The list is not empty\n";
}
}

//Save to file
void savetofile(){
    Node *temp=head;
    int count=size();
    ofstream file;
    file.open ("output.txt");
    for(int i=1;(i<=count && temp!=NULL);i++){
        file<<i<<"."<<temp->film<<endl;
        temp=temp->next;
}
    file.close();
}

//Load from file
void loadfromfile(){
   ifstream file("input.txt");
    string film; 
    while (getline(file, film))
    {
        addFilm(film);
    }
    cout<<"Enter 3 to check the list.\n";

}

//Method to display choices
void displayChoices(){
    cout<<"-------------------------------------\n";
    cout<<"         NETFLIX FILM LIST          \n";
    cout<<"-------------------------------------\n";
    cout<<"   Enter the number option : \n";
    cout<<"1. Add a film\n";
    cout<<"2. Add a film at a certain position\n";
    cout<<"3. Display the filmlist\n";
    cout<<"4. Enter the index of film to find it\n";
    cout<<"5. Enter the index of film to delete it \n";
    cout<<"6. Delete the entire list\n";
    cout<<"7. Arrange the films alphabetically\n";
    cout<<"8. Check if the list is empty\n";
    cout<<"9. Save to file\n";
    cout<<"10. Load from file\n";
    cout<<"11. Exit\n";
    cout<<"-------------------------------------\n";
    }
   
   
int main(){
    int choice;
    string film;
    int pos;
    //displayChoices();

    do{
       displayChoices();
       cin>>choice;
        switch(choice){ 
            case 1: cout<<"Enter the film name:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, film);
            addFilm(film);
            break;
            case 2: cout<<"Enter position: ";
            cin>>pos;
            cout<<"Enter the film name:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, film);
            addfilmatn(pos,film);
            break;
            case 3:displayFilmlist();
            break;
            case 4: cout<<"Enter index: ";
            cin>>pos;
            findatpos(pos);
            break;
            case 5: cout<<"Enter index: ";
            cin>>pos;
            removeatpos(pos);
            break;
            case 6:removethefilmlist();
            break;
            case 7: alphabetically();
            displayFilmlist();
            break;
            case 8: checkEmpty();
            break;
            case 9:savetofile();
            break;
            case 10: loadfromfile();
            break;
        }
    }while(choice!=11);

}