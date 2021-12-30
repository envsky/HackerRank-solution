#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string output = "";
    int h = stoi(s.substr(0, 2));
    if(s.find("AM") != string::npos) {
        if(h == 12)
            output = "00" + s.substr(2, 6);
        else
            output = s.substr(0, 8);
    }
    else {
        if(h == 12)
            output = s.substr(0, 8);
        else 
            output = to_string(h+12) + s.substr(2, 6);
    }
    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}