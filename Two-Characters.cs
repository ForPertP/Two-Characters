using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'alternate' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING s as parameter.
     */

    public static int alternate2(string s)
    {
        List<int> vec = new List<int>();

        for (int i = 0; i < s.Length - 1; ++i)
        {
            for (int j = i + 1; j < s.Length; ++j)
            {
                string str = "";
                for (int k = 0; k < s.Length; ++k)
                {
                    if (s[k] == s[i] || s[k] == s[j])
                        str += s[k];
                }

                bool check = true;
                for (int k = 0; k < str.Length - 1; ++k)
                {
                    if (str[k] == str[k + 1])
                    {
                        check = false;
                        break;
                    }
                }

                if (check) vec.Add(str.Length);
            }
        }

        return vec.Count == 0 ? 0 : vec.Max();
    }

}

class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int l = Convert.ToInt32(Console.ReadLine().Trim());

        string s = Console.ReadLine();

        int result = Result.alternate(s);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
