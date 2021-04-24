#include<iostream>
#include<fstream>
#include<thread>
#include<windows.h>
#include"menu.cpp"

using namespace std;

string Password = "";

void initState()
{
    ifstream password("password.txt");
    char p;
    getline(password,Password);
    password.close();
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
    thread t1(initState);
    loading();
    t1.join();
    while(menuStart)
    {
        system("cls");
        menuStart = Menu(Password);
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