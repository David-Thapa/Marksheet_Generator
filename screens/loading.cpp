#include<iostream>
#include<thread>
#include<windows.h>
#include"menu.cpp"

using namespace std;

void InitialFetch()
{
    //Waited for the value
    Sleep(2000);
    cout<<"Data Fetched";
}

class Loading
{
    bool menuStart = true;
    public:
    void loading();
    void start();
};

void Loading :: start()
{
    thread t1(InitialFetch);
    loading();
    t1.join();
    while(menuStart)
    {
        system("cls");
        menuStart = Menu();
    }
}

void Loading :: loading()
{
    for (int i = 0; i < 4; i++)
    {
        cout<<"\n\n\t\tLoading";
        for (int j = 0; j < 10; j++)
        {
            cout<<".";
            Sleep(100);
        }
        system("clear");
    }
}