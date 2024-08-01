#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[MAX_PARAGRAPH_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS] = {0};
    int wordCount = 0;
    printf("Enter a paragraph: ");
    fgets(paragraph, MAX_PARAGRAPH_LENGTH, stdin);

    toLowerCase(paragraph);

    
    char* token = strtok(paragraph, " ,.-\n");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], token);
            count[wordCount] = 1;
            wordCount++;
        }

        token = strtok(NULL, " ,.-\n");
    }

    printf("\nWord frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}
