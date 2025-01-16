// Rock paper scissors CSC222.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Name: Yochanan allen 

//Write a program that lets the user play the game Rock, Paper, Scissors against the computer:
//Write the program so that the game proceeds in a loop where the computer and a human play
//multiple rounds of the game in a tournament.A score is kept for each player of the number of wins.
//The human player determines when the tournament ends at which point the player(computer or
// human) with the highest score is declared the winner and the final score is displayed.Note that
// each round can end in a draw and the entire tournament can also end in a draw.


#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;


int getComputerChoice() {
    
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distrib(1, 3); 

    return distrib(gen);  
}


string choiceToString(int choice) {
    if (choice == 1) return "rock";
    else if (choice == 2) return "paper";
    else return "scissors";
}


string getPlayerChoice() {
    string playerChoice;
    while (true) {
        cout << "Enter your choice (rock, paper, scissors, or quit): ";
        cin >> playerChoice;
        if (playerChoice == "rock" || playerChoice == "paper" || playerChoice == "scissors" || playerChoice == "quit") {
            break;
        }
        else {
            cout << "Invalid input. Please enter 'rock', 'paper', 'scissors', or 'quit'. ";
        }
    }
    return playerChoice;
}


string determineWinner(string playerChoice, string computerChoice) {
    if (playerChoice == computerChoice) {
        return "draw";
    }
    else if ((playerChoice == "rock" && computerChoice == "scissors") ||
        (playerChoice == "scissors" && computerChoice == "paper") ||
        (playerChoice == "paper" && computerChoice == "rock")) {
        return "player";
    }
    else {
        return "computer";
    }
}


void updateScores(string winner, int& playerScore, int& computerScore) {
    if (winner == "player") {
        playerScore++;
    }
    else if (winner == "computer") {
        computerScore++;
    }
}


void declareTournamentWinner(int playerScore, int computerScore) {
    cout << " Final Scores: ";
    cout << "Player: " << playerScore << endl;
    cout << "Computer: " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << "Congratulations! You win the tournament! ";
    }
    else if (computerScore > playerScore) {
        cout << "Computer wins the tournament! Better luck next time. ";
    }
    else {
        cout << "The tournament is a draw! ";
    }
}

int main() {
    

    int playerScore = 0, computerScore = 0;
    string playerChoice, computerChoice;
    int rounds = 0;

    cout << "Welcome to Rock, Paper, Scissors Tournament! ";

    while (true) {
        rounds++;  
        cout << " Round " << rounds << endl;

        
        int computerChoiceNum = getComputerChoice();
        computerChoice = choiceToString(computerChoiceNum);

        
        playerChoice = getPlayerChoice();

        
        if (playerChoice == "quit") {
            break;
        }

        
        cout << "Computer chose " << computerChoice << endl;
        cout << "You chose " << playerChoice << endl;

        
        string roundWinner = determineWinner(playerChoice, computerChoice);

        updateScores(roundWinner, playerScore, computerScore);

        
        if (roundWinner == "draw") {
            cout << "It's a draw! ";
        }
        else if (roundWinner == "player") {
            cout << "You win this round! ";
        }
        else {
            cout << "Computer wins this round!\n";
        }

        
        cout << " Current Scores: ";
        cout << "Player: " << playerScore << endl;
        cout << "Computer: " << computerScore << endl;
    }

    
    declareTournamentWinner(playerScore, computerScore);

    return 0;
}

