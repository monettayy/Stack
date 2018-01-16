#include <iostream>
#include <limits>
#include <string>
#include <windows.h>

#include "MYSTACK.H"
#include "MyStyle.h"
#include "StackMenu.h"

using namespace std;

StackMenu::StackMenu()
{
    //ctor
}

string StackMenu::getChoiceString()
{
    switch(_choice)
    {
        case Empty: return "Empty";
        case Push:  return "Push";
        case Pop:   return "Pop";
        case Peek:  return "Peek";
        case Print: return "Print";
    }
}

void StackMenu::displayItems()
{
    MyStyle::centerText("STACK MENU");
    MyStyle::centerText("[1] Empty", 9);
    MyStyle::centerText("[2] Push", 9);
    MyStyle::centerText("[3] Pop", 9);
    MyStyle::centerText("[4] Peek", 9);
    MyStyle::centerText("[5] Print", 9);
    MyStyle::centerText("[6] Quit\n", 9);
}

int StackMenu::selectedItem()
{
    int input;
    MyStyle::centerTextAsk("Enter your choice [ ]? ");

    //continuously ask choice until input is valid
    while(!(cin >> input) || (input < 1 || input > 6)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        MyStyle::centerTextAsk("Enter your choice [ ]? ");
    }

    return input;
}

bool StackMenu::tryAgain()
{
    string input;
    cout << endl;
    MyStyle::centerTextAsk("Do you want to try again? [y if yes] ");
    cin >> input;
    return input == "y" || input == "Y";
}

char StackMenu::askChar()
{
    char input;
    MyStyle::centerTextAsk("Enter value to push: ");
    cin >> input;
    return input;
}

void StackMenu::process()
{
    MyStyle::titleText("Stack " + getChoiceString());

    switch(_choice)
    {
        case Empty:
        {
            if(!_stack.isEmpty())
                _stack.emptyStack();

            MyStyle::centerText("Stack is now empty");
        }
        break;
        case Push:
        {
            _stack.push(askChar());
            _stack.print();
        }
        break;
        case Pop:
        {
            if(_stack.isEmpty())
                MyStyle::centerText("Stack is now empty");
            else
            {
                char poped = _stack.pop();
                MyStyle::centerTextAsk("Pop: ");
                cout << poped << endl;
                _stack.print();
            }
        }
        break;
        case Peek:
        {
            if(_stack.isEmpty())
                MyStyle::centerText("Stack is now empty");
            else
            {
                char peek = _stack.peek();
                MyStyle::centerTextAsk("Peek: ");
                cout << peek << endl;
                _stack.print();
            }
        }
        break;
        case Print:
            _stack.print();
            break;
    }
}

StackMenu::~StackMenu()
{
    //dtor
}
