#include<iostream>
#include"math.h"

/* -------------------------------- */
// GOAL: Reverse the digits of the
// integer input.
//
// CONSTRAINTS: Input is an integer,
// but if the reversed input is
// larger/smaller than the max/min
// integer size, return 0.
/* -------------------------------- */
// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)
//
// DESCRIPTION: This is an
// efficient solution since it
// does not rely on integer to
// string conversion, only 
// numerical calculations.
/* -------------------------------- */

class Solution {
public:
    int reverse(int x) {

        bool isSigned = false;
        // Convert to long so that overflow does not occur during comparisons
        long inputInt = x;
        if(x < 0)
        {
            isSigned = true;
            // For edge case of converting minimum possible integer, convert to 0 
            // if sign change causes overflow
            inputInt = ((-1)*(inputInt) > (pow(2,31) - 1)) ? 0 : (-1)*inputInt;
        }

        int NumberOfDigits = inputInt == 0 ? 0 : log10(inputInt) + 1;
        int ReversedInteger = 0;
        int TempInteger;

        for(int i = 0; i < NumberOfDigits; i++)
        {
            // Remove less significant digits by dividing by magnitude (and typecasting to int), 
            // then remove more significant digits by modulo 10, thus isolating the single digit 
            // into TempInteger
            TempInteger = (int)(inputInt / pow(10,NumberOfDigits - i - 1)) % 10;

            // Ensure each new sum does not cause overflow while adding to reversed result
            if(ReversedInteger + TempInteger * pow(10,i) > pow(2,31) - 1)
                return 0;

            // Multiply digit by magnitude and add to reversed result
            ReversedInteger += TempInteger * pow(10,i);
        }
        
        if(isSigned)
            ReversedInteger*= -1;
            
        return ReversedInteger;
    }
};

// Driver Code
int main()
{
    Solution sln;
    // Testing minimum possible integer edge case: -2147483648
    std::cout << "Reversed Integer : " << (sln.reverse(-2147483648)) << std::endl;
    return 0;
}