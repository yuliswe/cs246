#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

const int maxCandidates = 10;
int candidatesNum = 0;
int validBallots = 0;
int invalidBallots = 0;

string candidates[maxCandidates];
int ballots[maxCandidates] = {0};

void readBallots(int);
void printResults();

int main(int argn, char** args) {
    if (argn > 1) {
        istringstream ss(args[1]);
        int i;
        ss >> i;
        readBallots(i);
    } else {
        readBallots(-1);
    }
    printResults();
}

/*  
    Function:   readBallots
    Purpose:    Read all inputs from the stdin. Each time a candidate name, a valid ballot or an invalid ballot is read, 
                global variables candidates, validBallots and invalidBallots will respectively increase by 1.
                Candidate names are read into the global candidates array.
                Ballots are read into the global ballot array.
    Params:     int maxVotes: the max number of votes per voter. If this parameter is -1, then maxVotes = candidatesNum
*/
void readBallots(int maxVotes) {
    string l;
    /*  Read Candidate Names  */
    while (getline(cin,l)) {
        istringstream maybeName(l);    
        
        // Test if is the ballot section already
        int test;
        maybeName >> test;
        if (maybeName.fail() && candidatesNum <= maxCandidates) {
            candidates[candidatesNum++] = l;
        } else {break;}
    }
    
    /*  Read Ballots  */
    if (maxVotes == -1) {maxVotes = candidatesNum;}

    while (cin.good()) {
        istringstream maybeValid(l);
        getline(cin,l);     
        int tmpBallots[candidatesNum + 1]; // If tmpBallots[candidatesNum] is assigned then the ballot
        int sum = 0;                       // has at least 1 extra column. Invalid.
        int columns = 0;

        while (maybeValid >> tmpBallots[columns] && columns <= candidatesNum) { // sum a ballot's votes
            sum += tmpBallots[columns++];
        };

        if (columns == candidatesNum && sum <= maxVotes) {
            for (int i = 0; i < candidatesNum; i++) {ballots[i] += tmpBallots[i];} // add votes for each candidate
            validBallots++;
        } else {
            invalidBallots++;
        }
    }

}

/*
    Funtion:    printResults
    Purpose:    print the formated voting result according to global variables
*/
void printResults() {
    cout << "Number of voters: " << validBallots + invalidBallots << endl
         << "Number of valid ballots: " << validBallots << endl
         << "Number of spoilt ballots: " << invalidBallots << endl
         << endl
         << "Candidate      Score" << endl
         << endl;
    for (int i = 0; i < candidatesNum; i++) {
        cout << candidates[i] << setw(15-candidates[i].size()+3) << ballots[i] << endl;
    }
}
