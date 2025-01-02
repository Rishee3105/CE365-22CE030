#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=36;
    //cout << "Number of input symbols: ";
    //cin >> n;

    vector<char> inputSymbols(n);
    //cout << "Input symbols: ";
    /*for (int i = 0; i < n; i++)
    {
        cin >> inputSymbols[i];
    }*/


    /*cout << "Input symbols are: ";
    for (auto s : inputSymbols)
    {
        cout << s << " ";
    }
    cout << endl;*/

    int i=0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        cout<<c;
        inputSymbols[i++]=c;
    }

    for (char c = '0'; c <= '9'; c++)
    {
        cout<<c;
        inputSymbols[i++]=c;
    }

    int states=3;
    //cout << "Enter number of states: ";
    //cin >> states;

    int initial;
    cout << "Enter initial state (0-based): ";
    cin >> initial;

    int numberOfAcceptingStates=1;
    //cout << "Enter the number of accepting states: ";
    //cin >> numberOfAcceptingStates;

    vector<int> acceptingStates(numberOfAcceptingStates);
    cout << "Enter accepting states: ";
    for (int i = 0; i < numberOfAcceptingStates; i++)
    {
        cin >> acceptingStates[i];
    }

    cout << "Transition table setup:" << endl;
    vector<vector<int>> mat(states, vector<int>(n));

    /*for (int i = 0; i < states; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "State " << i << " to '" << inputSymbols[j] << "' -> ";
            cin >> mat[i][j];
        }
    }*/

    for (int i = 0; i < states; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "State " << i << " to '" << inputSymbols[j] << "' -> ";
            if(i==0)
            {
                if(j<26)
                {
                    mat[i][j]=1;
                }
                else
                {
                    mat[i][j]=2;
                }
            }
            else if(i==1)
            {
                mat[i][j]=1;
            }
            else if(i==2)
            {
                mat[i][j]=2;
            }
        }
    }


    cout << "\nTransition table:" << endl;
    for (int i = 0; i < states; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "State " << i << " to '" << inputSymbols[j] << "' -> " << mat[i][j] << endl;
        }
        cout << endl;
    }

    int t;
    cout<<"Enter number of testcases: ";
    cin>>t;

    while(t--)
    {
        string input;
        cout << "Enter string input: ";
        cin >> input;

        int currentState = initial;
        for (char c : input)
        {
            int intermediate = -1;
            for (int j = 0; j < n; j++)
            {
                if (c == inputSymbols[j])
                {
                    intermediate = j;
                    break;
                }
            }

            if (intermediate == -1)
            {
                cout << "Invalid symbol in input string: " << c << endl;
                return 1;
            }

            currentState = mat[currentState][intermediate];
        }

        cout << "Final state: " << currentState << endl;

        bool isValid = false;
        for (int state : acceptingStates)
        {
            if (currentState == state)
            {
                isValid = true;
                break;
            }
        }

        if (isValid)
        {
            cout << "Valid String" << endl;
        }
        else
        {
            cout << "Invalid String" << endl;
        }
    }

    return 0;
}
