// Helper functions for music
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>
// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{

    //checks the fraction and returns the req int to convert to 8
    if (fraction[2] == '8')
    {
        if (fraction[0] == '1')
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    //checks the second condition of the same
    else if ( fraction[2] == '4')
    {
        return 2;
    }

    else if (fraction[2] == '2')
    {
        return 4;
    }

    else
    {
        return 0;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    // Checks the offset from the octave number
    const double freq_a4 = 440.0;
    int octavenum = note[strlen(note) - 1];
    octavenum -= 48;
    int octavevar = octavenum - 4;

    int noteoff = 0;
    // Calculates the offset from the A note
    switch (note[0])
    {
        case 'C':
            noteoff = -9;
            break;

        case 'D':
            noteoff = -7;
            break;

        case 'E':
            noteoff = -5;
            break;

        case 'F':
            noteoff = -4;
            break;

        case 'G':
            noteoff = -2;
            break;

        case 'A':
            noteoff = 0;
            break;

        case 'B':
            noteoff = 2;
            break;

        default :
            noteoff = 0;
    }

    int additionaloff = 0;
    // Checks the offset from the sharp and flat
    if (note[1] == '#')
    {
        additionaloff = 1;
    }

    else if (note[1] == 'b')
    {
        additionaloff = -1;
    }

    else
    {
        additionaloff = 0;
    }

    int toff = 12 * octavevar + noteoff + additionaloff;
    // Calculates the power to which 2 is to be raised
    double power = 0;
    power = ((double)toff) / 12.0;

    double freq = 0;
    // Checks the condition whether to multiply or to divide
    if (toff >= 0)
    {
        freq = freq_a4 * pow(2.0, power);
    }
    else
    {
        // Turns the power to positive as negative indicate the
        // octave number less than 4
        power = -power;
        freq = freq_a4 / pow(2.0, power);
    }
    return round(freq);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strlen(s) == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}
