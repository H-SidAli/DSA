//
//HADJI SIDALI
//1CP G05 
//HomeWork ALSDD
//Libraries
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//Environment
//BUFFER is the maximum of characters in the line;
#define BUFFER 1000
//Words is the structure we are asked to do;
typedef struct {
    char word[45];
    // word[45] because the longest word is in 45 characters;
    int line;
    int position;
} Words;

//Modules
//FillText: Asks the user to enter the number of lines in his paragraph then enters each line individualy;
void FillText(int *n, char text[][BUFFER]){
    printf("Enter the number of lines: ");
    scanf("%d", n);
    getchar(); // Consume the newline character;

    for (int i = 0; i < *n; i++)
    {
        printf("Enter line %d: ", i+1);
        // instead of using scanf or getc, just to set a maximum of characters in each line;
        fgets(text[i], BUFFER, stdin);
    }
}

//GetWords: Get the words from the lines;
void GetWords(int n, char text[][BUFFER], Words Word[], int *cpt){
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        char str[BUFFER] = "";
        str[0] = '\0';
        for (int j = 0; j< strlen(text[i]); j++){
            //If the character is different from 'space or more' and 'new line' and the NULL character and must be an alphabet;
            if (text[i][j] != ' ' && text[i][j] != '\n' && text[i][j] != '\0' && isalpha(text[i][j])) {
                strncat(str,&text[i][j], 1);
            }
            else{
                // if the string is not empty we stock it
                if (strlen(str) > 0){
                    strcpy(Word[k].word, str);
                    // the '+1' is because the loops and the counter K are initialized by 0;
                    Word[k].line = i+1;
                    Word[k].position = k+1;
                    k++;
                    str[0] = '\0';
                }
            }
        }
    }
    *cpt = k;
}

void DisplayWords(int cpt, Words Word[]){
    for (int i = 0; i < cpt; i++){
        printf("Word: %s\n", Word[i].word);
        printf("Line: %d\n", Word[i].line);
        printf("Position: %d\n", Word[i].position);
        printf("----------------------------------\n");
    }
}
//a structure to store only the unique words
typedef struct {
    char word[50];
    int freq;
} WordFreq;

void FreqWords(Words Word[], int cpt){
    WordFreq wordFreqs[cpt];
    //counter for the unique words
    int uniqueWords = 0;

    for (int i = 0; i < cpt; i++) {
        //boolean
        int found = 0;
        for (int j = 0; j < uniqueWords; j++) {
            if(strcmp(Word[i].word, wordFreqs[j].word) == 0){
                wordFreqs[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordFreqs[uniqueWords].word, Word[i].word);
            wordFreqs[uniqueWords].freq = 1;
            uniqueWords++;
        }
    }
    // wordFreqs contains each unique word and its frequency
    // uniqueWords contains the number of unique words

    // Sort the frequencies in decreasing order 
    // Bubble sort of wordFreqs
    for (int i = 0; i < uniqueWords - 1; i++)
    {
        for (int j = i + 1; j < uniqueWords; j++)
        {
            //sorting based on the frequencies
            if (wordFreqs[i].freq < wordFreqs[j].freq)
            {
                WordFreq temp = wordFreqs[i];
                wordFreqs[i] = wordFreqs[j];
                wordFreqs[j] = temp;
            }
        }
    }

    // Display the first 5 most frequent words that are different from each other
    printf("The first 5 most frequent words that are different from each other:\n");
    printf("------------------------------------------\n");
    int count = 0;
    for (int i = 0; i < uniqueWords && count < 5; i++)
    {
        // i==0 because we know that the array is sorted thus the most frequent word is in the index 0,
        // and the second condition is to avoid displaying the same word (repeating) 
        // the i-1 instead of i+1 because the second condition starts from i=1 
        if (i == 0 || strcmp(wordFreqs[i].word, wordFreqs[i-1].word) != 0)
        {
            printf("Word: %s\n", wordFreqs[i].word);
            printf("Frequency: %d\n", wordFreqs[i].freq);
            printf("Coordinates:\n");
            // Searching for the coordinates of the same word
            for (int j = 0; j < cpt; j++)
            {
                if (strcmp(wordFreqs[i].word, Word[j].word) == 0)
                {
                    printf("Line: %d, Position: %d\n", Word[j].line, Word[j].position);
                }
            }
            printf("------------------------------------------\n");
            count++;
        }
    }
}

//Main
int main(){

    int n = 100; // it should be initialized with a maximum number of lines to avoid C bugs;
    char text[n][BUFFER];
    int cpt, choice;
    Words Word[n];
    bool e = false;
    bool q1, q2, q3, q4;
    do{
        printf("\n---------------------------------------MENU---------------------------------------\n");
        printf("1- Filling the text\n");
        printf("2- Getting the words\n");
        printf("3- Displaying the words\n");
        printf("4- Displaying the most 5 frequent words with their coords\n");
        printf("5- Exit\n");
        printf("----------------------------------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                q1 = true;
                printf("----------------------------------Filling the text--------------------------------\n");
                FillText(&n, text);
                break;
            case 2:
                if(q1 == false){
                    printf("Please process option 1 first!");
                }
                else{
                    q2 = true;
                    printf("---------------------------------Getting the words--------------------------------\n");
                    GetWords(n, text, Word, &cpt);
                    printf("---------------------------------------DONE---------------------------------------");
                }
                break;
            case 3:
                if (q1 == false || q2 == false){
                    printf("Please process option 1 and 2 first!");
                }
                else{
                    printf("------------------------------Displaying the words-------------------------------\n");
                    DisplayWords(cpt, Word);
                }
                break;
            case 4:
                if (q1 == false || q2 == false){
                    printf("Please process option 1 and 2 first!");
                }
                else{
                    printf("---------------Displaying the most 5 frequent words with their coords-------------\n");
                    FreqWords(Word, cpt);
                }
                break;
            case 5:
                printf("-------------------------------END OF THE PROGRAM-------------------------------------\n");
                e = true;
                break;
            default:
                printf("Error of choice ! Please enter a valid choice !");
        }
    }while(e == false);
}