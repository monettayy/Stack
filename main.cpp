#include <iostream>

#include "MyStyle.h"
#include "MYSTACK.H"
#include "StackMenu.h"

using namespace std;

int main()
{
    MyStyle::fullScreen();
    StackMenu menu;

    do
    {
        MyStyle::titleText("Using a Pointer to Manage A Stack DS");
        menu.displayItems();

        menu.setChoice(menu.selectedItem());

        if(menu.getChoice() == StackMenu::Quit)
            break;

        system("cls");
        menu.process();

    }while(menu.getChoice() != StackMenu::Quit);

    MyStyle::centerText("Thank you for using this application . . .");
    return 0;
}
