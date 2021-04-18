#include<iostream>
// #include"screens/loading.cpp"
#include"screens/menu.cpp"

using namespace std;

int main()
{
    bool menuStart = true;
    while(menuStart)
    {
        system("cls");
        menuStart = Menu();
    }
    // Loading loading;
    // loading.start();
}