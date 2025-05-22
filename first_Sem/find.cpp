#include <iostream>
using namespace std;

// Function Prototypes
void readList(int list[], int &size);
int findSubsequence(const int firstList[], int firstSize, const int secondList[], int secondSize, int resultIndices[]);
void outputResults(const int resultIndices[], int matchCount);

int main()
{
    const int MAX_SIZE = 100;
    int firstList[MAX_SIZE], secondList[MAX_SIZE], resultIndices[MAX_SIZE];
    int firstSize, secondSize, matchCount;

    // Read the two lists
    readList(firstList, firstSize);
    readList(secondList, secondSize);

    // Find subsequence matches
    matchCount = findSubsequence(firstList, firstSize, secondList, secondSize, resultIndices);

    // Output the results
    outputResults(resultIndices, matchCount);

    return 0;
}

/**
 * Reads a list of integers from standard input.
 * The first number is the size of the list, followed by the list elements.
 *
 * @param list Array to store the input list.
 * @param size Reference to the size variable to store the number of elements in the list.
 */
void readList(int list[], int &size)
{
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> list[i];
    }
}

/**
 * Finds starting indices where the second list appears as a subsequence in the first list.
 *
 * @param firstList Array containing the first list of integers.
 * @param firstSize Number of elements in the first list.
 * @param secondList Array containing the second list of integers.
 * @param secondSize Number of elements in the second list.
 * @param resultIndices Array to store the starting indices of matches.
 * @return The number of matches found.
 */
int findSubsequence(const int firstList[], int firstSize, const int secondList[], int secondSize, int resultIndices[])
{
    int matchCount = 0;

    // Check each starting position in the first list
    for (int i = 0; i <= firstSize - secondSize; i++)
    {
        bool match = true;

        // Compare elements in the second list with a subsequence of the first list
        for (int j = 0; j < secondSize; j++)
        {
            if (firstList[i + j] != secondList[j])
            {
                match = false;
                break;
            }
        }

        // Record the index if a match is found
        if (match)
        {
            resultIndices[matchCount] = i;
            matchCount++;
        }
    }

    return matchCount;
}

/**
 * Outputs the results of the subsequence search.
 *
 * @param resultIndices Array containing the starting indices of matches.
 * @param matchCount Number of matches found.
 */
void outputResults(const int resultIndices[], int matchCount)
{
    if (matchCount == 0)
    {
        cout << "does not appear" << endl;
    }
    else
    {
        for (int i = 0; i < matchCount; i++)
        {
            cout << resultIndices[i] << endl;
        }
    }
}
