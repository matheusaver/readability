#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Count the number of words in the text
int count_words(string str)
{
    int words = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (str[i] == ' ')
        {
            words = words + 1;
        }
    }
    return words + 1;
}

// Count the number of letters in the text
int count_letters(string str)
{
    int letters = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (isalpha(str[i]))
        {
            letters = letters + 1;
        }
    }
    return letters;
}

// Count the number of sentences in the text
int count_sentences(string str)
{
    int sentences = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            sentences = sentences + 1;
        }
    }
    return sentences;
}

// Compute the Coleman-Liau index
int compute_index(float words, float letters, float sentences)
{
    float L = (100.0 * (letters / words));
    float S = (100.0 * (sentences / words));
    float index_float = (0.0588 * L) - (0.296 * S) - 15.8;
    double teste = round(index_float);
    int index_int = teste;
    return index_int;
}

int main(void)
{
    printf("READABILITY LEVEL\n");
    string text = get_string("Enter the text: ");
    float words = count_words(text);
    float letters = count_letters(text);
    float sentences = count_sentences(text);
    int index = compute_index(words, letters, sentences);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
