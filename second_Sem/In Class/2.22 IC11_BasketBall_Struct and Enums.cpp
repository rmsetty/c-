// Find the maximum, minimum, and average for any field of players. 

// File has name, scores, age, rebounds, steals, blocks, fouls. 

// player structure. 

// For maximum/minimum scores, program needs to output the name of players with scores.

// If you cannot open the file display an error message and exit.

// Read File + Count records

// Use seekg(0) and clear to start from beginning

// Define array of structures

// Left justified.

// Int values should be printed with setw(8) and Strings be printed with setw(16). 

// Function to calculate average, min, and max of any field. 
// The field can be “scores, “age”, “rebounds”, “fouls”, “steals”, “blocks”, “quit”

// parameters
// 1. array of structures 
// 2. size of the array
// 3. the field

// getMin - index of minimum element.

// getMax - index of maximum element.

// getAvg - the average of scores.


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Player
{
  string name;
  int scores;
  int age;
  int rebounds;
  int steals;
  int blocks;
  int fouls; 
};

enum Vital {Scores, Age, Steals, Fouls, Blocks, Rebounds, Quit};


int getMin(Player* players, int size, Vital field);
int getMax(Player* players, int size, Vital field);
double getAvg(Player* players, int size, Vital field);

int main()
{
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;
    
    ifstream inputFile;
    inputFile.open(fileName);
    
    if(!inputFile)
    {
        cout << "Cannot open file." << endl;
    }
    
    else
    {
        int countLine = 0;
        string line;
        getline(inputFile, line);
        while(getline(inputFile, line))
        {
            countLine++;
        }
        
        inputFile.clear();
        inputFile.seekg(0);
        
        getline(inputFile, line);
        
        Player* players = new Player[countLine];
        
        for(int i = 0; i < countLine; i++)
        {
            inputFile >> (players + i) -> name >> (players + i) -> age >> (players + i) -> scores  >> (players + i) -> rebounds >> (players + i) -> steals >> (players + i) -> blocks >> (players + i) -> fouls; 
        }
        
        inputFile.close();
        
        cout << left;
        cout << "Name" << setw(16) << "Age" << setw(8) << "Scores" << setw(8) << "Rebounds" << setw(8) << "Steals" << setw(8) << "Blocks" << setw(8) << "Fouls" << setw(8) << endl;
        
        for(int i = 0; i < countLine; i++)
        {
            cout << (players + i) -> name << setw(16) << (players + i) -> age << setw(8) << (players + i) -> scores << setw(8) << (players + i) -> rebounds << setw(8) << (players + i) -> steals << setw(8) << (players + i) -> blocks << setw(8) << (players + i) -> fouls << setw(8) << endl;
        }
        
        Vital field = 0;
        int minIndex;
        int maxIndex;
        int min = 0;
        int max = 0;
        double avg;
        string fieldString;
        
        while (field != Quit)
        {
            cout << "Enter the field for getting average, min and max" << endl;
            cout << "Please pick one item from the menu: " << endl;
            cout << "Enter 0 for Scores " << endl;
            cout << "Enter 1 for Age " << endl;
            cout << "Enter 2 for Steals " << endl;
            cout << "Enter 3 for Fouls " << endl;
            cout << "Enter 4 for Blocks " << endl;
            cout << "Enter 5 for Rebounds " << endl;
            cout << "Enter 6 for quit:  " << endl;

            cin >> field;
            cout << endl;
            
                
            if (field == Scores || field == Age || field == Steals || field == Fouls || field == Blocks || field == Rebounds || field == Quit) 
            {
                if(field != Quit)
                {
                    minIndex = getMin(players, countLine, field);
                    maxIndex = getMax(players, countLine, field);
                }
                
                switch(field)
                {
                    case Scores:
                        min = (players + minIndex)->scores;
                        max = (players + maxIndex)->scores;
                        fieldString = "Scores";
                        break;
                    
                    case Age:
                        min = (players + minIndex)->age;
                        max = (players + maxIndex)->age;
                        fieldString = "Age";
                        break;
                    
                    case Steals:
                        min = (players + minIndex)->steals;
                        max = (players + maxIndex)->steals;
                        fieldString = "Steals";
                        break;
                    
                    case Fouls:
                        min = (players + minIndex)->fouls;
                        max = (players + maxIndex)->fouls;
                        fieldString = "Fouls";
                        break;
                    
                    case Blocks:
                        min = (players + minIndex)->blocks;
                        max = (players + maxIndex)->blocks;
                        fieldString = "Blocks";
                        break;
                    
                    case Rebounds:
                        min = (players + minIndex)->rebounds;
                        max = (players + maxIndex)->rebounds;
                        fieldString = "Rebounds";
                        break;
                    
                    case Quit:
                        break;
                }
                
                if(field != Quit)
                {
                    avg = getAvg(players, countLine, field);
                        
                        
                    cout << "The average " << fieldString << " of the team is " << avg << endl;
                    cout << "The player with minimum " << fieldString << " is " << (players + minIndex) -> name << " = " << min << endl;
                    cout << "The player with maximum " << fieldString << " is " << (players + maxIndex) -> name << " = " << max << endl;
                }
            } 
            
            else 
            {
                cout << "Invalid field." << endl;
            }

        }
        
        cout << "Exiting!!!" << endl;
        
    delete[] players;
    players = nullptr;
    
    }
    
    return 0;
}

int getMin(Player* players, int size, Vital field)
{
    int minIndex = 0;

    for (int i = 1; i < size; i++)
    {
        bool isSmaller = false;

        if (field == Age) 
        {
            isSmaller = (players + i)->age < (players + minIndex)->age;
        } 
        
        else if (field == Rebounds) 
        {
            isSmaller = (players + i)->rebounds < (players + minIndex)->rebounds;
        } 
        
        else if (field == Steals) 
        {
            isSmaller = (players + i)->steals < (players + minIndex)->steals;
        } 
        
        else if (field == Blocks) 
        {
            isSmaller = (players + i)->blocks < (players + minIndex)->blocks;
        } 
        
        else if (field == Fouls) 
        {
            isSmaller = (players + i)->fouls < (players + minIndex)->fouls;
        } 
        
        else if (field == Scores) 
        {
            isSmaller = (players + i)->scores < (players + minIndex)->scores;
        }

        if (isSmaller) {
            minIndex = i;
        }
    }

    return minIndex;
}

int getMax(Player* players, int size, Vital field)
{
    int maxIndex = 0;
    
    for(int i = 1; i < size; i++)
    {
        bool isBigger = false;

        if (field == Age) 
        {
            isBigger = (players + i)->age > (players + maxIndex)->age;
        } 
        
        else if (field == Rebounds) 
        {
            isBigger = (players + i)->rebounds > (players + maxIndex)->rebounds;
        } 
        
        else if (field == Steals) 
        {
            isBigger = (players + i)->steals > (players + maxIndex)->steals;
        } 
        
        else if (field == Blocks) 
        {
            isBigger = (players + i)->blocks > (players + maxIndex)->blocks;
        } 
        
        else if (field == Fouls) 
        {
            isBigger = (players + i)->fouls > (players + maxIndex)->fouls;
        } 
        
        else if (field == Scores) 
        {
            isBigger = (players + i)->scores > (players + maxIndex)->scores;
        }

        if (isBigger) {
            maxIndex = i;
        }        
    }
    
    return maxIndex;
}

double getAvg(Player* players, int size, Vital field)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        if (field == Age) 
        {
            sum += (players + i)->age;
        } 
        
        else if (field == Rebounds) 
        {
            sum += (players + i)->rebounds;
        } 
        
        else if (field == Steals) 
        {
            sum += (players + i)->steals;
        } 
        
        else if (field == Blocks) 
        {
            sum += (players + i)->blocks;
        } 
        
        else if (field == Fouls) 
        {
            sum += (players + i)->fouls;
        } 
        
        else if (field == Scores) 
        {
            sum += (players + i)->scores;
        } 
    }
    
    double avg = sum / size;
    
    return avg;
}








