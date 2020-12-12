#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void anagram(char* w1, char* w2)
{
    /* first, we know that if two words are not the same size, we don't even need to check their letters to know that they are not anagrams */
    if(strlen(w1) != strlen(w2))
    {
        printf("Words cannot be anagrams because they have different sizes.");
    }
    else
    {
        int size, count = 0;
        size = strlen(w1);
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (w1[i] == w2[j])
                {
                    /* do this so that if there are two letters repeated in a word, the algorithm does not compare it twice */
                    w2[j] = '0';
                    /* for each equal letter, the counter adds 1 unit */
                    count++;
                }

            }
            /* if the count equal to i, means that the count don't was not added, so the letter in first word in the i position don't exists in the second word*/
            if(count == i) 
            {
                printf("Words aren't anagrams!");
                break;
            }  
        } 
        /* finally, if all the letters in the two words are the same, the counter will be equal to the number of letters */
        if (count == size - 1)
        {
            printf("Words are anagrams!");
        }
    }
}

int main()
{
    char word_1[30], word_2[30];
    printf("Let's find out whether two words are anagrams or not. \n");
    printf("Type the first word: \n");
    fgets(word_1, 30, stdin);
    printf("Type the second word: \n");
    fgets(word_2, 30, stdin);
    anagram(word_1, word_2);

}