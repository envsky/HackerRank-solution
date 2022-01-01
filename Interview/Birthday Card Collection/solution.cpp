#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'hackerCards' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY collection
 *  2. INTEGER d
 */

vector<int> hackerCards(vector<int> collection, int d) {
    vector<int> output;
    int sum = 0;
    for(int i=1; i<=d; i++) {
        if(find(collection.begin(), collection.end(), i) != collection.end())
            continue;
        if(sum+i > d)
            break;
        sum += i;
        output.push_back(i);
    }
    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string collection_count_temp;
    getline(cin, collection_count_temp);

    int collection_count = stoi(ltrim(rtrim(collection_count_temp)));

    vector<int> collection(collection_count);

    for (int i = 0; i < collection_count; i++) {
        string collection_item_temp;
        getline(cin, collection_item_temp);

        int collection_item = stoi(ltrim(rtrim(collection_item_temp)));

        collection[i] = collection_item;
    }

    string d_temp;
    getline(cin, d_temp);

    int d = stoi(ltrim(rtrim(d_temp)));

    vector<int> result = hackerCards(collection, d);

    for (size_t i = 0; i < result.size(); i++) {
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