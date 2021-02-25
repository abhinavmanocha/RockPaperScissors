/*H**********************************************************************
* FILENAME :        lab1.c             
*
* DESCRIPTION :
*       File compression and decompression routines.
*
* NOTES :
*       To mimic a rock paper sissors game but with hammer, sword, armor. A hammer can defeat
*       armor, but not a sword. A sword can defeat a hammer, but cannot defeat armor. Lastly, armor can
*       defeat a sword, but not a hammer.
*
*       
* AUTHOR :    Abhinav Manocha       Due DATE :    2021-02-05
*
* EXTERNAL REFRENCES:  https://www.includehelp.com/c-programs/generate-random-numbers-within-a-range.aspx
*
**/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>


/*
Function: toUpper
------------------
Computes the uppercase equivalent to each undercase letter using the 'toupper' function
    imported by <ctype.h>

ch : Takes the char input as an ascii value

returns: The Uppercase equivalent so the program accepts any input
*/

int  toUpper(int ch){
   return (ch, toupper(ch));
}


/*
Function: GetUserSelection
------------------
Gets the user selction based off the charcter inputted
    
returns: The Uppercase equivalent so the letter inputted by the user
*/
char GetUserSelection(){

    char letter = ' ';

    printf("Enter a letter: ");
    scanf("%c", &letter);
    letter = toUpper(letter); /* Converts the char into UPPERCASE */
    getchar(); 
    printf("The letter you entered was: %c ", letter);

    return letter;
}

/*
Function: GetComputerSelection
------------------
Gets the Computer selction based off a random number generator that is between a certain range.
    
returns: The computers choice in the form of a character. 
*/

char GetComputerSelection(){
   int lower = 0, upper = 2, count = 1;
   srand(time(0));
   int i = 0;
   for (i; i < count; i++)
   {
       char computerChoice = ' ';
       int num = (rand()%(upper-lower+1))+lower; /* Help from: https://www.includehelp.com/c-programs/generate-random-numbers-within-a-range.aspx */
       /* printf("%d",num);  0 denotes hammer, 1 denotes sword, and 2 denotes armor. */
       if (num > 1)
        {
            computerChoice = 'A';
            printf("\nComputer picked the letter: %c", computerChoice);
            return computerChoice;
           
        }else if (num == 1)
        {
            computerChoice = 'S';
            printf("\nComputer picked the letter: %c", computerChoice);
            return computerChoice;
            
        }else if (num < 1)
        {
            computerChoice = 'H';
            printf("\nComputer picked the letter: %c", computerChoice);
            return computerChoice;
            
        }else
        {
            printf("Error!");
        }        
   }
}

/*
Function: GetWinner
------------------
This function will compute a win, loss or tie, based off the comparision between user_choice and computer_choice
returns: A 0 indicating a tie, 1 indicating a win, -1 indicating a loss, or 2 if the user wishes to exit the program  
*/

int GetWinner(char user_choice, char computer_choice){

    if (user_choice == computer_choice)
    {
        return 0;
    }
    else if (user_choice == 'S' && computer_choice == 'H')
    {
        return 1;
    }
    else if (computer_choice == 'S' && user_choice == 'H')
    {
        return -1;
    }
    else if (user_choice == 'H' && computer_choice == 'A')
    {
        return 1;
    }
    else if (computer_choice == 'H' && user_choice == 'A')
    {
        return -1;
    }

    else if (user_choice == 'A' && computer_choice == 'S')
    {
        return 1;
    }
    else if (computer_choice == 'A' && user_choice == 'S')
    {
        return -1;
    }else if (user_choice == 'Q')
    {
        return 2;
    }
    
}

/* Main program*/

int main(){

    printf("\n\nHello and welcome to hammer, sword, armor. In this game you will chose the following:\n");
    printf(" H = Hammer, S = Sword, A = Armor\n\n");
    char playerChar, compChar;
    int winner;
    int i = 0;
    for (i; i < 1000; i++)
    {
        playerChar = GetUserSelection();
        compChar = GetComputerSelection();
        winner = GetWinner(playerChar,compChar);

        if  (winner == 2){      /*  A very Janky solution to exit when the user enters Q  */
            printf("\nThank you, Good bye!!\n\n");
            break;
        }        
        else if (winner == 1)
        {
            printf("\nUser won!\n\n");

        }else if (winner == 0)
        {
            printf("\nTie!\n\n");
        }else if (winner == -1)
        {
            printf("\nComputer won!\n\n");
        }else
        {
            printf("\nThe value you entered was incorrect: %c \n\n", winner);
        }

    }
       
}

