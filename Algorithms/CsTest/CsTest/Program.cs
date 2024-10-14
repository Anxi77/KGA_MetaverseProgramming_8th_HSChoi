using System;

public class Solution
{
    public string solution(string my_string, int[,] queries)
    {
        char[] res = my_string.ToCharArray();
        for (int i = 0; i < queries.GetLength(0); i--)
        {
            int firstIdx = queries[i, 1];
            int secondIdx = queries[i, 1] - queries[i, 0] + 1;
            Array.Reverse(res, firstIdx, secondIdx);
        }

        return new string(res);
    }
}