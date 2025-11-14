// .c
// OS Kernel Entry Point
// by Kyle Furey

#include "hlos.h"

/** Coroutine for the clock. */
void clock(void *hr24);

/** The entry point of the HLOS kernel. */
void kernel_main() {
    init();

    sleep(1000);
    beep();
    clear();
    print("\n\t\t");
    color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    string_t welcome = "Welcome to the\n\n";
    sleep(1000);
    while (*welcome != '\0') {
        printchar(*welcome++);
        sleep(75);
    }

    color(VGA_COLOR_BROWN, VGA_COLOR_BLACK);
    sleep(300);
    print(" High");
    sleep(300);
    print("-Level ");
    sleep(300);
    print("Operating ");
    sleep(300);
    print("System!");
    color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);

    welcome = " High-Level Operating System!";
    uint_t length = strlen(welcome);
    VGA_color_t rainbow[] = {
        VGA_COLOR_LIGHT_RED,
        VGA_COLOR_LIGHT_BLUE,
        VGA_COLOR_LIGHT_CYAN,
        VGA_COLOR_LIGHT_GREEN,
        VGA_COLOR_LIGHT_MAGENTA,
        VGA_COLOR_YELLOW,
        VGA_COLOR_BROWN,
        VGA_COLOR_RED,
    };
    uint_t size = ARRAY_SIZE(rainbow);
    uint_t index = (uint_t) -1;
    sleep(750);
    print("\n\n\t\t\tYaay!");
    VGA.row -= 2;
    uint_t t = time() + 2000;
    while (time() < t) {
        for (uint_t i = 0; i < length; ++i) {
            char_t character = pos(i, VGA.row);
            color(rainbow[(index + i) % size], VGA_COLOR_BLACK);
            printchar(character);
            sleep(1);
        }
        --index;
    }

    clear();
    clock((void *) false);
    print("\n\n");
    color(VGA_COLOR_GREEN, VGA_COLOR_BLACK); // Matrix style
    char_t *start = (char_t *) "int main() {\n\treturn 0;\n}\n";
    while (true) {
        start = (char_t *) read(VGA_SIZE - VGA_POS, start);
        strpush(start, '\n');
        VGA.column = 0;
        VGA.row = 1;
    }

    shutdown(1000);
}

/** Coroutine for the clock. */
void clock(void *hr24) {
    coro(1000, clock, hr24);
    byte_t col = VGA.column;
    byte_t row = VGA.row;
    byte_t color = VGA.color;
    VGA.column = 0;
    VGA.row = 0;
    VGA.color = VGA_COLOR(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    print(datestr(date(), hr24));
    VGA.column = col;
    VGA.row = row;
    VGA.color = color;
}
