#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  // For Sleep() function on Windows

// Function to display the devotion prompt
void display_devotion() {
    printf("It's time for your daily devotion!\n");

    // Display a main Bible verse
    printf("Main Bible Verse: John 3:16 - For God so loved the world...\n");

    // Display related Bible verses
    printf("Related Verses: Romans 5:8, 1 John 4:9\n");

    // Display today's hymn
    printf("Today's Hymn: Hymn 101\n");

    // Display prayer points
    printf("Prayer Points: Pray for strength and wisdom.\n");

    // Ask user for notes
    char note[256];
    printf("Enter your note for today: ");
    fgets(note, sizeof(note), stdin);
    strtok(note, "\n");  // Remove the newline character

    // Save the note (for simplicity, we'll just display it)
    printf("Your note: %s\n", note);
}

// Function to check if it's the right time for devotion (6 AM)
void check_time_for_devotion() {
    time_t now;
    struct tm *local_time;

    while (1) {
        time(&now);
        local_time = localtime(&now);

        // Check if it's 6 AM
        if (local_time->tm_hour == 6 && local_time->tm_min == 0) {
            display_devotion();
            break;  // Break after displaying devotion
        }

        Sleep(60000);  // Check every minute (Windows uses milliseconds)
    }
}

int main() {
    printf("Daily Devotion Program Started...\n");
    check_time_for_devotion();
    return 0;
}