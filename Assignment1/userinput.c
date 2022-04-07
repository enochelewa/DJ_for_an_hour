//
// Created by enoch on 15/03/2021.
//


#include "userinput.h"
#include <string.h>

#include <stdio.h>

void Keyboard(FILE* fp){// function to get user input and store in text file
    char read[num_len];
    do {
        fgets(read,num_len,stdin);// taking string from keyboard and storing into read
        fputs(read, fp);// copy read into file
    }while(strcmp(read, "0\n") != 0);// continue until a zero is entered by the user
}

void File(FILE *kPtr, struct playlistData p_arr[]){ // function to read  from text file in the array of structs

    int j=0;
    char array[line_len][num_len];
    while(!feof(kPtr)){ // loop until the end of file
        fgets(array[j],num_len,kPtr);// read line from the file int a 2D array called array
        if (array[j][strlen(array[j]) - 1] == '\n') // strip the string of it's new line character
            array[j][strlen(array[j]) - 1] = '\0';  // strip the string of it's null character
        j++; // j is equal to number of lines read from the file
    }

    char scan[num_len];
    int i = 0;
    int q = 0;

    while (q < j){ // copy from the array of strings into the struct
        strcpy(p_arr[i].artiste,array[q]);
        q++;
        strcpy(scan, array[q]);
        int m = 0;
        while (strstr(scan, "***") != 0) { // loop until the next string read does not have ***
            //copy the strings into songs
            strcpy(p_arr[i].songs[m], scan);
            q++;
            strcpy(scan, array[q]);
            m++;
        }
        // setting the struct song.dig to the number of songs
        p_arr[i].song_dig = m;
        q++;
        i++;
    }
}

void initialisation(struct playlistData p_arr[]){  // function prototype to initialise the array of structs  to get rid of odd characters
    int i,k;
    for(i=0; i<artiste_len; i++) {
        strcpy(p_arr[i].artiste,"");// initialising the artiste
        p_arr[i].song_dig = 0; // initialising the number of songs to 0

        for(k=0; i<song_len; i++) {
            strcpy(p_arr[i].songs[k],""); // initialising the songs
        }
    }
}
