#include <ncurses.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    initscr();
    printw("Hello World !!!");
    refresh();
    def_prog_mode();
    getch();
    endwin();
    system("/bin/bash");
    reset_prog_mode();
    refresh();
    printw("Another String\n");
    refresh();
    getch();
    endwin();

    return 0;
}
