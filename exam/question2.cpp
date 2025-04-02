#include <iostream>
#include <vector>
#include <string>

using namespace std;

void eliminateLeftRecursion(string nonTerminal, vector<string> productions) {
    vector<string> alpha, beta;
    
    for (string prod : productions) {
        if (prod[0] == nonTerminal[0]) {
            alpha.push_back(prod.substr(1)); 
        } else {
            beta.push_back(prod);
        }
    }

    if (alpha.empty()) {
        cout << nonTerminal << " -> ";
        for (size_t i = 0; i < productions.size(); i++) {
            cout << productions[i];
            if (i != productions.size() - 1) 
               cout << " | ";
        }
        cout << endl;
        return;
    }

    string newNonTerminal = nonTerminal + "'";

    cout << nonTerminal << " -> ";
    for (size_t i = 0; i < beta.size(); i++) {
        cout << beta[i] << newNonTerminal;
        if (i != beta.size() - 1) cout << " | ";
    }
    cout << endl;

    cout << newNonTerminal << " -> ";
    for (size_t i = 0; i < alpha.size(); i++) {
        cout << alpha[i] << newNonTerminal << " | ";
    }
    cout << "ε" << endl; 
}

int main() {
    string nonTerminal;
    int numProductions;

    cout << "Enter the non-terminal: ";
    cin >> nonTerminal;
    
    cout << "Enter the number of productions: ";
    cin >> numProductions;

    vector<string> productions(numProductions);
    cout << "Enter productions (separated by space):\n";
    for (int i = 0; i < numProductions; i++) {
        cin >> productions[i];
    }

    cout << "\nGrammar after removing left recursion:\n";
    eliminateLeftRecursion(nonTerminal, productions);

    return 0;
}
