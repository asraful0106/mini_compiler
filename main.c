#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void clearWindow(){
    // Clear the console screen
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Linux/MacOS
    #endif
};

void mainMenu(){
    printf("███████████████████████████████████████████████████████████████████████████████████████████████████\n");
    printf("███████████████████╗███╗███╗░░██╗██╗███████████████████████████╗███████████████████████████╗██████╗\n");
    printf("███████████████╗█████║██║███████║██║░░███████████╗███████████████████████████████████████║█████╗░\n");
    printf("██▓███╔██████╔█╗██████╔██║██║░░╚═╝░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████▓██░░╝███╗\n");
    printf("████████████████████████████████████████▓▒­░⡷⠂𝙼𝙸𝙽𝙸 COMPILER⠐⢾░▒░░░░░░░░░████████████████████████████████\n");
    printf("██▓███╔██████╔█╗██████╔██║██║░░╚═╝░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████████▓██░░╝███╗\n");
    printf("███████████████╗█████║██║███████║██║░░███████████╗███████████████████████████████████████║█████╗░\n");
    printf("███████████████████╗███╗███╗░░██╗██╗███████████████████████████╗███████████████████████████╗██████╗\n");
    printf("███████████████████████████████████████████████████████████████████████████████████████████████████\n");

    printf("\n");
    printf("\n");
    printf("Please select an operation by entering the corresponding number:\n");
    printf("1. Lexical Analysis\n");
    printf("2. DFA/NFA Simulation\n");
    printf("3. Left Recursion Elimination\n");
    printf("4. Exit\n");
};
//------------------------ Lexical Analysis ------------
void lexicalAnalysisMenu(){
    printf("\n");
    printf("███████████▓▒­░⡷⠂Lexical Analysis⠐⢾░▒░░░░░░░░░█████\n");
    printf("\n");
    printf("Please select an operation by entering the corresponding number:\n");
    printf("1. Tokenize Input\n");
    printf("2. Find Operator, Identifier, Keywords\n");
    printf("3. Exit\n");
};

int isOperator(char *str) {
    const char *operators[] = {"+", "-", "*", "/", "%", "<", ">", "=", "==", "!=", "<=", ">=", "&&", "||"};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < numOperators; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}



int isKeyword(char *str) {
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };

    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


void lexicalOperations(){
    while(1){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
        if(choice == 1){
            //-------Tokenize------
            printf("Enter 0 to exit.\n");
            printf("Example: Input--> 213-15-4380, Token Against--> -");
            printf("\n\n");
            while(1){
                char input[1000];
                char tokenSimble[100];
                getchar();
                printf("Input: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                if(strcmp(input, "0") == 0) {
                    clearWindow();
                    lexicalAnalysisMenu();
                    break;
                };
                printf("Token Against: ");
                fgets(tokenSimble, sizeof(tokenSimble), stdin);
                tokenSimble[strcspn(tokenSimble, "\n")] = 0;
                char *token;
                token = strtok(input, tokenSimble);
                while(token != NULL){
                    printf("'%s'", token);
                    token = strtok(NULL, tokenSimble);
                }
                printf("\n");
                printf("Press enter to do another tokenization.");
            }
        }else if(choice == 2){
            //-------Lexical Analysis------
            printf("\n\n");
            printf("Enter 0 to exit.\n");
            while(1){
                char input[1000];
                getchar();
                printf("Enter text to get each token: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                if(strcmp(input, "0") == 0) {
                    clearWindow();
                    lexicalAnalysisMenu();
                    break;
                };
                char *token;
                token = strtok(input, " ");
                while (token != NULL) {
                    if (isKeyword(token)) {
                        printf("Keyword: %s\n", token);
                    } else if (isOperator(token)) {
                        printf("Operator: %s\n", token);
                    } else {
                        printf("Identifier: %s\n", token);
                    }
                    token = strtok(NULL, " ");
                }
                printf("\n");
                printf("Press enter to do another lexical analysis.");
            }
        }else if(choice == 3){
            clearWindow();
            mainMenu();
            break;
        }else{
            printf("Invalid Input!");
        }
    }
}

//------------- DFA/NFA ---------------
void impDfa() { //Implement DFA
    printf("Enter 0 anywhere to exit.\n");
    printf("Note: Empty input will be considered as not a condition.\n");
    printf("\n\n");

    while (1) {
        char startWith[100];
        char endsWith[100];
        char anyWhere[100];
        char input[1000];
        getchar();

        printf("Conditions--> \n\n");

        printf("Start with: ");
        fgets(startWith, sizeof(startWith), stdin);
        startWith[strcspn(startWith, "\n")] = 0;
        int startLength = strlen(startWith);
        if (strcmp(startWith, "0") == 0) {
            clearWindow();
            mainMenu();
            break;
        }

        printf("\nEnds with: ");
        fgets(endsWith, sizeof(endsWith), stdin);
        endsWith[strcspn(endsWith, "\n")] = 0;
        int endLength = strlen(endsWith);
        if (strcmp(endsWith, "0") == 0) {
            clearWindow();
            mainMenu();
            break;
        }

        printf("\nAnywhere: ");
        fgets(anyWhere, sizeof(anyWhere), stdin);
        anyWhere[strcspn(anyWhere, "\n")] = 0;
        int anyLength = strlen(anyWhere);
        if (strcmp(anyWhere, "0") == 0) {
            clearWindow();
            mainMenu();
            break;
        };

        if(startLength == 0 && endLength == 0 && anyLength == 0){
            printf("Not valid conditions!\n");
            continue;
        };

        printf("\n\nInput: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        int inputLength = strlen(input);
        if (strcmp(input, "0") == 0) {
            clearWindow();
            mainMenu();
            break;
        };

        bool validStart = true, validEnd = true, validAny = true;

        if (startLength != 0 && endLength != 0 && anyLength != 0) {
            // Check if input starts with startWith
            for (int i = 0; i < startLength; i++) {
                if (input[i] != startWith[i]) {
                    validStart = false;
                    break;
                };
            }

            // Check if input ends with endsWith
            for (int i = endLength - 1, j = 0; i >= 0; i--, j++) {
                if (input[inputLength - 1 - j] != endsWith[i]) {
                    validEnd = false;
                    break;
                };
            };

            // Check if input contains anyWhere anywhere
            if (validStart && validEnd) {
                char *pos = strstr(input, anyWhere);  // Check if 'anyWhere' is in the input
                if (pos == NULL) {
                    validAny = false;
                };
            };
        } else if (startLength == 0 && endLength != 0 && anyLength != 0) {
            // No start condition, check only endsWith and anywhere
            for (int i = endLength - 1, j = 0; i >= 0; i--, j++) {
                if (input[inputLength - 1 - j] != endsWith[i]) {
                    validEnd = false;
                    break;
                };
            };

            // Check if input contains anyWhere anywhere
            if (validEnd) {
                char *pos = strstr(input, anyWhere);
                if (pos == NULL) {
                    validAny = false;
                };
            };
        } else if (startLength == 0 && endLength == 0 && anyLength != 0) {
            // No start or end condition, check only anywhere
            char *pos = strstr(input, anyWhere);
            if (pos == NULL) {
                validAny = false;
            };
        }else if(startLength != 0 && endLength == 0 && anyLength == 0){
            // Check if input starts with startWith
            for (int i = 0; i < startLength; i++) {
                if (input[i] != startWith[i]) {
                    validStart = false;
                    break;
                };
            };
        }else if(startLength == 0 && endLength != 0 && anyLength == 0){
            // Check if input ends with endsWith
            for (int i = endLength - 1, j = 0; i >= 0; i--, j++) {
                if (input[inputLength - 1 - j] != endsWith[i]) {
                    validEnd = false;
                    break;
                };
            };

        }
        // Final output based on validity of all conditions
        if (validStart && validEnd && validAny) {
            printf("Accepted.\n");
        } else {
            printf("Rejected.\n");
        };
        printf("\n");
        printf("Press enter to do another DFA/NFA.");
    }
}

//------------- Left Recursion Elimination ---------------
bool isLeftRecursion(char input[]) {
    char newInput[1000];
    strcpy(newInput, input + 3);

    char *token;
    token = strtok(newInput, "|");

    while (token != NULL) {
        if (input[0] == token[0]) {
            return true;
        }
        token = strtok(NULL, "|");
    }
    return false;
}

void impLeftRecursion(){
    printf("Enter 0 any where to exit.\n\n");
    while(1){
        printf("Enter total CFG: ");
        int arrSize;
        scanf("%d", &arrSize);
        if (arrSize == 0) {
            clearWindow();
            mainMenu();
            break;
        };
        getchar();

        char inputArr[arrSize][1000];

        printf("Enter CFG:\n");
        bool isExit = false;
        for (int i = 0; i < arrSize; i++) {
            fgets(inputArr[i], sizeof(inputArr[i]), stdin);
            if (strcmp(inputArr[i], "0\n") == 0) {
                clearWindow();
                mainMenu();
                isExit = true;
                break;
            }
            inputArr[i][strcspn(inputArr[i], "\n")] = '\0';
        }

        if(isExit) break;

        bool isLeft = false;
        for (int i = 0; i < arrSize; i++) {
            if (isLeftRecursion(inputArr[i])) {
                isLeft = true;
                break;
            }
        }

        if (isLeft) {
            printf("Left Recursion: true\n");
        } else {
            printf("Left Recursion: false\n");
        }
        printf("\n");
        printf("Press enter to do another Left Recursion Elimination.");
    }
}


int main() {
    mainMenu();
    while(1){
        int choice;
        printf("\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // ------- main menu case------
        switch (choice){
        case 1:
            clearWindow();
            lexicalAnalysisMenu();
            lexicalOperations();
            break;
        case 2:
            clearWindow();
            impDfa();
            break;
        case 3:
            clearWindow();
            impLeftRecursion();
            break;
        case 4:
            printf("\n");
            printf("███████████▓▒­░⡷⠂Execution done⠐⢾░▒░░░░░░░░░█████\n");
            return 0;
        default:
            clearWindow();
            mainMenu();
            printf("\n\nInvalid Input!");
        }
    }
    return 0;
}
