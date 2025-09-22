/*                                                                                                 1                   1                   1
         1         2         3         4         5         6         7         8         9         0                   2                   4
12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890*/

#include <stdio.h>                                             // i/o printf() scanf(): /usr/include
#include <stdlib.h>                                          // malloc() atoi() rand(): /usr/include
#include <string.h>                        // string functions (strcmp() used re argv): /usr/include
#include <unistd.h>                                                // sleep() usleep(): /usr/include
#include <ncursesw/ncurses.h>                        // ncurses w UTF-8 chars: /usr/include/ncursesw
#include <locale.h>                                                   // UTF-8 support: /usr/include
#include <wchar.h>                                                    // UTF-8 support: /usr/include
#include <time.h>                                                    // seeding rand(): /usr/include
#include <ctype.h>                                            // isalpha, isdigit, etc: /usr/include

int mode = 16;
int colorpair = 2;
char mixcolor = 'n';

int help() {

    char answer = 'y';
    int i = 0, n = 0;

    printf("\nd_rain 0.01 digital rain in the terminal\n\n");
    printf("usage: d_rain <256> <color>\n\n");
    printf("All parameters are optional. By default,\n");
    printf("d_rain uses monochrome green trails. The\n");
    printf("numeral 256 is for 256-color mode.\n\n");
    printf("Colors available:\n\n");
    printf("r red          y yellow\n");
    printf("g green        c cyan\n");
    printf("b blue         m magenta\n");
    printf("               x mix\n\n");
    printf("For example   d_rain 256 g   will use 255\n");
    printf("shades of green plus white.\n\n");
    printf("Test your terminal for 256 color mode (y/n)? ");

    scanf(" %c", &answer);
        if (answer == 'n') {
            return EXIT_SUCCESS;
        }

        initscr();
        noecho();
        cbreak();
        curs_set(0);
        if (has_colors()) {
            printw("\nThe terminal supports color.\n");
            start_color();
            printw("\nNumber of colors available      = %d\n", COLORS);
            printw("Number of color pairs available = %d\n\n", COLOR_PAIRS);
            if (can_change_color()) {
                printw("The default colors can be changed.\n\n");
            }
            printw("The next screen will display the default colors.\n\n");
            printw("any key to continue...");
            getch();
            clear();
            for (i = 0; i < 256; i++) {
                init_pair(i, i, 0);                        // syntax: init pair(pair_number,
            }                                              // foreground_color, background_color)
    
            for (i = 0; i < 16; i++) {
            attron(COLOR_PAIR(i));                                // first 16 are "the basic 8" then
            attron(A_REVERSE);                                    // "the basic 8" when the A_BOLD
            printw("  Color # %3d  ", i);                         // attribute is turned on
            attroff(COLOR_PAIR(i));
            }

            for (n = 0; n < 40; n++) {
                for (i = 16 + n * 6; i < 22 + n * 6; i++) {
                    attron(COLOR_PAIR(i));
                    attron(A_REVERSE);              // A_REVERSE used to show more color; black text
                    printw("  Color number %3d ", i);  // on color rather than colored text on black
                    attroff(COLOR_PAIR(i));
                }
            printw("\n");
            }
        attroff(A_REVERSE);
        attron(COLOR_PAIR(0));
        move(LINES - 1, (COLS/2) - 12);
        printw("any key to exit...");
        getch();
        endwin();
        return EXIT_SUCCESS;
        } else { printw("\nThe terminal does not support color.\n");
          }
        endwin();
        return EXIT_FAILURE;

}

wchar_t getRndmWChar() {                                                // START getRndmWChar()

    wchar_t rndmWChar = L'\0';

    switch (rand() % 32) {
        case 0:
            rndmWChar = L'Բ';
            break;
        case 1:
            rndmWChar = L'Գ';
            break;
        case 2:
            rndmWChar = L'Դ';
            break;
        case 3:
            rndmWChar = L'Ե';
            break;
        case 4:
            rndmWChar = L'Զ';
            break;
        case 5:
            rndmWChar = L'Է';
            break;
        case 6:
            rndmWChar = L'Ը';
            break;
        case 7:
            rndmWChar = L'Թ';
            break;
        case 8:
            rndmWChar = L'Ժ';
            break;
        case 9:
            rndmWChar = L'Ի';
            break;
        case 10:
            rndmWChar = L'Խ';
            break;
        case 11:
            rndmWChar = L'Ծ';
            break;
        case 12:
            rndmWChar = L'Կ';
            break;
        case 13:
            rndmWChar = L'Հ';
            break;
        case 14:
            rndmWChar = L'Ձ';
            break;
        case 15:
            rndmWChar = L'Ճ';
            break;
        case 16:
            rndmWChar = L'Յ';
            break;
        case 17:
            rndmWChar = L'Ն';
            break;
        case 18:
            rndmWChar = L'Շ';
            break;
        case 19:
            rndmWChar = L'Չ';
            break;
        case 20:
            rndmWChar = L'Պ';
            break;
        case 21:
            rndmWChar = L'Ջ';
            break;
        case 22:
            rndmWChar = L'Վ';
            break;
        case 23:
            rndmWChar = L'Ց';
            break;
        case 24:
            rndmWChar = L'Ֆ';
            break;
        case 25:
            rndmWChar = L'բ';
            break;
        case 26:
            rndmWChar = L'է';
            break;
        case 27:
            rndmWChar = L'ժ';
            break;
        case 28:
            rndmWChar = L'խ';
            break;
        case 29:
            rndmWChar = L'ճ';
            break;
        case 30:
            rndmWChar = L'փ';
            break;
        case 31:
            rndmWChar = L'ֆ';
            break;
    }
    return rndmWChar;
}                                                                             // END getRandomChar()


void drawTrails() {                                                           // START draw_trails()

    wchar_t wChar;
    wchar_t wCharWhtSpc = L' ';                                                  // wchar whitespace
    cchar_t cChar;
    cchar_t cCharWhtSpc;                                                         // cchar whitespace
    setcchar(&cCharWhtSpc, &wCharWhtSpc, A_NORMAL, 0, 0);     // wchar whitespace ➜ cchar whitespace

    int j = 0;                                                    // tmp int for loop counters, etc.

    int fall[10];
    int startingLine[10];
    int rndmCol[10];

// Black       0, 0, 0          Gray        128, 128, 128        default basic 8 colors:
// Red         255, 0, 0        Orange      255, 165, 0          black   0    blue     4
// Green       0, 255, 0        Purple      128, 0, 128          red     1    magenta  5
// Blue        0, 0, 255        Light Gray  211, 211, 211        green   2    cyan     6
// Yellow      255, 255, 0      White       255, 255, 255        yellow  3    white    7
// Cyan        0, 255, 255
// Magenta     255, 0, 255      

    if (mode == 16) {
        init_pair(0, 7, 0);  // white: default, always 1st cChar
        init_pair(1, 1, 0);  // red
        init_pair(2, 2, 0);  // green: default, 2nd-end chars of trail
        init_pair(3, 3, 0);  // yellow
        init_pair(4, 4, 0);  // blue
        init_pair(5, 5, 0);  // magenta
        init_pair(6, 6, 0);  // cyan
    }

    for (j = 0; j < 10; j++) {                                   // initialize first array of trails
                startingLine[j] = rand() % LINES;
                rndmCol[j] = rand() % COLS;
                fall[j] = 0;
    }
    if (mode == 16) {
        while (getch() != 'q') {
            for (j = 0; j < 10; j++) {
                if (startingLine[j] + fall[j] - 1 == LINES) {                     // if a char drops
                    startingLine[j] = rand() % LINES;                             // offscreen,
                    rndmCol[j] = rand() % COLS;                                   // reinitialize
                    fall[j] = 0;
                }
                wChar = getRndmWChar();
                setcchar(&cChar, &wChar, A_BOLD, 0, NULL);                  // first char bold white
                if (startingLine[j] + fall[j] < LINES) {                       // draw onscreen only
                    mvadd_wch(startingLine[j] + fall[j], rndmCol[j], &cChar);
                }
                if (mixcolor == 'y') {
                    colorpair = rand() % 7;
                }
                if (startingLine[j] + fall[j] - 1 < LINES) {                   // draw onscreen only
                    mvchgat(startingLine[j] + fall[j] - 1, rndmCol[j], 1, A_NORMAL, colorpair, NULL);
                }
                                                                                     // erase (some)
                if (fall[j] > 2) {                  // trail starts 2 chars long then randomly erase
                    if (rand() % 2 == 0) {              // 1 out of 2 chars left behind in the trail
                        if (startingLine[j] + fall[j] - 2 < LINES) {          // erase onscreen only
                            mvadd_wch(startingLine[j] + fall[j] - 2, rndmCol[j], &cCharWhtSpc);
                        }
                    }
                }
                usleep(5000);                                               // microseconds of sleep
                refresh();
                fall[j]++;
            }                                                                              // j loop
        }                                                                              // while loop
    }                                                                       //  if (mode == 16) loop

    if (mode == 256) {
        while (getch() != 'q') {
            for (j = 0; j < 10; j++) {
                if (startingLine[j] + fall[j] - 1 == LINES) {                     // if a char drops
                    startingLine[j] = rand() % LINES;                             // offscreen,
                    rndmCol[j] = rand() % COLS;                                   // reinitialize
                    fall[j] = 0;
                }
                wChar = getRndmWChar();
                setcchar(&cChar, &wChar, A_BOLD, 255, NULL);                  // first char bold white
                if (startingLine[j] + fall[j] < LINES) {                       // draw onscreen only
                    mvadd_wch(startingLine[j] + fall[j], rndmCol[j], &cChar);
                }
                if (startingLine[j] + fall[j] - 1 < LINES) {                   // draw onscreen only
                    mvchgat(startingLine[j] + fall[j] - 1, rndmCol[j], 1, A_NORMAL, 1 + rand() % 254, NULL);
                }
                                                                                     // erase (some)
                if (fall[j] > 2) {                  // trail starts 2 chars long then randomly erase
                    if (rand() % 2 == 0) {              // 1 out of 2 chars left behind in the trail
                        if (startingLine[j] + fall[j] - 2 < LINES) {          // erase onscreen only
                            mvadd_wch(startingLine[j] + fall[j] - 2, rndmCol[j], &cCharWhtSpc);
                        }
                    }
                }
                usleep(5000);                                               // microseconds of sleep
                refresh();
                fall[j]++;
            }                                                                              // j loop
        }                                                                              // while loop
    }                                                                       //  if (mode == 16) loop

}                                                                               // END draw_trails()

void colorred() {

    int i = 0;

    init_color(255, 1000, 1000, 1000);                          // init_color #255 defined as white
    init_pair(255, 255, 0);                                     // init_pair  #255 is white on black

    for (i = 1; i < 255; i++) {
        init_color(i, (1000/255)*i, 0, 0);
    }
    for (i = 1; i < 255; i++) {
        init_pair(i, i, 0);
    }
}

void colorgreen() {

    int i = 0;

    init_color(255, 1000, 1000, 1000);                          // init_color #255 defined as white
    init_pair(255, 255, 0);                                     // init_pair  #255 is white on black

    for (i = 1; i < 255; i++) {                                          // #s 2-255 shades of green
        init_color(i, 0, (1000/255)*i, 0);
    }
    for (i = 1; i < 255; i++) {                  // pairs assigned from color_pair_number (first i) 
        init_pair(i, i, 0);                      // and colors defined w init_color (second i) 
    }
}

void coloryellow() {

    int i = 0;

    init_color(255, 1000, 1000, 1000);                          // init_color #255 defined as white
    init_pair(255, 255, 0);                                     // init_pair  #255 is white on black

    for (i = 1; i < 255; i++) {
        init_color(i, (1000/255)*i, (1000/255)*i, 0);
    }
    for (i = 1; i < 255; i++) {
        init_pair(i, i, 0);
    }
}

void colorblue() {

    int i = 0;

    init_color(255, 1000, 1000, 1000);                          // init_color #255 defined as white
    init_pair(255, 255, 0);                                     // init_pair  #255 is white on black

    for (i = 1; i < 255; i++) {
        init_color(i, 0, 0, (1000/255)*i);
    }
    for (i = 1; i < 255; i++) {
        init_pair(i, i, 0); 
    }
}

void colormagenta() {

    int i = 0;

    init_color(255, 1000, 1000, 1000);                          // init_color #255 defined as white
    init_pair(255, 255, 0);                                     // init_pair  #255 is white on black

    for (i = 1; i < 255; i++) {
        init_color(i, (1000/255)*i, 0, (1000/255)*i);
    }
    for (i = 1; i < 255; i++) {
        init_pair(i, i, 0);
    }
}

void colorcyan() {

    int i = 0;

    init_color(255, 1000, 1000, 1000);                          // init_color #255 defined as white
    init_pair(255, 255, 0);                                     // init_pair  #255 is white on black

    for (i = 1; i < 255; i++) {
        init_color(i, 0, (1000/255)*i, (1000/255)*i);
    }
    for (i = 1; i < 255; i++) {
        init_pair(i, i, 0);
    }
}


void colormix() {

    int i = 0;

    init_color(255, 1000, 1000, 1000);                          // init_color #255 defined as white
    init_pair(255, 255, 0);                                     // init_pair  #255 is white on black

    for (i = 1; i < 255; i++) {
        init_pair(i, i, 0);
    }
}                                                                                                   


int main (int argc, char *argv[]) {                                                  // START main()

    int i = 0;
    char answer = '\0';

    struct timespec ts;                                                                // high 
    clock_gettime(CLOCK_MONOTONIC, &ts);                                               // resolution
    unsigned long seed = ts.tv_sec ^ ts.tv_nsec;                                       // rand()
    srand(seed);                                                                       // seeding

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            help();                                                  // -h command line help request
            return EXIT_SUCCESS;
        }
    }

    if (argc == 1) {
        printf("d_rain: usage: d_rain <256> <color>\n");
        printf("d_rain: usage: d_rain -h for help\n");
        printf("->   q to quit while running   <-\n");
        printf("Proceed with defaults (y/n)? ");
        scanf(" %c", &answer);
        if (answer == 'N' || answer == 'n') {
            return EXIT_FAILURE;
        }
    }

                                       // set up ncurses //                                         
    setlocale(LC_ALL, "");                                        // enable UTF-8 in standard output
    initscr();                                                                       // init ncurses
    cbreak();                                                          // disable line buffering (?)
    noecho();                                   // prevent user input from being shown on the screen
    curs_set(0);                                                            // don't show the cursor
    start_color();                                                                     // init color
    nodelay(stdscr, TRUE);                                         // set getch() to be non-blocking

    if (argc == 2) {

        if (isdigit(argv[1][1])) {
            if (atoi(argv[1]) == 256) {
                mode = 256;
                colorgreen();
            } else {
                endwin();
                printf("Unrecognized parameter %s\n", argv[1]);
                return EXIT_FAILURE;
            }
        }
        if (isalpha(*argv[1])) {
            switch (*argv[1]) {
                case 'r':
                    colorpair = 1;
                    break;
                case 'g':
                    colorpair = 2;
                    break;
                case 'y':
                    colorpair = 3;
                    break;
                case 'b':
                    colorpair = 4;
                    break;
                case 'm':
                    colorpair = 5;
                    break;
                case 'c':
                    colorpair = 6;
                    break;
                case 'x':
                    mixcolor = 'y';
                    break;
                default:
                    endwin();
                    printf("Unrecognized parameter %s\n", argv[1]);
                    return EXIT_FAILURE;
            }                                                                     // END switch-case
        }                                                                // END if (isalpha(argv[1])
    }                                                                           // END if (arg == 2)

    if (argc == 3) {
        if (atoi(argv[1]) == 256) {
            mode = 256;
        } else {
            endwin();
            printf("Unrecognized parameter %s\n", argv[1]);
            return EXIT_FAILURE;
        }
        if (isalpha(*argv[2])) {
            switch (*argv[2]) {
                case 'r':
                    colorred();
                    break;
                case 'g':
                    colorgreen();
                    break;
                case 'y':
                    coloryellow();
                    break;
                case 'b':
                    colorblue();
                    break;
                case 'm':
                    colormagenta();
                    break;
                case 'c':
                    colorcyan();
                    break;
                case 'x':
                    colormix();
                    break;
                default:
                    endwin();
                    printf("Unrecognized parameter %s\n", argv[2]);
                    return EXIT_FAILURE;
            }                                                                     // END switch-case
        }                                                               // END if (isalpha(*argv[2])
    }                                                                           // END if (arg == 3)

    drawTrails();                                                                          // draw!

    endwin();                                                                     // ncurses cleanup
    return EXIT_SUCCESS;
}                                                                                      // END main()


/*                                                                                                 1                   1                   1
         1         2         3         4         5         6         7         8         9         0                   2                   4
12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890*/
