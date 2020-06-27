//Lab 3 exercise 2
//Fall 2018
//js236

#include <iostream>
#include <iomanip>

using namespace std;

int findWinner(int votes[]);
int minVote(int votes[]);
void printResults(string contestants[], int votes[]);
double calculatePercentage(int votes[], int vote);

const int NUMBER_OF_CONTESTANTS = 5;

int main()
{
    string contestants[NUMBER_OF_CONTESTANTS];
    int votes[NUMBER_OF_CONTESTANTS];
    
    cout << "Please input the 5 contestants followed by the votes they received"
         << " i.e. Smith 5000: ";
    for (int i = 0; i < NUMBER_OF_CONTESTANTS; i++) {
        cin >> contestants[i] >> votes[i];
    }
    printResults(contestants, votes);
    cout << "The contestants with the minimum number of votes is: "
         << contestants[minVote(votes)] << endl;
    cout << "And the winner is: " << contestants[findWinner(votes)] << endl;
    return 0;
}

double calculatePercentage(int votes[], int vote){
    int sumOfVotes = 0;
    for (int i = 0; i < NUMBER_OF_CONTESTANTS; i++) {
        sumOfVotes += votes[i];
    }
    double percentage = ((double)vote/sumOfVotes)*100;
    return percentage;
}


void printResults(string contestants[], int votes[]){
    cout <<fixed<<setprecision(2);
    cout << "Name:" << setw(15) << "Votes:" << setw(15) << "Percentage:" << endl;
    for (int i = 0; i < NUMBER_OF_CONTESTANTS; i++) {
        cout << setw(8) << contestants[i] << setw(10) << votes[i] << setw(15);
        double percentage = calculatePercentage(votes, votes[i]);
        cout << percentage << "%" << endl;
    }
}

int findWinner(int votes[]){
    int winner = 0;
  
    for (int i = 0; i < NUMBER_OF_CONTESTANTS; i++) {
        if (votes[i] > votes[winner]){
            winner = i;
        }
    }
    return winner;
}

int minVote(int votes[]){

    int min=0;
   
    for (int i = 0; i < NUMBER_OF_CONTESTANTS; i++) {
        if (votes[i] <= votes[min])
            min = i;
    }
    return min;
}