#include<vector>
#include<string>
#include<iostream>

/* -------------------------------- */
// GOAL: Find the longest prefix
// that is common to all strings in
// the input vector.
//
// CONSTRAINTS: Input characters are
// all lower case. No more than 200
// strings are in the vector and
// each string has no more than
// 200 characters.
/* -------------------------------- */
// TIME COMPLEXITY: O(n^2)
// SPACE COMPLEXITY: O(1)
//
// DESCRIPTION: Each string in the
// vector is compared with the
// first string in the vector, so
// the first string is the baseline.
// Speed is enhanced during comparison
// by breaking the inner loop when
// first uncommon character is
// encountered, thus moving onto the
// next string.
/* -------------------------------- */

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Current Match is the matching prefix for the string that is currently
        // being compared to the first string
        std::string longestCurrentMatch = "";
        // Longest Match holds that value for the shortest matching prefix, see why
        // it is the shortest further down
        std::string longestMatch = strs[0];
        int firstStringIterator = 0;
        for(int i = 1; i < strs.size(); i++)
        {
            firstStringIterator = 0;
            longestCurrentMatch = "";
            for(int j = 0; j < strs[i].size(); j++)
            {
                // Ensure that characters match and the comparison string index (j) does not
                // surpass the first string index (firstStringIterator)
                if(firstStringIterator <= j && strs[0][firstStringIterator] == strs[i][j])
                {
                    longestCurrentMatch += strs[i][j];
                    firstStringIterator++;
                }
                // Break when first uncommon character is found
                else
                    break;
            }
            // If a shorter match is found, set that to the new longest match. This is
            // because a shorter match implies the new comparison string does not share
            // as many characters as an older comparison string, so the total match must
            // be updated.
            if(longestCurrentMatch.size() < longestMatch.size())
            {
                longestMatch = longestCurrentMatch;
            }
        }
        return longestMatch;
    }
};

// Driver Code
int main()
{
    Solution sln;
    std::vector< std::string > potentialMatches;
    // Input 3 strings, longest prefix match is "fl"
    potentialMatches.push_back("flowers");
    potentialMatches.push_back("flight");
    potentialMatches.push_back("flourish");
    std::cout << "Longest Match: " << sln.longestCommonPrefix(potentialMatches) << std::endl;
    return 0;
}