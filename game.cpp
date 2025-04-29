#include "game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void intro() {
    std::cout << "Welcome to Space Escape!\n";
    std::cout << "You are the captain of a stranded spaceship on an alien planet.\n";
    std::cout << "Your mission is to survive and find a way back to Earth.\n\n";
}

void startGame() {
    std::string playerName;
    int score = 0;
    std::string inventory[3] = {"Laser Gun", "Medkit", "Scanner"};
    int choice;

    std::cout << "Enter your name, Captain: ";
    std::getline(std::cin, playerName);

    std::cout << "\nChoose an action:\n";
    std::cout << "1. Explore the surface\n";
    std::cout << "2. Hide in the wreckage\n";
    std::cout << "3. Signal for help\n";
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    // Input validation
    while (std::cin.fail() || choice < 1 || choice > 3) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 3: ";
        std::cin >> choice;
    }

    std::cout << "\n";

    // Game decision logic
    switch (choice) {
        case 1:
            std::cout << "You found an abandoned escape pod.\n";
            score += calculateScore(100, 50);
            endGame(true);
            break;
        case 2:
            std::cout << "Hostile aliens discovered your location.\n";
            score += calculateScore(50, 20);
            endGame(false);
            break;
        case 3:
            std::cout << "A friendly ship received your signal and rescued you.\n";
            score += static_cast<int>(calculateScore(100.0, 1.5));
            endGame(true);
            break;
    }

    saveScore(playerName, score);
}

int calculateScore(int base, int bonus) {
    return base + bonus;
}

double calculateScore(double base, double multiplier) {
    return base * multiplier;
}

void endGame(bool win) {
    if (win)
        std::cout << "Mission successful. You escaped the alien planet!\n";
    else
        std::cout << "Mission failed. You did not survive.\n";
}

void saveScore(const std::string& name, int score) {
    std::ofstream file("scores.txt", std::ios::app);
    if (file.is_open()) {
        file << name << ": " << score << "\n";
        file.close();
    } else {
        std::cerr << "Error: Could not open scores.txt to save score.\n";
    }
}