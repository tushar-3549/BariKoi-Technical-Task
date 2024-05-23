#include <bits/stdc++.h>
using namespace std;
string toLowerCase(string &s)
{
    string x = s;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    return x;
}
int distance(string &s1, string &s2)
{
    int d = 0;
    for(int i = 0; i < s2.size(); i++)
    {
        if(s1[i] != s2[i])
          d++;
    }
    return d;
}
int main()
{
    string original = "Bangladesh";
    vector <string> wordList = {"bangladfsh", "bangla desh", "banglsdwsh", "zydesh", "banladesh",
                                "bangladesh"};
    vector <string> matches;
    string lower_original = toLowerCase(original);
    /*for(auto i: lower_original) {
        cout << i;
    }*/
    int original_length = original.size();
    for(string &word: wordList) {
        string lower_word = toLowerCase(word);
        if(lower_word.size() == original_length) {
            int dis = distance(lower_original, lower_word);
            if(dis <= 2)
              matches.push_back(word);
        }
    }
    for(int i = 0; i < matches.size(); i++)
    {
        cout << "'" << matches[i] << "'";
        if(i < matches.size() -1)
          cout << ", ";
    }
    cout << endl;

    return 0;

}
