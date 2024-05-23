#include <bits/stdc++.h>
using namespace std;

bool isNumeric(const string &s)
{
    return all_of(s.begin(), s.end(), ::isdigit);
}

bool compareHoldingNumbers(const string &a, const string &b)
{

    if (isNumeric(a) && isNumeric(b))
    {
        return stoi(a) < stoi(b);
    }

    if (isdigit(a[0]) && isdigit(b[0]))
    {
        int i = 0, j = 0;
        while (i < a.size() && isdigit(a[i])) i++;
        while (j < b.size() && isdigit(b[j])) j++;

        int n1 = stoi(a.substr(0, i));
        int n2 = stoi(b.substr(0, j));

        if (n1 != n2)
        {
            return n1 < n2;
        }

        return a.substr(i) < b.substr(j);
    }

    return a < b;
}

void sortHoldingNumbers(vector<string> &holding_numbers)
{
    sort(holding_numbers.begin(), holding_numbers.end(), compareHoldingNumbers);
}

int main()
{
    vector<string> holding_numbers =
    {
        "20/b/1", "20/a", "102/GHA/3", "102/Ga/4", "10/a", "182/ka", "20", "001",
        "gp cha 182", "102/GHA/1", "gp cha 136"
    };

    sortHoldingNumbers(holding_numbers);

    for(const auto &number : holding_numbers)
    {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
