#include <iostream>               
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
int width = 40;
int height = 20;
int score;
int dinoX, dinoY;
int cactusX, cactusY;
int cactusSpeed;

void Setup() {
    gameOver = false;
    score = 0;
    dinoX = width / 2;
    dinoY = height - 1;
    cactusX = width - 1;
    cactusY = height - 1;
    cactusSpeed = 1;
}

void Draw() {
    system("cls"); // Clear the console screen

    // Draw top border
    for (int i = 0; i < width; i++)
    cout << "#";
    cout << std::endl;

    // Draw game area
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == dinoX && i == dinoY)
                cout << "O"; // Draw dinosaur
            else if (j == cactusX && i == cactusY)
                cout << "@"; // Draw cactus
            else
                cout << " ";
        }
        cout <<endl;
    }

    
    for (int i = 0; i < width; i++)
    cout << "#";
    cout <<endl;

    // Draw score
    cout << "Score: " << score << std::endl;
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case ' ':
                if (dinoY == height - 1)
                    dinoY -= 2; // Jump if on the ground
                break;
            case 'q':
                gameOver = true; // Quit the game
                break;
        }
    }
}

void Logic() {
    if (dinoY < height - 1)
        dinoY++; // Apply gravity to the dinosaur

    if (cactusX > 0)
        cactusX -= cactusSpeed; // Move the cactus

    // Check collision
    if (dinoX == cactusX && dinoY == cactusY) {
        gameOver = true;
    }

    // Increase score if the cactus has passed the dinosaur
    if (cactusX == 0) {
        score++;
        cactusX = width - 1;
        if (score % 10 == 0)
            cactusSpeed++;
    }
}

int main() {
    Setup();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100); // Delay for smoother gameplay
    }

    cout << "Game Over! Your score: " << score <<endl;

    return 0;
}
             
