// Generates random sentences using predefined word lists. 
// Randomly select words from four arrays
// 1. article
// 2. noun
// 3. verb
// 4. preposition

// Article + Noun + Verb + Preposition + Article + Noun.

// Seed Value
// 8 sentences
// sentences
// 1. start with capital
// 2. end with period
// 3. single space between words

// string article[] = { "the", "a", "one", "some", "any" };
// string noun[] = { "boy", "girl", "dog", "town", "car" };
//  string verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
// string preposition[] = { "to", "from", "over", "under", "on" };


#include <iostream>

using namespace std;

int main()
{
    string article[] = { "the", "a", "one", "some", "any" };
    string noun[] = { "boy", "girl", "dog", "town", "car" };
     string verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
    string preposition[] = { "to", "from", "over", "under", "on" };
    
    int seed = 0;
    cout << "Enter the seed value: ";
    cin >> seed;
    srand(seed);
    
    string word1;
    string word2;
    string word3;
    string word4;
    string word5;
    string word6;
    
    string sentence;
    
    cout << endl;
    
    for(int i = 0; i < 8; i++)
    {
        word1 = article[rand() % 5];
        word2 = noun[rand() % 5];
        word3 = verb[rand() % 5];
        word4 = preposition[rand() % 5];
        word5 = article[rand() % 5];
        word6 = noun[rand() % 5];
        
        word1[0] = toupper(word1[0]);
        
        sentence = word1 + " " + word2 + " " + word3 + " " + word4 + " " + 
        word5 + " " + word6 + " ";
        
        cout << sentence << endl;
    }
    
    return 0;
}