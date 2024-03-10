#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <fstream>

using namespace std;

// class to store player name and score
class Player {
public:
    string name;
    int score;
    Player() {}
    Player(string name, int score) {
        this->name = name;
        this->score = score;
    }
    string getName() {
        return name;
    }
    int getScore() {
        return score;
    }
};

int getGuess() {
    int guess;
    cout << "Guess a value between 10 and 100: ";
    cin >> guess;
    // clear buffer
    while (cin.fail() || guess < 10 || guess > 100) {
        // validate input and clear buffer
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Please enter a number between 10 and 100: ";
        cin >> guess;
    }
    return guess;
}

int PlayGuessingGame() {
    int tries = 0;
    int numberToGuess;
    srand(time(0));
    numberToGuess = rand() % 91 + 10;
    double sq = sqrt(numberToGuess);
    cout << sq << " is the square root of what number?" << endl;
    bool correct = false;
    while (!correct) {
        int guess;
        guess = getGuess();
        if (guess < numberToGuess) {
            cout << "Too low, guess again: ";
            tries++;
        } else if (guess > numberToGuess) {
            cout << "Too high, guess again: ";
            tries++;
        } else {
            correct = true;
        }
    }
    cout << "You got it, baby!" << endl;
    return tries + 1;
}

int main() {
    cout << "Welcome! Press 'q' to quit or any other key to continue:" << endl;
    char c;
    cin >> c;
    while (c != 'q') {
        cout << "Please enter your name to start:" << endl;
        string name;
        cin >> name;
        int score;
        score = PlayGuessingGame();

        // Create a player object with the name and score
        Player curr(name, score);
        cout << "You made " << score << " guesses." << endl;

        // Open the file
        ifstream fileIn("scores.txt");
        Player allPlayers[6]; // 5 players at max + 1 for the current player
        int i = 0;
        bool inserted = false;

        // Read existing scores
        while (fileIn >> allPlayers[i].name >> allPlayers[i].score) {
            i++;
        }
        fileIn.close();

        // use a variable to store the number of players because i will be used to insert the current player in the correct position
        int numPlayers = i;
        
        // cout << i << endl;
        while (i > 0 && allPlayers[i-1].score > curr.score) {
            // go from end of array to start, shifting all players with higher scores to the right until the current player's score is better than the player at index i-1
            allPlayers[i] = allPlayers[i-1];
            i--;
            // cout << i;
        }

        allPlayers[i] = curr;

        // cout << "\nnum PLayers: " << numPlayers << "\n";
        if(numPlayers < 5) 
            numPlayers++;
            

        cout << "Here are the current leaders:" << endl;
        for (int j = 0; j < numPlayers; ++j) {
            cout << allPlayers[j].name << " made " << allPlayers[j].score << " guesses." << endl;
        }


        // Write the updated leaderboard to the file
        ofstream fileOut("scores.txt");
        for (int j = 0; j < numPlayers; ++j) {
            fileOut << allPlayers[j].name << " " << allPlayers[j].score << endl;
        }
        fileOut.close();

        cout << "Press 'q' to quit or any other key to continue:" << endl;
        cin >> c;
    }

    cout << "Bye Bye!" << endl;
    return 0;
}
