#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself. 
  

104 = '1101000'

*/

char* addBinary(char* a, char* b) {
    int lenA = strlen(a), lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    
    // Result can be at most maxLen + 1 (for a possible carry)
    char* result = (char*)malloc(maxLen + 2); // +1 for carry and +1 for '\0'
    int carry = 0, i = lenA - 1, j = lenB - 1, k = 0;
    
    // Traverse both strings from right to left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        // Add the current digit from a if available
        if (i >= 0) {
            sum += a[i] - '0';  // Convert char '0'/'1' to integer
            i--;
        }
        
        // Add the current digit from b if available
        if (j >= 0) {
            sum += b[j] - '0';  // Convert char '0'/'1' to integer
            j--;
        }
        
        // The result digit is sum % 2
        result[k++] = (sum % 2) + '0';  // Convert back to char '0'/'1'
        
        // Update carry for next iteration
        carry = sum / 2;
    }
    
    // Null-terminate the result
    result[k] = '\0';
    
    // Reverse the result string
    for (int start = 0, end = k - 1; start < end; start++, end--) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
    }
    
    return result;    
}

int main(int argc, char *argv[])
{
    // Example 1
    char *a = "11";
    char *b = "1";
    printf("%s+%s=%s\n",a,b,addBinary(a,b));

    // Example 2
    char *aa = "1010";
    char *bb = "1011";
    printf("%s+%s=%s\n",aa,bb,addBinary(aa,bb));
    
    return EXIT_SUCCESS;
}

