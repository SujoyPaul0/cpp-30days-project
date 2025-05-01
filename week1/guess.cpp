#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>  // for std::abs

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int secretNumber = std::rand() % 100 + 1;
    int guess;
    int tries = 0;
    char playAgain;

    std::cout << "🎮 Guess the Number (1 to 100)\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        tries++;

        int difference = std::abs(secretNumber - guess);

        if (guess == secretNumber) {
            std::cout << "🎯 Correct! You guessed it in " << tries << " tries.\n";
            std::cout << "Play again? (y/n): ";
            std::cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y') {
                secretNumber = std::rand() % 100 + 1;
                tries = 0;
                continue;
            } else {
                break;
            }
        } else if (difference < 5) {
            std::cout << "🔥🔥 Very Hot!\n";
        } else if (difference < 30) {
            std::cout << "🔥 Warm (" << tries << " tries)\n";
        } else if (difference < 50) {
            std::cout << "❄️ Cold\n";
        } else {
            std::cout << "❄️ Freezing!\n";
        }

    } while (true);

    return 0;
}
