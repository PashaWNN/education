#include <iostream>
#include <cstdlib>
#include <ncurses.h>

using namespace std;

const string items[4] = {
        "Get aknowledgements list",
        "Learn field of knowledge",
        "Get initial knowledge",
        "Identify knowledge quality"
};

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
int main()
{
    initscr();
    unsigned choice = 0;
    curs_set(0);
    keypad(stdscr, true);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while ( true )
    {
        clear();
        for ( unsigned i = 0; i < 4; i++ ) //Проходим по всем элементам меню
        {
            if ( i == choice )
                addch('>');
            else
                addch(' ');

            printw("%s\n", items[i].data());
        }
        switch ( getch() )
        {
            case KEY_UP:
                if ( choice )
                    choice--;
                break;
            case KEY_DOWN:
                if ( choice != 3 )
                    choice++;
                break;
        }
    }
#pragma clang diagnostic pop

    endwin();
    return 0;
}
#pragma clang diagnostic pop