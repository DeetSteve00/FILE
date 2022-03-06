#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Set the randomizer seed

FILE * filePointer;

void addLine(char file[]) {
    filePointer = fopen(file, "a");
    char input[150];
    printf("Enter new line: " );
    gets(input);
    fprintf(filePointer, input);
}

void readFile(char file[]) {
    printf("\n");
    filePointer = fopen(file, "r");
    char fileContent[150];
	while(!feof(filePointer)) {
		fgets(fileContent, 150, filePointer);
		printf("%s", fileContent);
	}
	printf("\n");
    fclose(filePointer);
}

void writeFile(char file[]) {
    filePointer = fopen(file, "w");
    char input[150];
    printf("Enter new line (Will rewrite entire file): " );
    gets(input);
    fprintf(filePointer, input);
}

void fillFile(char file[]) {
    filePointer = fopen(file, "w");
    fprintf(filePointer, "0"); //Replace all the file's content with "0"
    fclose(filePointer);
    filePointer = fopen(file, "a");
    int a, b;
    unsigned char garbage[150];
    for(a = 0; a < 100; a++) {
        for(b = 0; b < 149; b++) {
            garbage[b] = rand() % 255; //Random charachter to form string
        }
        garbage[150] = '\0'; //Insert that string to the file
        fprintf(filePointer, garbage);
    }
}

int main(int argc, char* argv[]) {
    srand(time(0)); //Randomizer for -fill garbage
    if(argc < 2) {
        printf("No arguments entered: Use -help to get a list of commands\n");
        return 1;
    }
    if(strcmp(argv[1], "-read") == 0) {
        if(argc < 3) {
                printf("Not enough arguments!\n");
                return 1;
        }
        readFile(argv[2]);
        return 0;
    } else if(strcmp(argv[1], "-write") == 0) {
        if(argc < 3) {
                printf("Not enough arguments!\n");
                return 1;
        }
        writeFile(argv[2]);
        return 0;
    } else if(strcmp(argv[1], "-add") == 0) {
        if(argc < 3) {
                printf("Not enough arguments!\n");
                return 1;
        }
        addLine(argv[2]);
    } else if(strcmp(argv[1], "-fill") == 0){
        if(argc < 3) {
                printf("Not enough arguments!\n");
                return 1;
        }
        fillFile(argv[2]);
    } else if(strcmp(argv[1], "-help") == 0) { //Display list of commands
        printf("\nHELP:\n   -read: Display the text inside a file\n   -write: Write 1 line of text on a file\n   -add: Add new text line to file\n   -fill: Overwrite and fill an entire file with garbage\n   -help: Get a list of commands\n");
        return 0;
    } else { //Entered nonexistant command
        printf("Unknown command\n");
        return 1;
    }
    return 0;
}
