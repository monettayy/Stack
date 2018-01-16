#ifndef STACKMENU_H
#define STACKMENU_H

#include <string>

#include "MYSTACK.H"

using namespace std;

class StackMenu
{
    public:
        StackMenu();

        enum Menu {Empty, Push, Pop, Peek, Print, Quit};

        void setChoice(int c)       { _choice = (Menu)(c - 1);}
        Menu getChoice()            { return _choice; }
        void displayItems();
        int selectedItem();
        bool tryAgain();
        char askChar();

        void process();

        virtual ~StackMenu();

    protected:

    private:
        Menu _choice;
        MyStack _stack;
        string getChoiceString();
};

#endif // STACKMENU_H
