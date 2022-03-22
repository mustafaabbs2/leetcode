// Given a string, find the length of the longest substring in it with no more than K distinct characters.

// Input: String="araaci", K=2
// Output: 4
// Explanation: The longest substring with no more than '2' distinct characters is "araa".

// Input: String="cbbebi", K=3
// Output: 5
// Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".


//NOTE - whenever there are char problems relating to frequency, use a hashmap

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class LongestSubstringK
{
private:
    /* data */
public:
    static int findLongestSub(const string s, int k)
    {
        int windowStart = 0;
        int maxLength = 0; 
        unordered_map <char, int> charFrequencyMap; 
        //to remember frequency, you will need a hashmap

        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++)
        {
            char rightCar = s[windowEnd];
            charFrequencyMap[rightCar]++;
            //add new char to hashmap

            // ..following loop loops through hashmap
            while(charFrequencyMap.size() > k) //if the map has more than k distinct entries
            {
                char leftChar = s[windowStart];
                charFrequencyMap[leftChar] --;

                //if the frequency is 0, erase the character
                if (charFrequencyMap[leftChar] == 0)
                    charFrequencyMap.erase(leftChar);
                    //function to erase from a map

                windowStart++; //shrink window
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1); 


        }
        
    return maxLength; 


    }


};

int main(int argc, char *argv[]) 
{
  cout << "Length of the longest substring: " << LongestSubstringK::findLongestSub("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringK::findLongestSub("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringK::findLongestSub("cbbebi", 3)
       << endl;
}

