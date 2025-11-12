// .h
// OS Beep Sound Functions
// by Kyle Furey

#ifndef HLOS_BEEP_H
#define HLOS_BEEP_H

#include "types.h"

/** Programmable Interval Timer channel 2 (audio). */
#define PIT_CHANNEL2_PORT 0x42

/** The port for the audio speaker. */
#define SPEAKER_PORT 0x61

/** Settings for a square wave sound. */
#define SQUARE_WAVE_NUM 0xB6

/** Audio speaker flags. */
typedef enum speaker_flags {
    SPEAKER_FLAGS_ENABLE = 3,
    SPEAKER_FLAGS_CLEAR = 252,
} speaker_flags_t;

/** Beeps the computer. */
void beep();

/** Beeps for the given frequency in hertz and duration in milliseconds. */
void freq(uint_t hz, uint_t ms);

#endif // HLOS_BEEP_H
