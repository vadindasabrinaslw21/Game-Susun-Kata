#include <ncurses/ncurses.h>
using namespace std;

int main() {
    initscr();
    mvprintw(12, 40, "Hello World!");
    refresh();
    getch();
    endwin();
    return 0;
}