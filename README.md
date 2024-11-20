# WordProcessor.c Documentation

## Overview

`WordProcessor.c` is a C program that processes a paragraph of text to find and list the positions of words within the text. The program reads a paragraph from the user, parses it to identify individual words, and then allows the user to search for a word to see its occurrences and positions within the paragraph.

## Logic Explanation

The program consists of several key functions:

1. **`addWordToIndex`**: Adds a word to the index, recording its position.
2. **`processWord`**: Processes a word by adding it to the index if it is not empty.
3. **`parseParagraph`**: Parses the paragraph to extract words and their positions.
4. **`listWordPositions`**: Lists the positions of a specified word in the paragraph.
5. **`main`**: The main function that drives the program.

### Detailed Function Descriptions

1. **`addWordToIndex`**:
    - Checks if the word already exists in the index.
    - If it exists, it adds the new position to the existing word's positions.
    - If it does not exist, it adds the word to the index and records its position.

2. **`processWord`**:
    - Finalizes the current word by adding it to the index.
    - Resets the word position for the next word.

3. **`parseParagraph`**:
    - Iterates through each character of the paragraph.
    - Builds words character by character.
    - Calls `processWord` when a non-alphanumeric character is encountered.
    - Ensures the last word is processed after the loop.

4. **`listWordPositions`**:
    - Searches for the specified word in the index.
    - Prints the positions and total occurrences if the word is found.
    - Prints a message if the word is not found.

5. **`main`**:
    - Reads a paragraph from the user.
    - Calls `parseParagraph` to process the paragraph.
    - Reads a word to find from the user.
    - Calls `listWordPositions` to display the word's positions.

## Procedure

1. **Input Paragraph**:
    - The user is prompted to enter a paragraph.
    - The paragraph is read using `fgets`.

2. **Parse Paragraph**:
    - The paragraph is parsed to extract words and their positions.
    - Words are converted to lowercase and stored in the `wordIndices` array.

3. **Input Word to Find**:
    - The user is prompted to enter a word to find.
    - The word is read using `scanf`.

4. **List Word Positions**:
    - The program searches for the word in the `wordIndices` array.
    - If found, it prints the positions and total occurrences.
    - If not found, it prints a message indicating the word was not found.

## Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Input Paragraph]
    B --> C[Parse Paragraph]
    C --> D[Input Word to Find]
    D --> E[List Word Positions]
    E --> F[End]

    subgraph Parse Paragraph
        C1[Initialize Variables]
        C2[Iterate through Paragraph]
        C3[Build Word]
        C4[Process Word]
        C5[End of Paragraph]
        C1 --> C2
        C2 --> C3
        C3 --> C4
        C4 --> C2
        C2 --> C5
    end

    subgraph List Word Positions
        E1[Search for Word]
        E2[Word Found?]
        E3[Print Positions and Count]
        E4[Print Not Found Message]
        E1 --> E2
        E2 -->|Yes| E3
        E2 -->|No| E4
    end