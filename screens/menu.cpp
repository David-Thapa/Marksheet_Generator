#include<iostream>
#include"admin.cpp"
#include"search.cpp"

using namespace std;

bool Menu()
{
    int choice;
    cout<<"1. Search Student.\n2. Admin.\n3. Exit"<<endl;
    cout<<"Enter you choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        system("clear");
        Search();
        return true;

        case 2:
        
        Admin();
        return true;

        case 3:
        return false;

        default:
        return true;
    }
}