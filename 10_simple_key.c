#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

static int startx = 0;
static int starty = 0;

static char *choices[] = {
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit"
};

static int n_choices = sizeof(choices) / sizeof(char *);
static void print_menu(WINDOW *menu_win, int highlight);

int main(int argc, char const *argv[]) {
    WINDOW *menu_win;
    int highlight = 1, choice = 0, c;

    initscr();
    clear();
    noecho();
    cbreak();
    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    print_menu(menu_win, highlight);

    while (1) {
        c = wgetch(menu_win);
        switch (c) {
        case KEY_UP:
            if (highlight == 1)
                highlight = n_choices;
            else
                --highlight;
            break;
        case KEY_DOWN:
            if (highlight == n_choices)
                highlight = 1;
            else
                ++highlight;
            break;
        case 10:
            choice = highlight;
            break;
        default:
            mvprintw(24, 0, "Charcter pressed is = %3d, Hopefully it can be pressed", c);
            refresh();
            break;
        }
        print_menu(menu_win, highlight);
        if (choice != 0)
            break;
    }
    mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
    clrtoeol();
    refresh();
    endwin();
    return 0;
}

void print_menu(WINDOW *menu_win, int highlight) {
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (i = 0; i < n_choices; ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        } else {
            mvwprintw(menu_win, y, x, "%s", choices[i]);
        }
        ++y;
    }
    wrefresh(menu_win);
}