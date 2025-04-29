#ifndef GAME_H
#define GAME_H

#include <string>  // <-- Add this line

void intro();
void startGame();
int calculateScore(int base, int bonus);
double calculateScore(double base, double multiplier); // Overloaded
void endGame(bool win);
void saveScore(const std::string& name, int score);

#endif