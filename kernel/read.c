// .c
// OS Input Reading Functions
// by Kyle Furey

#include "read.h"
#include "lib.h"
#include "assembly.h"
#include "print.h"

/** A mapping of each scancode to a keyboard character. */
const char_t SCANCHAR[SCANCODE_COUNT] = {
    '\0', '\e', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', '0', '-', '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
    'o', 'p', '[', ']', '\n', '\0', 'a', 's',
    'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', '`', '\0', '\\', 'z', 'x', 'c', 'v',
    'b', 'n', 'm', ',', '.', '/', '\0', '*',
    '\0', ' ', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '7',
    '8', '9', '-', '4', '5', '6', '+', '1',
    '2', '3', '0', '.',
};

/** A mapping of each scancode to a shifted keyboard character. */
const char_t SCANSHIFT[SCANCODE_COUNT] = {
    '\0', '\e', '!', '@', '#', '$', '%', '^',
    '&', '*', '(', ')', '_', '+', '\b', '\t',
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
    'O', 'P', '{', '}', '\n', '\0', 'A', 'S',
    'D', 'F', 'G', 'H', 'J', 'K', 'L', ':',
    '"', '~', '\0', '|', 'Z', 'X', 'C', 'V',
    'B', 'N', 'M', '<', '>', '?', 0, '*',
    '\0', ' ', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '7',
    '8', '9', '-', '4', '5', '6', '+', '1',
    '2', '3', '0', '.',
};

/** The state of the user's keyboard. */
volatile keyboard_t keyboard = {0};

/** Reads an input string from the user. */
string_t read() {
    static char_t buffer[MAX_INPUT_LEN] = {0};
    // TODO
    return buffer;
}

/** Reads a single character from the user. */
char_t readchar() {
    // TODO
}

/**
 * Reads an integer from the user.
 * If the user inputted a valid number, <num> is set to it.
 * Returns whether the read was successful.
 */
bool_t readint(int_t *num) {
    return strint(read(), num);
}

/** Updates the state of the keyboard. */
void key() {
    static bool_t extended = false;
    scancode_t code = (scancode_t) in(KEYBOARD_DATA_PORT);
    if (code == SCANCODE_NONE) {
        return;
    }
    if (code == SCANCODE_EXTENDED) {
        extended = true;
        return;
    } else if (code == SCANCODE_EXTENDED2) {
        extended = false;
        return;
    }
    bool_t pressed = (code & SCANCODE_RELEASED) == 0;
    code &= ~SCANCODE_RELEASED;
    volatile key_state_t *state = &keyboard.queue[keyboard.index == 0 ? MAX_KEY_STATES - 1 : keyboard.index - 1];
    uint8_t flags = state->flags;
    if (extended) {
        extended = false;
        if ((flags & KEY_FLAGS_NUMLOCK) == 0) {
            switch (code) {
                case SCANCODE_LEFT_CTRL:
                    code = SCANCODE_RIGHT_CTRL;
                    break;
                case SCANCODE_LEFT_ALT:
                    code = SCANCODE_RIGHT_ALT;
                    break;
                case SCANCODE_KEYPAD_8:
                    code = SCANCODE_UP;
                    break;
                case SCANCODE_KEYPAD_2:
                    code = SCANCODE_DOWN;
                    break;
                case SCANCODE_KEYPAD_4:
                    code = SCANCODE_LEFT;
                    break;
                case SCANCODE_KEYPAD_6:
                    code = SCANCODE_RIGHT;
                    break;
                case SCANCODE_KEYPAD_7:
                    code = SCANCODE_HOME;
                    break;
                case SCANCODE_KEYPAD_1:
                    code = SCANCODE_END;
                    break;
                case SCANCODE_KEYPAD_9:
                    code = SCANCODE_PAGEUP;
                    break;
                case SCANCODE_KEYPAD_3:
                    code = SCANCODE_PAGEDOWN;
                    break;
                case SCANCODE_KEYPAD_0:
                    code = SCANCODE_INSERT;
                    break;
                case SCANCODE_KEYPAD_DOT:
                    code = SCANCODE_DELETE;
                    break;
                case SCANCODE_ENTER:
                    code = SCANCODE_KEYPAD_ENTER;
                    break;
                default:
                    break;
            }
        }
    }
    if (pressed) {
        switch (code) {
            case SCANCODE_LEFT_SHIFT:
            case SCANCODE_RIGHT_SHIFT:
                flags |= KEY_FLAGS_SHIFT;
                break;
            case SCANCODE_LEFT_CTRL:
            case SCANCODE_RIGHT_CTRL:
                flags |= KEY_FLAGS_CTRL;
                break;
            case SCANCODE_LEFT_ALT:
            case SCANCODE_RIGHT_ALT:
                flags |= KEY_FLAGS_ALT;
                break;
            case SCANCODE_LEFT_SUPER:
            case SCANCODE_RIGHT_SUPER:
                flags |= KEY_FLAGS_SUPER;
                break;
            case SCANCODE_CAPSLOCK:
                flags ^= KEY_FLAGS_CAPSLOCK;
                break;
            case SCANCODE_NUMLOCK:
                flags ^= KEY_FLAGS_NUMLOCK;
                break;
            case SCANCODE_SCROLLLOCK:
                flags ^= KEY_FLAGS_SCROLLLOCK;
                break;
            default:
                break;
        }
    } else {
        switch (code) {
            case SCANCODE_LEFT_SHIFT:
            case SCANCODE_RIGHT_SHIFT:
                flags &= ~KEY_FLAGS_SHIFT;
                break;
            case SCANCODE_LEFT_CTRL:
            case SCANCODE_RIGHT_CTRL:
                flags &= ~KEY_FLAGS_CTRL;
                break;
            case SCANCODE_LEFT_ALT:
            case SCANCODE_RIGHT_ALT:
                flags &= ~KEY_FLAGS_ALT;
                break;
            case SCANCODE_LEFT_SUPER:
            case SCANCODE_RIGHT_SUPER:
                flags &= ~KEY_FLAGS_SUPER;
                break;
            default:
                break;
        }
    }
    keyboard.index = (keyboard.index + 1) % MAX_KEY_STATES;
    state = &keyboard.queue[keyboard.index];
    state->code = code;
    if (pressed) {
        state->flags = flags | KEY_FLAGS_PRESSED;
    } else {
        state->flags = flags & ~KEY_FLAGS_PRESSED;
    }
    ++state->age;
}
