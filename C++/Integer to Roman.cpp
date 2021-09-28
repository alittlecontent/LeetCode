#include<string>
#include<map>
#include<iostream>

/* -------------------------------- */
// GOAL: Convert the input integer
// to roman numeral format.
//
// CONSTRAINTS: Integer is between
// 1 and 3999.
/* -------------------------------- */
// TIME COMPLEXITY: O(n) - increases with input
// SPACE COMPLEXITY: O(1) - only store the dictionary + statically defined variables
//
// DESCRIPTION: Using a dictionary
// to store numeral strings and their
// corresponding integer values
// seems like a very straight-
// forward implementation. If the
// difference between the input
// int and current dictionary value
// is negative, then append the
// previous dictionary entry's
// numeral value to final string
// and subtract that entry's
// integer value from the input.
// Iterate until input is zero.
/* -------------------------------- */

class Solution {
public:
    std::string intToRoman(int num) {
        std::string romanConversion = "";

        // Initialize dictionary of necessary roman numerals with integer keys and string values
        std::map<int,std::string> numeralValues;
        numeralValues[1] = "I";
        numeralValues[4] = "IV";
        numeralValues[5] = "V";
        numeralValues[9] = "IX";
        numeralValues[10] = "X";
        numeralValues[40] = "XL";
        numeralValues[50] = "L";
        numeralValues[90] = "XC";
        numeralValues[100] = "C";
        numeralValues[400] = "CD";
        numeralValues[500] = "D";
        numeralValues[900] = "CM";
        numeralValues[1000] = "M";

        // Initialize dictionary iterator to the beginning
        std::map<int,std::string>::iterator mapIterator = numeralValues.begin();

        // Execute if input has not yet been reduced to 0
        while(num != 0)
        {
            // Reset iterator
            mapIterator = numeralValues.begin();

            // Plan to compare all dictionary values to input
            for(int i = 0; i < numeralValues.size(); i++)
            {
                if(num - mapIterator->first < 0)
                {
                    // If difference is negative, append previous numeral string to
                    // final string
                    romanConversion += (--mapIterator)->second;
                    // substract previous integer value from input, re-increment iterator
                    num -= (mapIterator++)->first;
                    break;
                }
                mapIterator++;
            }
            // For the case of the input being greater than 1000, apply previous logic
            // for final dictionary entry
            if(num - 1000 >= 0)
            {
                romanConversion += numeralValues[1000];
                num -= 1000;
            }
        }
        return romanConversion;
    }
};

// Driver Code
int main() 
{
    Solution sln;
    int integerValue = 3567;
    std::cout << "Roman Numeral Conversion for " << integerValue << ": " << sln.intToRoman(integerValue) << std::endl;
    return 0;
}