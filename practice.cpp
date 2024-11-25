#include<iostream>  
#include <ctime>
#include <cstdlib>
#include <windows.h>


class BasketballGame {
private:
    int score;
    int attempts;
    const int MAX_ATTEMPTS = 10;

    bool takeShot() {
        int power;
        std::cout << "Enter shooting power (1-100): ";
        std::cin >> power;
        
        
        srand(time(0));
        int windFactor = rand() % 20;
        return (power >= 40 && power <= 80 && windFactor > 5);
    }

    void displayAnimation(bool scored) {
        if (scored) {
            std::cout << "\nBall in the air";
            for (int i = 0; i < 3; i++) {
                Sleep(500);
                std::cout << ".";
            }
            std::cout << "\n🏀 SWISH! Nothing but net! 🎯\n";
        } else {
            std::cout << "\nBall in the air";
            for (int i = 0; i < 3; i++) {
                Sleep(500);
                std::cout << ".";
            }
            std::cout << "\n❌ CLANK! Missed shot!\n";
        }
    }

public:
    BasketballGame() : score(0), attempts(0) {}

    void play() {
        std::cout << "🏀 Welcome to Basketball Shooter! 🏀\n\n";
        
        while (attempts < MAX_ATTEMPTS) {
            std::cout << "\nAttempt " << attempts + 1 << "/" << MAX_ATTEMPTS << "\n";
            std::cout << "Current Score: " << score << "\n";
            
            bool scored = takeShot();
            displayAnimation(scored);
            
            if (scored) {
                score += 2;
                std::cout << "Score +2!\n";
            }
            
            attempts++;
        }
        
        std::cout << "\n🎮 Game Over! 🎮\n";
        std::cout << "Final Score: " << score << " points\n";
        
        if (score >= 12) {
            std::cout << "Amazing performance! 🌟\n";
        } else if (score >= 6) {
            std::cout << "Good game! 👍\n";
        } else {
            std::cout << "Keep practicing! 💪\n";
        }
    }
};

int main() {
    BasketballGame game;
    game.play();
    return 0;
}