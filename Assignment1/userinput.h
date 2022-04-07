//
// Created by enoch on 15/03/2021.
//

#ifndef PROJECT1_USERINPUT_H
#define PROJECT1_USERINPUT_H

#include <stdio.h>

#define line_len 150 // number of lines
#define num_len  50 // number of characters
#define artiste_len 10 // number of artiste
#define song_len 10


struct playlistData{ // struct to sort

    char artiste[num_len]; // variable to hold the artiste name
    int song_dig; // holding the number of songs
    char songs[song_len][num_len]; // 2D array to hold the artiste songs

};

#endif //PROJECT1_USERINPUT_H


void File(FILE *kPtr, struct playlistData p_arr[]);// function prototype to read from file
void Keyboard(FILE* fp); // function prototype to read from keyboard
void initialisation(struct playlistData p_arr[]);  // function prototype to initialise the array of structs  to get rid of odd characters