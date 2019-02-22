#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct instruction_s {
    int step;
    int index;
};
//function to getting a word from line
//@param s is the line given to function
//@param n is the index of word in the line
char* get_word(char* s, int n)
{

    char* word;
    int counter = 1;
    int i;
    char* s2;
    s2 = (char*)malloc(200 * sizeof(char));
    for (i = 0; i < 200; i++) {
        s2[i] = '\0';
    }
    strcpy(s2, s);
    word = strtok(s2, " ");
    while (word != NULL) {
        if (counter == n) {

            int leng;
            leng = strlen(word);
            for(i=0;i<leng;i++)
            {
			
            if (isalpha(word[i]) == 0 && isdigit(word[i]) == 0 ) {
                word[i] = '\0';
            }
}
            return word;
        }
        counter++;
        word = strtok(NULL, " ");
    }
    free(s2);
    return NULL;
}
//function which take words in a sentence
//@param lines lines of book
//@param instructions array of instrucrions 
//@param instructions_n number of instructions
//@param sentence is empty string to store words and make sentence
void get_sentence(char** lines, struct instruction_s* instructions, int instructions_n, char* sentence)

{
    int i, line2;
    line2 = instructions[0].step;
    for (i = 0; i < 200; i++) {
        sentence[i] = 0;
    }
    for (i = 1; i < instructions_n; i++) {

        strcat(sentence, get_word(lines[line2 - 1], instructions[i-1].index));
        strcat(sentence, " ");

        line2 += instructions[i].step;
    }

    printf("%s\n", sentence);
}

int main(int argc, char* argv[])
{
    FILE* d = fopen(argv[1], "r");
    FILE* f = fopen(argv[2], "r");
    
    if(f==NULL)
    {
    	printf("file cannot be opened");
    	return EXIT_FAILURE;
	}
    else if(d==NULL)
    {
    	printf("file cannot be opened");
    	return EXIT_FAILURE;
	}
    else{
	
    const int size = 10000;
    const int length = 200;
    char** lines = (char**)malloc(size * sizeof(char*));
    char* line = (char*)malloc(length * sizeof(char));

    int i, count;
    struct instruction_s instructions[200];
    for (i = 0; i < size; i++) {
        lines[i] = (char*)malloc(length * sizeof(char));
    }

    count = 0;
    i = 0;
    int k = 0;
    int len = 0;
    while (fgets(line, length, d)) {
        len = strlen(line);

        int leng = strlen(line);
        char* line2 = (char*)malloc(200 * sizeof(char));
        strcpy(line2, line);
        i = 0;
        k = 0;
        while (i < leng) {
            if ((isalpha(line2[i]) != 0 || isspace(line2[i]) != 0 || isdigit(line2[i]) != 0)) {
                line[k] = line2[i];
                line[k] = tolower(line[k]);
                k++;
            }
            i++;
        }
        line[k] = '\0';

        free(line2);

        for (i = 0; i < len; i++) {

            lines[count][i] = line[i];
        }
        
        count++;
    }
    
    int step, index,j=1;
    i = 0;
    while (fscanf(f, "%d %d", &step, &index) != EOF) {
        instructions[i].step = step;
        instructions[i].index = index;
        i++;
        j++;
    }
    char* sentence = (char*)malloc(length * sizeof(char));

    get_sentence(lines, instructions, j, sentence);

    for (i = 0; i < size; i++) {
        free(lines[i]);
    }

    free(sentence);
    free(lines);
    free(line);
    fclose(d);
    fclose(f);

    return 0;
}
}
