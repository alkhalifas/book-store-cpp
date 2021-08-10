#include <iostream>                                // Add header files
#include <string.h>
#include <stdlib.h>


using namespace std;                               // Using the standard namespace

class book {                                       // Class name
private:                                           // Access profiler private/public
    char *author, *title, *publisher;              // Pointer declaration
    float *price;
    int *stock;

public:                                            // Access profiler private/public
    book() {
        author= new char[20];                      // Dynamically allocates a char[20] (array of char, length 20)
        title=new char[20];
        publisher=new char[20];
        price=new float;
        stock=new int;
    }
    void feedData();
    void editData();
    void showData();
    int search(char[],char[]);
    void buyBook();
};

void book::feedData()	{
    cin.ignore();
    cout<<"\nEnter Author Name: ";      cin.getline(author,20);
    cout<<"Enter Title Name: ";       cin.getline(title,20);
    cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
    cout<<"Enter Price: ";            cin>>*price;
    cout<<"Enter Stock Position: ";   cin>>*stock;

}

void book::editData()	{

    cout<<"\nEnter Author Name: ";      cin.getline(author,20);
    cout<<"Enter Title Name: ";       cin.getline(title,20);
    cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
    cout<<"Enter Price: ";            cin>>*price;
    cout<<"Enter Stock Position: ";   cin>>*stock;
}

void book::showData()	{
    cout<<"\nAuthor Name: "<<author;
    cout<<"\nTitle Name: "<<title;
    cout<<"\nPublisher Name: "<<publisher;
    cout<<"\nPrice: "<<*price;
    cout<<"\nStock Position: "<<*stock;
}

int book::search(char tBuy[20],char aBuy[20] )	{
    if(strcmp(tBuy,title)==0 && strcmp(aBuy,author)==0)
        return 1;
    else return 0;
}

void book::buyBook()	{
    int count;
    cout<<"\nEnter Number Of Books to buy: ";
    cin>>count;
    if(count<=*stock)	{
        *stock=*stock-count;
        cout<<"\nBooks Bought Successfully";
        cout<<"\nAmount: Rs. "<<(*price)*count;
    }
    else
        cout<<"\nRequired Copies not in Stock";
}


int main()	{
    book *B[20];
    int i=0,r,t,choice;
    char titleBuy[20],authorBuy[20];
    while(1)	{
        cout<<"\n\n\t\tMENU"
        <<"\n1. Entry of New Book"
        <<"\n2. Buy Book"
        <<"\n3. Search For Book"
        <<"\n4. Edit Details Of Book"
        <<"\n5. Exit"
        <<"\n\nEnter your Choice: ";
        cin>>choice;

        switch(choice)	{
            case 1:	B[i] = new book;
            B[i]->feedData();
            i++;	break;

            case 2: cin.ignore();
            cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
            cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);
            for(t=0;t<i;t++)	{
                if(B[t]->search(titleBuy,authorBuy))	{
                    B[t]->buyBook();
                    break;
                }
            }
            if(t==1)
                cout<<"\nThis Book is Not in Stock";

            break;
            case 3: cin.ignore();
            cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
            cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);

            for(t=0;t<i;t++)	{
                if(B[t]->search(titleBuy,authorBuy))	{
                    cout<<"\nBook Found Successfully";
                    B[t]->showData();
                    break;
                }
            }
            if(t==i)
                cout<<"\nThis Book is Not in Stock";
            break;

            case 4: cin.ignore();
            cout<<"\nEnter Title Of Book: "; cin.getline(titleBuy,20);
            cout<<"Enter Author Of Book: ";  cin.getline(authorBuy,20);

            for(t=0;t<i;t++)	{
                if(B[t]->search(titleBuy,authorBuy))	{
                    cout<<"\nBook Found Successfully";
                    B[t]->editData();
                    break;
                }
            }
            if(t==i)
                cout<<"\nThis Book is Not in Stock";
            break;

            case 5: exit(0);
            default: cout<<"\nInvalid Choice Entered";

        }
    }
    return 0;
}
