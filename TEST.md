Test Case 1 Regular Number:
Everything should be normal and I believe it supports some millions

Input: $ ./output
12345
Output: 12345 = one hundred twenty three dollars and forty five cents
PS. if run the same number again it will go with the cache function

Test Case 2 Negative Cases:
Maybe someone wants to calculate their debt. For now thats not an option but they can put their number in without the negative. This is just for
maintaining functionality and not seeing weird symbols

Input: -1
Output: Error: Negative values are not allowed. Please enter a valid number

Test Case 3 Bigger Number:
Slightly bigger number just to show that it can handel some of those
$ ./output
1754975314
1754975314 = seventeen million five hundred forty nine thousand seven hundred fifty three dollars and fourteen cents

$ ./output
45675678
45675678 = four hundred fifty six thousand seven hundred fifty six dollars and seventy eight cents

Test Case 4 A Character:
Maybe Someone wanted to try it the other way around. Well that would completely break that so no thanks and just giving a warning

Input: a
Output: Error: Characters are not allowed. Please enter a valid number.
