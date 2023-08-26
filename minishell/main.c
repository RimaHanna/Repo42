#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main() {
    char *input;
    
    // Read input using readline
    input = readline("Enter a command: ");
    
    // Check for EOF or empty input
    if (input == NULL || input[0] == '\0') {
        printf("No input provided.\n");
    } else {
        printf("You entered: %s\n", input);
        
        // Add input to the history
        add_history(input);
    }

    // Free the input buffer
    free(input);

    return 0;
}
