#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int maxCandidates = 10;
int candidatesNum = 0;
int validVotes = 0;
int invalidVotes = 0;

string candidates[maxCandidates];
int votes[maxCandidates] = {0};

void readVotes();
void printResults();

int main() {
    readVotes();
    printResults();
}

/*  
    Function:   readVotes
    Purpose:    Read all inputs from the stdin. Each time a candidate name, a valid vote or an invalid vote is read, 
                global variables candidates, validVotes and invalidVotes will respectively increase by 1.
                Candidate names are read into the global candidates array.
                Votes are read into the global vote array.
*/
void readVotes() {
    int tmp;
    /*  Read input as strings of candidate names,
        until the point where the current input is an integer (tmp is assigned to it),
        or the EOF is met (tmp is undefined).  */ 
    for (candidatesNum = 0; !(cin >> tmp); candidatesNum++) {
        if (cin.eof()) {return;} else {cin.clear();} // if EOF, then it's the case of no candidate or vote, returns void; 
        getline(cin,candidates[candidatesNum]);
    };
    // start to read the votes until the EOF
    do {
        if (tmp < 1 || tmp > candidatesNum) {
            invalidVotes++;
        } else {
            validVotes++;
            votes[tmp-1]++;
        }
    } while (cin >> tmp);
}

/*
    Funtion:    printResults
    Purpose:    print the formated voting result according to global variables
*/
void printResults() {
    cout << "Number of voters: " << validVotes + invalidVotes << endl
         << "Number of valid votes: " << validVotes << endl
         << "Number of spoilt votes: " << invalidVotes << endl
         << endl
         << "Candidate      Score" << endl
         << endl;
    for (int i = 0; i < candidatesNum; i++) {
        cout << candidates[i] << setw(15-candidates[i].size()+3) << votes[i] << endl;
    }
}
