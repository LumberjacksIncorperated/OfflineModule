//-----------------------------------------------------------------------------------------
//*
//*  DESCRIPTION
//*  -----------
//*  Haystack Offline Module Application Source Code
//*
//*  AUTHOR
//*  ------
//*  Lumberjacks Incorperated
//*
//*  TIME
//*  ----
//*  2018
//*
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
//  INCLUDES
//-----------------------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//-----------------------------------------------------------------------------------------
//  PRIVATE FUNCTION FORWARD DECLARATIONS
//-------------------------------------------------------------------------------------
void runOptionsInterface(void);
void runEncryptInterface(void);
void runDecryptInterface(void);
char* findRecipientAddress(char* name);
void clearInputBuffer(void);
void formatMessage(char* message, int count);
void printUserOptions(void);
void setupClient(void);

//----------------------------------------------------------------------------------------
//  MAIN
//----------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
    runOptionsInterface();
    return EXIT_SUCCESS;
}

//-----------------------------------------------------------------------------------------
//  INTERNAL FUNCTIONS
//-----------------------------------------------------------------------------------------
void runOptionsInterface(void)
{
    int userOption = -1;
    
    while(userOption != 3)
    {
        printUserOptions();
        
        scanf("%d", &userOption);
        if(userOption == 1)
        {
            runEncryptInterface();
        }
        else if(userOption == 2)
        {
            runDecryptInterface();
        }
        else if(userOption == 0)
        {
            setupClient();
        }
        else
        {
            break;
        }
    }
}

void printUserOptions(void)
{
    printf("\n0 - Setup Client (Don't do this more than once)\n1 - Send Mail\n2 - Check Mail\n3 - Quit\n");
}

void setupClient(void)
{
    system("./SetupClient.sh");
}

void runEncryptInterface(void)
{
    char recipient[100];
    char message[100];
    
    printf("\nWho is the recipient?\n");
    scanf("%s", recipient);
    clearInputBuffer();
    
    printf("What is the message?\n");
    char *line = NULL;
    size_t size;
    if (getline(&line, &size, stdin) == -1) {
        printf("No line\n");
    }
    strncpy(message, line, strlen(line));
    formatMessage(message, strlen(line));
    
    // Write message to a file
    FILE * messageFile = fopen("plain.txt", "w");
    if(messageFile == NULL) {
        printf("PROBLEM!\n");
        printf("Error %d \n", errno);
    }
    fprintf(messageFile, "%s", message);
    fclose(messageFile);
    
    // Create syscall command
    char *command = malloc(400);
    strcpy(command, "cat plain.txt | openssl rsautl -encrypt -pubin -inkey ");
    strcat(command, recipient);
    strcat(command, ".pem > encodedMessage");
    strcat(command, "\0");
    system(command);
    
    printf("... Done\n\n");
}

void clearInputBuffer(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void formatMessage(char* message, int count)
{
    int counter = count - 1;
    printf("count = %d, and %c\n", count, (char) (212));
    while(counter < 100)
    {
        message[counter++] = ' ';
    }
    message[counter-1] = 0;
}

void runDecryptInterface(void)
{
    printf("Attempting to decrypt all messages");
    system("./DecryptFiles.sh");
    printf("... Done\n\n");
}
