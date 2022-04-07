//
// Created by enoch on 15/03/2021.
//

#include <string.h>

#include <stdio.h>
#include "Sorting.h"

void sort_Artiste(struct playlistData arr[]){// function to artiste in alphabetical order using insertion sort
    struct playlistData current;
    int i;
    int k;

    for(i=0; i<artiste_len; i++){

        k=i-1;
        current= arr[i];

        while(k>=0 && strcmp(current.artiste,arr[k].artiste)<0)
        {
            arr[k+1]= arr[k];
            k--;
        }
        arr[k+1]= current;
    }
}

void sort_Songs(struct playlistData arr[]){// function to sort songs in alphabetical order insertion sort


    char current[num_len];
    int i;
    int k;
    int m;

    for (m = 0; m < artiste_len; m++) {
        for (i = 0; i < arr[m].song_dig; i++) {
            k = i - 1;
            strcpy(current,arr[m].songs[i]);

            while(k >= 0 && strcmp(current, arr[m].songs[k]) < 0) {

                strcpy(arr[m].songs[k + 1], arr[m].songs[k]);
                k--;
            }
            strcpy(arr[m].songs[k + 1], current);

        }

    }
}
void printer (struct playlistData p_arr[]){
    int i ,k;
    // printing the sorted artiste name and songs certain format
    for(i=0; i<artiste_len; i++) {
        printf("%s\n", p_arr[i].artiste);
        for (k = 0; k < p_arr[i].song_dig; k++) {
            printf("o %s\n", p_arr[i].songs[k]);
        }
        printf("\n");
    }
}


