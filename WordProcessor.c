#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int positions[MAX_WORDS];
    int count;
} WordIndex;

void addWordToIndex(const char *word, int index, WordIndex wordIndices[], int *wordCount) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordIndices[i].word, word) == 0) {
            wordIndices[i].positions[wordIndices[i].count++] = index;
            return;
        }
    }
    strcpy(wordIndices[*wordCount].word, word);
    wordIndices[*wordCount].positions[0] = index;
    wordIndices[*wordCount].count = 1;
    (*wordCount)++;
}

void processWord(char *word, int *wordPos, int *index, WordIndex wordIndices[], int *wordCount) {
    if (*wordPos > 0) {
        word[*wordPos] = '\0';
        addWordToIndex(word, *index, wordIndices, wordCount);
        (*index)++;
        *wordPos = 0;
    }
}

void parseParagraph(const char *paragraph, WordIndex wordIndices[], int *wordCount) {
    char word[MAX_WORD_LENGTH];
    int wordPos = 0;
    int index = 0;
    *wordCount = 0;

    for (int i = 0; paragraph[i] != '\0'; i++) {
        if (isalnum(paragraph[i])) {
            word[wordPos++] = tolower(paragraph[i]);
        } else {
            processWord(word, &wordPos, &index, wordIndices, wordCount);
        }
    }
    processWord(word, &wordPos, &index, wordIndices, wordCount);
}

void listWordPositions(const char *word, WordIndex wordIndices[], int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordIndices[i].word, word) == 0) {
            printf("Word: %s\nPositions: ", wordIndices[i].word);
            for (int j = 0; j < wordIndices[i].count; j++) {
                printf("%d ", wordIndices[i].positions[j]);
            }
            printf("\nTotal occurrences: %d\n", wordIndices[i].count);
            return;
        }
    }
    printf("Word '%s' not found in the text.\n", word);
}

int main() {
    char paragraph[1000];
    char wordToFind[MAX_WORD_LENGTH];
    WordIndex wordIndices[MAX_WORDS];
    int wordCount;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);
    paragraph[strcspn(paragraph, "\n")] = '\0';

    parseParagraph(paragraph, wordIndices, &wordCount);

    printf("Enter a word to find: ");
    scanf("%s", wordToFind);

    listWordPositions(wordToFind, wordIndices, wordCount);

    return 0;
}
