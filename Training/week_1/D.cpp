//
// Created by Mohamad on 7/31/2018.
// https://vjudge.net/contest/237859#problem/D
//

#include <bits/stdc++.h>

#define TRACE(x) cerr << #x << " : " << x << endl
#define _ << " - " <<

using namespace std;



struct Code {
    string rock;
    string paper;
    string scissors;
};


map<string, Code> codes;

void init() {
    codes["cs"].rock = "Kamen";
    codes["cs"].scissors = "Nuzky";
    codes["cs"].paper = "Papir";

    codes["en"].rock = "Rock";
    codes["en"].scissors = "Scissors";
    codes["en"].paper = "Paper";


    codes["fr"].rock = "Pierre";
    codes["fr"].scissors = "Ciseaux";
    codes["fr"].paper = "Feuille";

    codes["de"].rock = "Stein";
    codes["de"].scissors = "Schere";
    codes["de"].paper = "Papier";

    codes["hu"].rock = "Ko | Koe";
    codes["hu"].scissors = "Ollo | Olloo";
    codes["hu"].paper = "Papir";

    codes["it"].rock = "Sasso | Roccia";
    codes["it"].scissors = "Forbice";
    codes["it"].paper = "Carta | Rete";

    codes["jp"].rock = "Guu";
    codes["jp"].scissors = "Choki";
    codes["jp"].paper = "Paa";

    codes["pl"].rock = "Kamien";
    codes["pl"].scissors = "Nozyce";
    codes["pl"].paper = "Papier";

    codes["es"].rock = "Piedra";
    codes["es"].scissors = "Tijera";
    codes["es"].paper = "Papel";

}

class Player {
public:
    string lang;
    string name;
    int score;

    explicit Player(string &lang, string &name) {
        score = 0;
    }

    explicit Player() {
        score = 0;
    }

    void init(string &lang, string &name) {
        this->lang = lang;
        this->name = name;
        score = 0;
    }

};

int interpret(const Player &p, const string &s) {

//    TRACE(p.lang _ s);
//    TRACE(codes["cs"].paper _ codes["cs"].scissors _ codes["cs"].rock);
    if (codes[p.lang].paper.find(s) != string::npos)
        return 0;
    else if (codes[p.lang].scissors.find(s) != string::npos)
        return 1;
    else
        return 2;
}

int whoWon$(int p1move, int p2move) {
    if (p1move == p2move)
        return 0;
    if (p1move == 0 && p2move == 2)
        return 1;
    if (p2move == 0 && p1move == 2)
        return 2;
    if (p1move < p2move)
        return 2;
    else
        return 1;
}

void playAHand(Player &p1, const string &p1c, Player &p2, const string &p2c) {
    int p1move = interpret(p1, p1c);
    int p2move = interpret(p2, p2c);
    int who = whoWon$(p1move, p2move);
//    TRACE(p1move _ p2move);
    if (who == 1)
        p1.score++;
    else if (who == 2)
        p2.score++;
}

void $print(const Player &p1, const Player &p2, int gnum) {
    cout << "Game #" << gnum << ":\n";
    cout << p1.name << ": " << p1.score << (p1.score == 1 ? " point" : " points") << "\n";
    cout << p2.name << ": " << p2.score << (p2.score == 1 ? " point" : " points") << "\n";
    if (p1.score == p2.score)
        cout << "TIED GAME\n";
    else
        cout << "WINNER: " << (p1.score > p2.score ? p1.name : p2.name) << "\n";
    cout << "\n";
}

int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    init();
    bool ended = false;
    Player p1, p2;
    int state = 0;
    string first, second;
    int gnum = 0;
    while (!ended) {
        if (state == 0) {
            cin >> first >> second;
            p1.init(first, second);
            cin >> first >> second;
            p2.init(first, second);
            state = 1;
        }
        if (state == 1) {
            cin >> first;
            if (first == "-") {
                gnum++;
                state = 2;
            } else if (first == ".") {
                gnum++;
                state = 3;
                ended = true;
            } else {
                cin >> second;
                playAHand(p1, first, p2, second);
            }
//            $print(p1,p2,gnum);
        }
        if (state == 2) {

            $print(p1, p2, gnum);
            state = 0;
        }
        if (state == 3) {
            $print(p1, p2, gnum);
        }

    }


    return 0;
}