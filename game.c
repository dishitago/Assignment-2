#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int x = 1;                    // player position
    int step = 0;                 // obstacle vertical movement
    int obstaclePos = rand() % 3; // random lane
    int score = 0;                // NEW: score counter
    int lives = 3;                // NEW: player lives

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)        // LEFT
                x--;

            if (ch == 77 && x < 2)        // RIGHT
                x++;
        }

        // ---- DRAW ----
        system("cls");
        printf("|--- --- ---|\n");

        // Display Score & Lives
        printf("Score: %d     Lives: %d\n\n", score, lives);

        for (int i = 0; i < 10; i++) {
            if (i == step) {

                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);

                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);

                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);

            } else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| %c        |\n", 6);
        else if (x == 1)
            printf("|     %c    |\n", 6);
        else if (x == 2)
            printf("|        %c |\n", 6);

        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos) {
            lives--;       // NEW: decrease life

            if (lives == 0) {
                printf("\nGAME OVER! Final Score: %d\n", score);
                break;
            } else {
                printf("\nYou lost a life! Remaining Lives: %d\n", lives);
                Sleep(800);
            }
        }

        Sleep(120);

        // ---- MOVE OBSTACLE ----
        step++;

        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
            score++;  // NEW: increase score after each dodge
        }
    }

    return 0;
}
