#include <stdio.h>
#include <string.h>

int countWords(char text[], int length) {
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (text[i] != ' ') {
            count++;
            while (i < length && text[i] != ' ') {
                i++;
            }
        }
    }
    
    return count;
}

int countPunctuationMarks(char text[], int length) {
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' 
        ||text[i] == ';' || text[i] == ':' || text[i] == ',' 
        || text[i] == '\'' || text[i] == '\"' || text[i] == '(' || text[i] == ')'
        || text[i] == '[' || text[i] == ']' || text[i] == '-') {
            count++;
        }
    }
    
    return count;
}

void sortText(char text[], int length, int wordsLength) {
    char sortedSentence[length];
    char textArr[wordsLength][length];
    
    // push all words in textArr:
    int j = 0;
    while (j < wordsLength) {
        for (int i = 0; i < length; i++) {
            while (i < length && text[i] != ' ') {
                textArr[j] = textArr[j] + text[i];
            }
            j++;
        }
    }
    
    // sort the words in textArr:
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
        // Select the minimum element
        if ((int) textArr[min][0] > (int) textArr[j][0]) 
            min = j;
        }

        // put min at the correct position
        char x[strlen(textArr[min])] = textArr[min];
        textArr[min] = textArr[i];
        textArr[i] = x;
    }
    
    // push all words from textArr to sortedSentence:
    for (int i = 0; i < length; i++) {
        if (i != length-1) {
            sortedSentence[i] = textArr[i] + " ";
        } else {
            sortedSentence[i] = textArr[i];
        }
    }

}

int main() {
    char text[1000];
    printf("Enter text: ");
    scanf("%[^\n]s", text);
    
    // Kulev task - find the number of words
    int wordsLength = countWords(text, strlen(text));
    printf("\nThere are %d words", wordsLength);

    // Medium - function that reads a sentence from the user and counts the number of punctuation marks (e.g., periods, commas, question marks) in the sentence
    printf("\nThere are %d punctuation marks\n", countPunctuationMarks(text, strlen(text)));

    // Medium - function that takes a sentence as input and returns the sentence with words sorted alphabetically
    sortText(text, strlen(text));
    printf("\nSorted text alphabetically: %s", text, wordsLength);

    return 0;
}