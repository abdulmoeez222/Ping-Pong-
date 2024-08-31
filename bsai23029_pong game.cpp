#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>

using namespace std;
char wall = -37;
int difficulty;
int score1 = 0, score2 = 0;
void gotoRowCol(int rpos, int cpos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int tcl, int bcl)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (tcl + (bcl * 16)));
}

void draw_boundaries(int bar1, int bar2, int bar3, int bar4) {
    gotoRowCol(0, 0);
    int length = 15, width = 60;
    char wall = -37;
    int height = 4;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == length - 1 || j == 0 || j == width - 1) {
                cout << wall;
            }
            else {
                cout << " ";
            }
            if (j == 3 && i >= 7 && i <= 10) {

                gotoRowCol(i, j);


                cout << wall;

            }
            if (j == 56 && i >= 7 && i <= 10) {
                gotoRowCol(i, j);
                cout << wall;
            }
        }

        cout << endl;
    }
}

void ball_move(char ball, int bar1, int bar2, int bar3, int bar4) {
    int i = 15 / 2, j = 60 / 2;
    int pi = 1, pj = 1;
    int playagain;
    gotoRowCol(7, 3);
    cout << wall;
    gotoRowCol(10, 56);
    cout << wall;

    for (int k = 0;; k++) {
        if (score1 == 7 || score2 == 7)
        {
            gotoRowCol(0, 0);
            cout << "Do you Wish to replay:" << endl;
            cout << " YES " << endl;
            cout << " NO  " << endl;
            cin >> playagain;
            if (playagain == 1) {
                score1 = 0;
                score2 = 0;
                system("ClS");
                cout << "1-NOOB" << endl << "2-THORA SA MOOB " << endl << "3-PRO LEVEL MODE" << endl << "Select Difficulty: ";
                cin >> difficulty;
                gotoRowCol(4, 100);
                {cout << "Player1" << "  |  " << "Player2" << endl;
                gotoRowCol(5, 100);
                cout << "              |               "; }
                gotoRowCol(6, 100);
                cout << "    " << score1 << "       " << score2;
                draw_boundaries(7, 10, 7, 10);
                ball_move(167, 7, 10, 7, 10);
            }
            else if (playagain == 2) {
                cout << " GAME END !!!!" << endl;
                break;
            }
        }

        if (_kbhit()) {
            char key = _getch();
            if (key == 'W' || key == 'w' && bar1 > 1) {

                gotoRowCol(bar1 - 1, 3);
                cout << wall;

                bar1--;
                gotoRowCol(bar2, 3);
                cout << " ";
                {bar2--; }
            }
            if (key == 'S' || key == 's' && bar1 < 10) {
                gotoRowCol(bar2 + 1, 3);
                cout << wall;

                bar2++;
                gotoRowCol(bar1, 3);
                cout << " ";
                {bar1++; }
            }
            if (key == 'I' || key == 'i' && bar3 > 1) {
                gotoRowCol(bar3 - 1, 56);
                cout << wall;

                bar3--;
                gotoRowCol(bar4, 56);
                cout << " ";
                {bar4--; }
            }
            if (key == 'K' || key == 'k' && bar3 < 10) {
                gotoRowCol(bar4 + 1, 56);
                cout << wall;

                bar4++;
                gotoRowCol(bar3, 56);
                cout << " ";
                {bar3++; }
            }
        }
        if (difficulty == 1) {
            Sleep(90);
        }
        else if (difficulty == 2) {
            Sleep(70);

        }
        else if (difficulty == 3) {
            Sleep(50);

        }
        gotoRowCol(i, j);
        cout << " ";
        i += pi;
        j += pj;
        gotoRowCol(i, j);
        cout << ball;

        if (i == 1 || i == 13) {
            pi = -pi;
        }

        if (j == 1) {

            system("CLS");
            score2++;

            gotoRowCol(4, 100);
            {cout << "Player1" << "  | " << "Player2"; }
            gotoRowCol(5, 100); {
                cout << "     |               "; }

            if (score2 == 7)
            {
                gotoRowCol(10, 40);
                {
                    cout << " CONGRATULATION !!!! Player2 win";
                    break;
                }

            }
            gotoRowCol(6, 100);
            cout << "    " << score1 << "       " << score2;
            draw_boundaries(7, 11, 7, 11);
            ball_move(167, 7, 11, 7, 11);

        }
        if (j == 58) {

            system("CLS");
            score1++;
            gotoRowCol(4, 100);
            {cout << "Player1" << "  |  " << "Player2"; }
            gotoRowCol(5, 100); {
                cout << "         |         "; }

            gotoRowCol(6, 100);
            cout << "    " << score1 << "       " << score2;
            if (score1 == 7)
            {
                gotoRowCol(10, 40);
                {
                    cout << "  CONGRATULATION !!!! Player1 win";
                    break;
                }
            }
            draw_boundaries(7, 10, 7, 10);
            ball_move(167, 7, 10, 7, 10);

        }

        if (j == 4 && i >= bar1 && i <= bar2) {
            pj = -pj;
        }

        if (j == 55 && i >= bar3 && i <= bar4) {
            pj = -pj;
        }
    }
}


int main() {
    char ball = 167;
    int bar1 = 7, bar2 = 10, bar3 = 7, bar4 = 10;
    gotoRowCol(5, 50);
    cout << "WELCOME TO PING PONG !!!!" << endl;
    cout << "1-NOOB" << endl << "2-THORA SA MOOB " << endl << "3-PRO LEVEL MODE" << endl << "Select Difficulty: ";
    cin >> difficulty;
    gotoRowCol(4, 100);
    {cout << "Player1" << "   " << "Player2"; }
    gotoRowCol(5, 100);
    cout << "    " << score1 << "       " << score2;
    draw_boundaries(bar1, bar2, bar3, bar4);
    ball_move(ball, bar1, bar2, bar3, bar4);

    return 0;
}