#include<iostream>
#include"screens/menu.cpp"

using namespace std;

int main()
{
    bool menuStart = true;

    while(menuStart)
    {
        system("clear");
        menuStart = menu();
    }
}