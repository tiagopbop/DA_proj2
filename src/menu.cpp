#include "menu.h"
#include <iostream>

using namespace std;

int menu::Terminal() {

    int decision;
    int chs_fl;
    string input;

    cout << endl;
    cout << "\033[1;34mWelcome to the Analysis and Synthesis of Algorithms Tool\033[0m" << endl;
    cout << endl;
    cout << "\033[1;33mPlease select the data origin to be analyzed\033[0m" << endl;
    cout << "\033[1;33m[ 1 ]\033[0m" << " X" << endl;
    cout << "\033[1;33m[ 2 ]\033[0m" << " Y" << endl;
    cout << "\033[0;33mDISCLAIMER : This can be changed later without restarting the program\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    cin >> chs_fl;
    cout << endl;

    if (chs_fl == 1) {
        cout << "\033[1;32mX chosen successfully\033[0m" << endl;
    } else if (chs_fl == 2) {
        cout << "\033[1;32mY chosen successfully\033[0m" << endl;
    } else {
        cout << "\033[1;33mUnrecognized answer - Proceeding with Y\033[0m" << endl;
    }


    cout << endl << endl;
    cout << "\033[1;34mWhat do you wish to do?\033[0m" << endl;

    cout << "\033[1;36m[ 1 ]\033[0m" << " Use the Backtracking Algorithm" << endl;
    cout << "\033[1;36m[ 2 ]\033[0m" << " Use the Triangular Approximation Heuristic" << endl;
    cout << "\033[1;36m[ 3 ]\033[0m" << " Use other Heuristics" << endl;
    cout << "\033[1;36m[ 4 ]\033[0m" << " Use TSP in the real world" << endl;
    cout << "\033[1;33m[ 9 ] Change the input data being analyzed\033[0m" << endl;
    cout << "\033[1;31m[ 0 ] Quit\033[0m" << endl;
    cout << endl;

    cout << "\033[1;34mDecision: \033[0m";
    cin >> decision;
    cout << endl << endl;

    while (decision != 0) {
        switch (decision) {
            case 1:



                break;
            case 2:



                break;
            case 3:



                break;
            case 4:



                break;
            case 9:



                if (chs_fl == 1) {
                    cout << "\033[1;32mSwitched to Y successfully\033[0m" << endl << endl;
                    chs_fl = 2;
                } else {
                    cout << "\033[1;32mSwitched to X successfully\033[0m" << endl << endl;
                    chs_fl = 1;
                }



                break;
            case 0:

                break;
            default:

                cout << "\033[1;31mInput error - Going back\033[0m" << endl << endl;
                decision = 1;

                break;
        }

        if (decision != 0) {

            cout << "\033[1;34mWish to do anything else?\033[0m" << endl;

            cout << "\033[1;36m[ 1 ]\033[0m" << " Use the Backtracking Algorithm" << endl;
            cout << "\033[1;36m[ 2 ]\033[0m" << " Use the Triangular Approximation Heuristic" << endl;
            cout << "\033[1;36m[ 3 ]\033[0m" << " Use other Heuristics" << endl;
            cout << "\033[1;36m[ 4 ]\033[0m" << " Use TSP in the real world" << endl;
            cout << "\033[1;33m[ 9 ] Change the input data being analyzed\033[0m" << endl;
            cout << "\033[1;31m[ 0 ] Quit\033[0m" << endl;
            cout << endl;

            cout << "\033[1;34mDecision: \033[0m";
            cin >> decision;
            cout << endl << endl;

        }

    }

    return 0;
}