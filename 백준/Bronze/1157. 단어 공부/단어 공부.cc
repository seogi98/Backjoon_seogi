/*input
Mississipi
*/
#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_COUNT 26

int alphabetToIndex(char c)
{
   return c - 'A';
}

int main()
{
   char alphabet;
   char givenCharacter;
   char mostFrequentChar;
   int countOfCharaters[ALPHABET_COUNT] = {
       0,
   };
   int mostFrequentCharCount = 0;
   string tmp;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
   std::cin >> tmp;
   for (auto i : tmp)
   {

      countOfCharaters[tolower(i) - 'a']++;
   }

   for (alphabet = 'A'; alphabet <= 'Z'; alphabet++)
   {
      if (countOfCharaters[alphabetToIndex(alphabet)] > mostFrequentCharCount)
      {
         mostFrequentCharCount = countOfCharaters[alphabetToIndex(alphabet)];
         mostFrequentChar = alphabet;
      }
      else if (countOfCharaters[alphabetToIndex(alphabet)] == mostFrequentCharCount)
      {
         mostFrequentChar = '?';
      }
   }

   std::cout << mostFrequentChar;
   return 0;
}