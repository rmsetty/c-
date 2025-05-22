>>>>>>>>>>>>>1
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string str;

    cout << "Enter the name of the string: ";
    cin >> str;
    
    if (isPalindrome(str)) {
        cout << "The given string is a palindrome. \n";
    } else {
        cout << "The given string is not a palindrome. \n";
    }
    
    return 0;
}


>>>>>>>>>>>>>>>2

int main()
{
    int n, size, total =0, index=-1;
   
    // Enter your code
    // Get the size of the array from the user
    cin>>size;
    // Get the elements of the array from the user
   int arr[size];
   for(int i=0; i<size; i++){
      cin>>arr[i];
      //cout<<arr[i]<<endl;
      total+= arr[i];
      }
   n = total/2;
   
    // Find out the element with the sum
     for(int i=0; i<size; i++){
     if(arr[i] == n){
        index = i;
        break;
        }
      }
      // If index is found with the sum
      if(index>-1){
        cout << "Index " << index << " has the sum" << endl;   
      }
       // If no index is found with the sum
       else{
        cout << "No index has the sum" << endl;
       }
    return 0;
}

>>>>>>>>>>>3

#include <iostream>

using namespace std;

int main() {
    string s;
    int k;

    // Taking input
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the number of characters to rotate: ";
    cin >> k;

    // Finding the length of the string without using s.length()
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    // Adjust k to avoid unnecessary rotations
    k = k % n;

    // Rotate manually without using substr
    for (int i = 0; i < k; i++) {
        char temp = s[0];  // Store first character
        for (int j = 0; j < n - 1; j++) {
            s[j] = s[j + 1];  // Shift characters left
        }
        s[n - 1] = temp;  // Move first character to end
    }

    // Output rotated string
    cout << "Rotated string: " << s << endl;

    return 0;
}

>>>>>>>4


>>>>>>>>>>>>>>>>>>>>>>>5
#include <iostream>
using namespace std;

int main()
{
    int mrow, mcol;

    // Input the number of rows and columns
    cout << "Enter the number of rows and columns: ";
    cin >> mrow >> mcol;

    // Check if rows and columns are the same
    while (mrow != mcol) {
        cout << "The number of rows and columns must be same." << endl;
        cout << "Enter the number of rows and columns again: ";
        cin >> mrow >> mcol;
    }

    // Input matrix values
    cout << "Enter the values for the matrix: \n";
    int A[mrow][mcol];
    for (int i = 0; i < mrow; i++) {
        for (int j = 0; j < mcol; j++) {
            cin >> A[i][j];
        }
    }

    // Check if the matrix is symmetric
    bool isSymmetric = true;
    for (int i = 0; i < mrow; i++) {
        for (int j = 0; j < mcol; j++) {
            if (A[i][j] != A[j][i]) {
                isSymmetric = false;
                break;
            }
        }
    }

    // Output result
    if (isSymmetric) {
        cout << "The matrix is symmetrical." << endl;
    } else {
        cout << "The matrix is not symmetrical." << endl;
    }

    return 0;
}

