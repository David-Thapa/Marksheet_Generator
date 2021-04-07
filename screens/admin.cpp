#include<iostream>

using namespace std;

void Admin()
{
    bool logedIn = true;
    int choice;
    while(logedIn)
    {
        system("clear");
        cout<<"1. Add Marksheet.\n2. Update Marksheet\n3. SignOut"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            logedIn = true;
            break;

            case 2:
            logedIn = true;
            break;

            case 3:
            logedIn = false;
            break;

            default:
            logedIn = true;
        }
    }
}