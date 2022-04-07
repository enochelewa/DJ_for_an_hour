//
// Created by enoch on 15/03/2021.
//

#include "Shuffle.h"


#include "Shuffle.h"

#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void generateRandomizedPlaylist(struct playlistData arr[]) // function to generate a playlist
{
    srand(time(NULL));

    int currentSize = 0;

    char artistName[2*song_len][num_len];// an array to hold artist name (20 in size)
    char songName[2*song_len][num_len];  //  an array to hold the song name (20 in size)
    char songDuration[2*song_len][num_len];//  an array to hold the song duration (20 in size)

    int MAX_MINUTES = 60; //initialising  max minutes to 60
    float currentDuration = 0.0;// initialising duration time to 0.0

    char previousArtist[num_len];
    strcpy(previousArtist, "");

    while (currentSize < 2*song_len && currentDuration < MAX_MINUTES)
    {


        int index = rand() % artiste_len;

        // checking if the position is not empty
        // or the artist is same as previous.
        if (arr[index].song_dig == 0 || strcmp(previousArtist, arr[index].artiste) == 0)
        {
            continue;
        }

        // checking how many songs have previous been for this artist.
        int previousCount = 0;
        int i = currentSize-1;
        for (i = currentSize-1; i >= 0; i--)
        {
            if (strcmp(artistName[i], arr[index].artiste) == 0)
            {
                previousCount++;
            }
        }

        // if the artist's song have already been included 3 times. then don't include more.
        // or if all the songs have already been included of this artist.
        if (previousCount >= 3 || previousCount == arr[index].song_dig)
        {
            continue;
        }

        // getting random song
        int index2 = rand() % arr[index].song_dig;

        // name and duration that'll be tokenized
        char name[num_len];
        char dur[num_len];

        // current song
        char currentSong[artiste_len];
        char* token;
        strcpy(currentSong, arr[index].songs[index2]);

        // getting the song name and duration
        token = strtok(currentSong, "***");
        strcpy(name, token);

        token = strtok(NULL, "***");
        strcpy(dur, token);

        // checking if the song is included already.
        int found = 0;
        for (i = currentSize-1; i >= 0; i--)
        {
            if (strcmp(artistName[i], arr[index].artiste) == 0 &&
                strcmp(name, arr[index].songs[index2]) == 0)
            {
                found = 1;
                break;
            }
        }

        // if it is included, it will be skipped
        if (found == 1)
            continue;

        // adding this song to the playlist.
        strcpy(artistName[currentSize], arr[index].artiste);
        strcpy(songName[currentSize], name);
        strcpy(songDuration[currentSize], dur);
        currentSize++;

        // updating the duration value.
        token = strtok(dur, ":");
        currentDuration += atoi(token);
        token = strtok(NULL, ":");
        currentDuration += atoi(token)/60.0;


        if (60 - currentDuration <= 2)
            break;

        strcpy(previousArtist, arr[index].artiste);

    }

    printf("\nRandomised playlist:\n");
    int i = 0;
    for (i = 0; i < currentSize; i++)
    {
        printf("%s: \"%s\" (%s)\n", artistName[i], songName[i], songDuration[i]); // printing artist name , song and song duration in the right format
    }
    int minutes = floor(currentDuration);// using the floor function to  return the largest integral value not greater than x
    int seconds = (currentDuration - minutes) * 60;
    printf("\nTotal Duration:%02d:%02d\n", minutes, seconds);  // printing the total duration of all the songs
}


