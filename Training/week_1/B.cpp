
//
// Created by Mohamad on 7/17/2018.
// https://vjudge.net/contest/237859#problem/B
//

#include <iostream>

using namespace std;


class WTF {
    string input, whole, fraction;
    int len, wholeLen, fracLen;
    int exp;

public:
    /*WTF(string &s) {
        input = s;
        len = input.length();
        int dotPos = input.find('.');
        if (dotPos == string::npos) { // agar noghte nadasht
            fracLen = 0; //fraction ham nadare
            fraction = "";
            int fd = input.find_first_not_of('0'); // avalin raghame gheyre 0 ro peyda kon.
            if (fd == string::npos) { // age peyda nashod, yani hame 0 an;
                whole = "0";
                wholeLen = 1;
            } else { //age peyda shod yani az oon ragham ta akhar.
                whole = input.substr(fd);
                wholeLen = len - fd;
            }
        } else { //agar noghte dasht.
            if (dotPos == 0) { //yani noghte avaleshe
                wholeLen = 1;
                whole = "0";
                int soff = dotPos + 1;
                int eoff = input.find_last_not_of('0');
                if (eoff == dotPos) // yani hame fraction 0 e;
                {
                    fraction = "";
                    fracLen = 0;
                } else {
                    fraction = input.substr(soff, eoff);
                    fracLen = eoff-soff+1;
                }
                print();
            } else if (dotPos == len-1) //agar noghte akharishe
            {
                fracLen = 0;
                fraction = "";
                int fd = input.find_first_not_of('0');
                if (fd == len-1) { // age peyda nashod, yani hame 0 an.
                    whole = "0";
                    wholeLen = 1;
                } else { //age peyda shod yani az oon ragham ta ghable noghte
                    whole = input.substr(fd, len-2);
                    wholeLen = len - fd -1;
                }
            }
        }
    }*/
    explicit WTF(string &s) {
        input = s;
        len = input.length();
        wholeLen = -1;
        fracLen = -1;
        exp = 0;
        int dpos = s.find('.');
        if (dpos == string::npos) {
            whole = input;
            fraction = "";
        } else {
            whole = input.substr(0, (unsigned int) dpos);
            fraction = input.substr((unsigned int) (dpos + 1), (unsigned int) (len - 1));
        }
        parseWhole();
        parseFrac();
        makeScientific();
        print();

    }

    void print() {
        if (wholeLen == 1) {
            if (fracLen == 0) {
                if (exp == 0)
                    cout << whole << endl;
                else
                    cout << whole << "E" << exp << endl;
            } else {
                if (exp == 0)
                    cout << whole << "." << fraction << endl;
                else
                    cout << whole << "." << fraction << "E" << exp << endl;
            }
            return;
        }
    }


private:
    void parseWhole() {
        int fd = whole.find_first_not_of('0');
        if (fd == string::npos) {
            whole = "";
            wholeLen = 0;
            return;
        }
        whole = whole.substr((unsigned int) (fd));
        wholeLen = whole.length();
    }

    void parseFrac() {
//        cout << "in parsefrac, frac=[" << fraction << "]" << endl;
        int ld = fraction.find_last_not_of('0');
//        cout << ld <<endl;
        if (ld == string::npos) {
            fraction = "";
            fracLen = 0;
            return;
        }
        fraction = fraction.substr(0, (unsigned int) (ld + 1));
        fracLen = fraction.length();
    }

    void makeScientific() {
        if (wholeLen == 0) {
            if (fracLen == 0) {
                whole = "0";
                wholeLen = 1;
            } else {
                int ffd = fraction.find_first_not_of('0');
                exp = -(ffd + 1);
                whole.push_back(fraction.at((unsigned int) ffd));
                wholeLen = 1;
                fraction = fraction.substr((unsigned int) ffd + 1);
                fracLen -= (ffd + 1);
            }
        } else if (wholeLen == 1);
        else {
//            cout << wholeLen <<endl;
//            cout <<"here"<<endl;
            string temp = whole.substr(1);
            temp.append(fraction);
            fraction = temp;
            whole = whole.substr(0, 1);
            exp = wholeLen - 1;
            parseFrac();
            parseWhole();


        }
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    WTF wtf(s);

}