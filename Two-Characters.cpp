int alternate(string s)
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

