/********************************
 * This program folds / wraps long lines.
 *
 * Inputs:
 *
 * (1) columnIndex: The "columnIndex" takes values from 1 up to any integer and specifies the
 * column index at which a long line will be folded.
 *
 * The line should be folded at the first non-blank character exactly before the "columnIndex" column.
 * If the line does not have blank characters before the "columnIndex" column, then it will be folded
 * at the "columnIndex" character.
 *
 * Note that some lines might be very long. Which means that they might be folded / wrapped to more than
 * two lines. For example a line with 300 characters and a "columnIndex" of 120, might be folded to
 * three lines.
 *
 */
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define NUMBER_OF_CHARS_PER_LINE 80

void wrapCurrentLine(char line[], int numberOfCharsPerLine);

int main(void) {
    int c = 0;
    int currentColumnIndex = -1;
    char currentLine[MAX_LINE_SIZE];

	while((c = getchar()) != EOF) {
		// we need to add the character to the existing/current line
		currentColumnIndex++;
		currentLine[currentColumnIndex] = c;
		if (c == '\n') {
			// the last character read is a newline,
			// We wrap the current line, before going to the next char
			currentLine[currentColumnIndex] = '\0';
			wrapCurrentLine(currentLine, NUMBER_OF_CHARS_PER_LINE);
			memset(currentLine, 0, MAX_LINE_SIZE);
			currentColumnIndex = -1;
		}
	}

	printf("Bye!\n");
	return 0;
}

void wrapCurrentLine(char line[], int numberOfCharsPerLine) {
	int lineLength = strlen(line);
	if (lineLength <= numberOfCharsPerLine) {
	    printf("%s\n", line);
	    return;
	}

    int currentChar = numberOfCharsPerLine - 1;
    while(currentChar != ' ' && currentChar >= 0) {
        currentChar--;
    }
    // Here, we are before the beginning of string if everything is blank.
    // Or we are at the first non-blank character.
    if (currentChar == -1) {
        // all characters were different from blank. Then in that case,
        // we wrap at the numberOfCharsPerLine
        currentChar = numberOfCharsPerLine - 1;
    }
    else {
        // points to the first blank character
    }

    char outputLine[MAX_LINE_SIZE];
    memset(outputLine, 0, MAX_LINE_SIZE);
    memcpy(outputLine, line, currentChar + 1);
    char newLine[MAX_LINE_SIZE];
    memset(newLine, 0, MAX_LINE_SIZE);
    memcpy(newLine, line, lineLength - currentChar - 1);
    printf("%s\n", outputLine);
    wrapCurrentLine(newLine, NUMBER_OF_CHARS_PER_LINE);
}
