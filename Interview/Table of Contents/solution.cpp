#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'tableOfContents' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY text as parameter.
 */

vector<string> tableOfContents(vector<string> text) {
    int chap = 0;
    int sec = 0;
    string s;
    vector<string> output;
    for (int i=0; i<text.size(); i++) {
        if(text[i][0] == '#') {
            if(text[i][1] == '#') {
                sec++;
                s = to_string(chap) + '.' + to_string(sec) + '.' + text[i].substr(text[i].find(' ')); 
                output.push_back(s);
            }
            else{
                chap++;
                sec = 0;
                s = to_string(chap) + '.' + text[i].substr(text[i].find(' ')); 
                output.push_back(s);
            }
        }
    }
    return output;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string text_count_temp;
    getline(cin, text_count_temp);

    int text_count = stoi(ltrim(rtrim(text_count_temp)));

    vector<string> text(text_count);

    for (int i = 0; i < text_count; i++) {
        string text_item;
        getline(cin, text_item);

        text[i] = text_item;
    }

    vector<string> result = tableOfContents(text);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
