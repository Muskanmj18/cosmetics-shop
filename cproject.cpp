#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void ins();
void display();
void update();
void del();
void order();
void disp();
class shop{
public:
    char name[30];
    char id[30];
    int quantity;
    int price;
    void input()
	{
    cout<<"\nEnter name of item: ";
    getchar();
    cin>>name;
    cout<<"\nEnter product id: ";
    cin>>id;
    cout<<"\nEnter Item price: ";
    cin>>price;
    cout<<"\nEnter item quantity: ";
    cin>>quantity;
    }
    void show(){
    cout<<id<<"\t"<<name<<"\t"<<price<<"\t"<<quantity<<endl;
    }
}s;
int main(){
char username[20]="Ganesh";
char id[10];
char user[10];
int pass;
int password=0000;
system("cls");
int op,choice;
cout<<"\nWelcome to cosmetics shop\n"<<endl;
cout<<"Press 1 if you are costumer \nPress 2 if you are owner\n";
cin>>choice;
if (choice == 1 ){
    system("cls");
    do{
    main:
    cout<<"\nhow may we help you:\n";
    cout<<"1.Order \n2.Menu\n3.queries\n4.Main menu\n";
    cout<<"0.Exit\n";
    cin>>op;
    switch(op){
    case 1:
        system("cls");
        order();
        break;
    case 2:
        system("cls");
        disp();
        break;
    case 3:
        cout<<"For your queries call on 8584692\n";
        break;
    case 4:
        goto main;
        break;
    case 0:
        cout<<"EXIT";
        exit(0);
        break;
    default:
        cout<<"\nInvalid option";
    }
    }while(op!=0);
}
else if(choice==2){
    system("cls");
    cout<<"\t\t\tAdmin login page \n\n";
    cout<<"Enter Username: ";
    getchar();
    cin.getline(user,20);
    cout<<"\nEnter password: ";
    cin>>pass;
    if(password==pass)
{
    system("cls");
    cout<<"\n\nChoose the option: "<<endl;
do{
    cout<<"\n1.Insert\n2.Display\n3.Update\n4.Delete\n0.Exit\n";
    cin>>op;
    switch(op){
case 1:
    system("cls");
    ins();
    break;
case 2:
    system("cls");
    display();
    break;
case 3:
    system("cls");
    display();
    update();
    break;
case 4:
    system("cls");
    display();
    del();
    break;
case 0:
    exit(1);
    break;
default:
    cout<<"\n Enter valid option";
    }

}while(op!=0);
}
else
{
    cout<<"incorect password";
}
}
return 0;
}
//insert function 
void ins()
{
fstream pr;
int ch=1;
cout<<"\t\tenter products\n\n"<<endl;
pr.open("ganesh.dat",ios::binary | ios::app);
if(!pr){
    cout<<"Can't open the file";
    return;
    }
while(ch){
    s.input();
    pr.write((char *)&s,sizeof(s));
    cout<<"\nPress 1 to enter more data else Press 0"<<endl;
    cin>>ch;
}
pr.close();
}
//display function
void display(){
fstream pr;
cout<<"\t\tItem in stock\n\n"<<endl;
pr.open("ganesh.dat",ios::binary | ios::in);
if(!pr){
    cout<<"Can't open the file";
    return;
    }
cout<<"\t\tId \t Name\t Price \t Quantity "<<endl;
cout<<"\t\t________________________________\n\n"<<endl;
while(pr.read((char *)&s,sizeof(s))){
cout<<"\t\t"<<s.id<<"\t"<<s.name<<"\t"<<s.price<<"\t"<<s.quantity<<endl;
}
pr.close();
}
//update function 
void update(){
char name[30],code[30];
int cho,countt=0,flag=0,up=0;
fstream pr;
pr.open("ganesh.dat",ios::binary | ios::in | ios::out);
pr.seekg(0);
if(!pr){
    cout<<"Can't open the file";
    exit(0);
    }
   cout<<"\nEnter item id :";
    getchar();
cin.getline(code,30);
   while(pr.read((char *)&s,sizeof(s)))
    {
     if((strcmp(s.id,code)==0))
    {
    flag=1;
    cout<<"\t\tId \t Name\t Price \t Quantity "<<endl;
    cout<<"\t\t_______________________________"<<endl;
    cout<<"\t\t"<<s.id<<"\t"<<s.name<<"\t"<<s.price<<"\t"<<s.quantity<<endl;
    cout<<"Enter Updated price and quantity of the item \n"<<endl;
    cout<<"Enter the quantity: ";
    cin>>s.quantity;
    cout<<"\nEnter the updated price of "<<s.name<<" :";
    cin>>s.price;
    pr.seekp(-sizeof(s),ios::cur);
    pr.write((char *)&s,sizeof(s));
    }
   }
    if(flag == 0){
        cout<<" Item is not found ";
    return;
    }

}
//delete function 
void del(){
    char pid[30];
    fstream obj("ganesh.dat",ios::binary | ios::in);
    fstream obj1("temp.dat",ios::binary | ios::out);
    obj.seekg(0);
    if(!obj || ! obj1){
        cout<<"Error in opening the file"<<endl;
        return;
    }
    else{
        cout<<"Enter item Id to delete: ";
            getchar();
            cin.getline(pid,30);
        while(obj.read((char *)&s,sizeof(s))){
            if(strcmp(s.id,pid)!=0){
             obj1.write((char *)&s,sizeof(s));
            }
        }
        obj.close();
        obj1.close();
    }
    remove("ganesh.dat");
    rename("temp.dat","ganesh.dat");
}
//order function
void order(){
fstream pr;
int flag=0,total=0,quantity,i=1;
char pay,idd[10];
pr.open("ganesh.dat",ios::binary | ios::in);
if(!pr){
    cout<<"Can't open the file";
    return;
    }
label1:
disp();
while(i==1){
    cout<<"Enter the order Id from the list: ";
        getchar();
        cin.getline(idd,10);
     while(pr.read((char *)&s,sizeof(s)))
    {
     if((strcmp(s.id,idd)==0))
    {
     flag=1;
    cout<<"\t\tId \t Name\t Price \t "<<endl;
    cout<<"\t\t_______________________________"<<endl;
    cout<<"\t\t"<<s.id<<"\t"<<s.name<<"\t"<<s.price<<"\t"<<endl;
     cout<<"How many "<<s.name <<" you want to order";
    cin>>quantity;
    total=total+(s.price*quantity);
    }
  }
cout<<"Press 1 to order more or Press 0 to exit: ";
cin>>i;
}
if(flag!=0){
    cout<<"\nWe've received your order: "<<endl;
    cout<<"Your order amount is "<<total;
  
        cout<<"\nYou will recieve your order in a moment please wait:  "<<endl;
  }
else {
    cout<<"Sorry we don't have this item:\n ";
   }
pr.close();
}
void disp(){
    fstream pr;
cout<<"\t\tItems available\n\n"<<endl;
pr.open("ganesh.dat",ios::binary | ios::in);
if(!pr){
    cout<<"Can't open the file";
    return;
    }
cout<<"\t\tId \t Name\t Price \t "<<endl;
cout<<"\t\t________________________________\n"<<endl;
while(pr.read((char *)&s,sizeof(s))){
cout<<"\t\t"<<s.id<<"\t"<<s.name<<"\t"<<s.price<<"\t"<<endl;
}
pr.close();
}
