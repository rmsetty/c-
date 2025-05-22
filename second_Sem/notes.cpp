//Palindrone
while(left < right)
{
    if (str[left] != str[right])
    {
        isPalindrome = false;
    }

    right--;
    left++;
}