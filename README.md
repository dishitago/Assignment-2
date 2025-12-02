# Assignment-2
Objective 1 – Game Logic Analysis

This document explains the basic working of the existing C console game.
1. Game Overview
-The game has three lanes.
-The player stands at the bottom and can move left or right.
-An obstacle appears from the top and moves downward.
-If the obstacle reaches the bottom in the same lane as the player, the game ends.
2. Main Variables
-x – player lane position (0, 1, 2)
-step – vertical position of the obstacle
-obstaclePos – lane where the obstacle appears
-srand(time(0)) – makes obstacle spawn randomly each game
3. Input Handling
The game checks arrow keys using _kbhit() and getch().
-75 → move left
-77 → move right
4. Drawing the Game
The screen clears every frame using system("cls").
The game prints:
10 rows of empty space
The obstacle on the row equal to step
The player on the bottom row
-ASCII 1 = obstacle
-ASCII 6 = player
5. Obstacle Movement
step++ moves the obstacle down each frame.
When it reaches the bottom, the game resets the obstacle and chooses a new lane.
6. Collision
Collision occurs when:
step == 10 && x == obstaclePos
This ends the game and prints “GAME OVER”.
7. Game Loop
-Everything runs inside an infinite loop:
-Read input
-Draw screen
-Move obstacle
-Check collision
-Delay with Sleep(120)

Objective 2 – Modifications I Added
For this part, I added two simple features to improve the original game:
1. Score System
I added a score variable that goes up every time the obstacle reaches the bottom without hitting the player. The score is shown at the top while playing and helps track how long the player survives.
2. Player Lives
Instead of ending the game instantly, I added a lives variable (set to 3).
Now, if the player gets hit, only one life is lost and the game continues. The game only ends when all lives are gone. This makes it a bit more forgiving and playable.
Summary
-Both features were added inside the main loop.
-Score increases after each successful dodge, and lives decrease only on collision.
-These two changes make the game feel more complete and slightly more challenging.
