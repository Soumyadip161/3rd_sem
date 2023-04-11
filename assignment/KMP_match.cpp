#include<iostream>
#include<string.h>
using namespace std;
int cost=0;
void prefixSuffixArray(char* pat, int M, int* pps) {
   int length = 0;
   pps[0] = 0;
   int i = 1;
   while (i < M) {
      cost++;
      if (pat[i] == pat[length]) {
         cost++;
         length++;
         pps[i] = length;
         i++;
         cost+=3;
      } else {
         if (length != 0){
            cost+=2;
         length = pps[length - 1];
         }
         else {
            cost+=2;
            pps[i] = 0;
            i++;
         }
      }
   }
}
void KMPAlgorithm(char* text, char* pattern) {
   int M = strlen(pattern);
   int N = strlen(text);
   int pps[M];
   prefixSuffixArray(pattern, M, pps);
   int i = 0;
    int j = 0;
   while (i < N) {
      cost++;
      if (pattern[j] == text[i]) {
         j++;
         i++;
         cost+=3;
      }
      if (j == M) {
         printf("Found pattern at index %d\n", i - j);
         j = pps[j - 1];
         cost+=3;
      }
      else if (i < N && pattern[j] != text[i]) {
         cost++;
         if (j != 0)
         j = pps[j - 1];
           else
         i = i + 1;
         cost+=2;
      }
   }
}
int main() {
   char text[] = "ababcbc";
   char pattern[] = "bcbc";
   printf("The pattern is found in the text at the following index : ");
   KMPAlgorithm(text, pattern);
   cout<<"Total cost="<<cost<<endl;
   return 0;
}
