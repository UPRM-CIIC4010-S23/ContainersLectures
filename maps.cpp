#include <iostream>
#include <map>
#include <string>

using namespace std;

// https://www.hackerrank.com/challenges/linkedin-practice-dictionaries-and-maps/problem

int main() {

    string paragraph = "A planet is an astronomical body orbiting a star or stellar remnant that is massive enough to be rounded by its own gravity";

    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    map<char, int> alphabetHistogram;

    for (char nextLetter : alphabet) {
        alphabetHistogram[nextLetter] = 0;
    }

    for (char nextLetter : paragraph) {
        alphabetHistogram[toupper(nextLetter)]++;
    }

    for (char nextLetter : alphabet) {
        cout << "Letter " << nextLetter << " appears " << alphabetHistogram[nextLetter] << endl;
    }
    
}