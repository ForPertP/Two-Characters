#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s)
{
    unordered_set<char> unique_chars(s.begin(), s.end());
    vector<char> chars(unique_chars.begin(), unique_chars.end());
    int max_length = 0;

    for (size_t i = 0; i < chars.size() - 1; ++i)
    {
        for (size_t j = i + 1; j < chars.size(); ++j)
        {
            char first = chars[i], second = chars[j];
            int length = 0;
            char last = 0;
            
            for (char c : s)
            {
                if (c == first || c == second)
                {
                    if (c == last)
                    {
                        length = 0;
                        break;
                    }
                    last = c;
                    ++length;
                }
            }

            max_length = max(max_length, length);
        }
    }

    return max_length;
}


int alternate2(string s)
{
    vector<int> vec;
    
    for (int i = 0; i < s.size()-1; ++i)
    {
        for (int j = i + 1; j < s.size(); ++j)
        {
            std::string str{};
            for (int k = 0; k < s.size(); ++k)
            {
                if(s[k] == s[i] || s[k] == s[j])
                {
                    str += s[k];
                }
            }
            
            bool check = true;
            for (int k = 0; k < str.size()-1; ++k)
            {
                if (str[k] == str[k+1])
                {
                    check = false;
                    break;
                }
            }
            
            if (check) vec.push_back(str.size());
        }
    }
    
    return vec.empty() ? 0 : *std::max_element(vec.begin(),vec.end());
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string rtrim(const std::string &str)
{
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(), s.end()
    );
    return s;
}
