#include <iostream>
#include <random>
#include <ctime>

using namespace std;

class Game {
public:
    Game() {
        guesses = 7;
        count = 0;
        randomValue = GetRandom(1, 100);
    }
    bool playGame() {
        for (int i = 1; i <= guesses; ++i) {
            ++count;
            cout << "Guess #" << count << endl;
            int guess;
            cin >> guess;
            if (guess > randomValue) {
                cout << "Your guess is too high." << endl;
            }
            else if (guess < randomValue) {
                cout << "Your guess is too low." << endl;
            }
            else
                return true;
        }
        return false;
    }
    bool playAgain() {
        char getAnswer;
        do {
            cout << "Would you like to play again (y/n)?" << endl;
            cin >> getAnswer;
        } while (getAnswer != 'y' && getAnswer != 'n');
        count = 0;
        return (getAnswer == 'y');
    }
    void Start() {
        do {
            cout << "Let's play a game. I'm thinking of a number. You have " << guesses << " tries to guess what it is." << endl;
            bool won = playGame();
            if (won) {
                cout << "Correct! You win!" << endl;
            }
            else {
                cout << "Sorry, you lose. The correct number was " << randomValue << "." << endl;
            }
        } while (playAgain());
        cout << "Thank you for playing." << endl;
    }
private:
    int guesses;
    int count;
    int randomValue;

    int GetRandom(int min, int max) {
        srand(time(0));
        int rValue = min + rand() % (max - min + 1);
        return rValue;
    }
};


int main() {
    Game game;
    game.Start();
}
