#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int debugSolutions[3188][4]; // An array of integers, named debugSolutions, with 3188 rows and 4 columns. It is used to store solutions for the mathematical computation.

// Define a constant 2D array of 10 rows and 4 columns that holds easy puzzle numbers
const int easyPuzzles[10][4] = {
    {3, 9, 4, 1}, {8, 5, 8, 1}, 
    {6, 1, 5, 1}, {2, 8, 7, 8}, 
    {5, 2, 9, 2}, {2, 6, 8, 4}, 
    {5, 5, 4, 3}, {6, 6, 2, 6}, 
    {8, 4, 2, 6}, {6, 2, 8, 1}
    };

/*
 * compute function takes in two numbers (a, b) and an operator (operator)
 * and performs the computation a operator b.
 * The function returns the result of the operation.
 * The function also prints the calculation and result to the console.
 */
double compute(double a, double b, char operator)
{
    switch (operator)
    {
    case '*':
        printf("%.0lf * %.0lf = %.0lf.\n", a, b, a * b);
        return (double)(a * b);
    case '/':
        printf("%.0lf / %.0lf = %.0lf.\n", a, b, (double)((int)a / (int)b));
        return (double)((int)a / (int)b);
    case '-':
        printf("%.0lf - %.0lf = %.0lf.\n", a, b, a - b);
        return (double)(a - b);
    case '+':
        printf("%.0lf + %.0lf = %.0lf.\n", a, b, a + b);
        return (double)(a + b);
    }
}

/*
 * Function: debugMode
 * -------------------
 * This function takes an array of solutions and a boolean flag indicating whether
 * the debug mode is enabled or not. If the debug mode is enabled, the function
 * prints each solution to the console and returns the array of solutions.
 * If the debug mode is not enabled, the function will not print out all the solutions.
 *
 * pArray: an array of solutions, where each solution is represented as an array of four numbers
 * debugBool: a boolean flag indicating whether the debug mode is enabled or not
 *
 * returns: the array of solutions
 */
int (*debugMode(int pArray[3188][4], bool debugBool))[4]
{
    char debugOperators[4] = {'+', '-', '*', '/'};
    int count = 1;
    double result1, result2, result3;
    for (double i = 1; i < 10; i++)
    {
        for (double j = 1; j < 10; j++)
        {
            for (double k = 1; k < 10; k++)
            {
                for (double l = 1; l < 10; l++)
                {
                    for (int m = 0; m < 4; m++)
                    {
                        if (debugOperators[m] == '+')
                        {
                            result1 = i + j;
                        }
                        else if (debugOperators[m] == '-')
                        {
                            result1 = i - j;
                        }
                        else if (debugOperators[m] == '*')
                        {
                            result1 = i * j;
                        }
                        else if (debugOperators[m] == '/')
                        {
                            result1 = i / j;
                        }
                        for (int n = 0; n < 4; n++)
                        {
                            if (debugOperators[n] == '+')
                            {
                                result2 = result1 + k;
                            }
                            else if (debugOperators[n] == '-')
                            {
                                result2 = result1 - k;
                            }
                            else if (debugOperators[n] == '*')
                            {
                                result2 = result1 * k;
                            }
                            else if (debugOperators[n] == '/')
                            {
                                result2 = result1 / k;
                            }
                            for (int s = 0; s < 4; s++)
                            {
                                if (debugOperators[s] == '+')
                                {
                                    result3 = result2 + l;
                                }
                                else if (debugOperators[s] == '-')
                                {
                                    result3 = result2 - l;
                                }
                                else if (debugOperators[s] == '*')
                                {
                                    result3 = result2 * l;
                                }
                                else if (debugOperators[s] == '/')
                                {
                                    result3 = result2 / l;
                                }
                                if ((result3 - 24.0) < 0.001 && (result3 - 24.0) >= 0)
                                {
                                    if (debugBool)
                                    {
                                        printf("%d. %.0d%c%.0d%c%.0d%c%.0d\n", count, (int)i,
                                               debugOperators[m], (int)j, debugOperators[n], (int)k, debugOperators[s], (int)l);
                                    }
                                    pArray[count - 1][0] = i;
                                    pArray[count - 1][1] = j;
                                    pArray[count - 1][2] = k;
                                    pArray[count - 1][3] = l;
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return (pArray);
}

/*
 * assess function takes in 4 numbers (a, b, c, d) and 3 operators (op1, op2, op3)
 * and evaluates the expression ((a op1 b) op2 c) op3 d.
 * The function uses the compute function to perform the operations and returns
 * true if the result is equal to 24, and false otherwise.
 */
bool assess(double a, double b, double c, double d, char op1, char op2, char op3)
{
    double result = compute(a, b, op1);
    result = compute(result, c, op2);
    result = compute(result, d, op3);
    return result == 24;
}

/* This function implements the game of TwentyFour. It starts by printing out a welcome message,
then generates 4 random numbers to be used in the game and prompts the user to enter 3 operators.
The function then checks if the user entered 3 valid operators, and if yes,
it calls the assess function to evaluate the result of the computation.
If the result is equal to 24, the user wins, otherwise the user loses.
The function then asks the user if they want to play again and continues until the user decides to stop. */
void play_game(bool easyBool, bool debugBool)
{
    char playAgain = 'y';
    int numbers[4];
    char operators[100];
    printf("Welcome to the game of TwentyFour.\n");
    printf("Use each of the four numbers shown below exactly once, \n");
    printf("combining them somehow with the basic mathematical operators (+,-,*,/) \n");
    printf("to yield the value twenty-four.\n\n");
    bool debugModeRan = false;
    while (playAgain != 'N')
    {
        if (debugBool && !debugModeRan)
        {
            debugMode(debugSolutions, debugBool);
            debugModeRan = true;
        }
        if (easyBool)
        {
            int randomIndex = rand() % 10;
            for (int i = 0; i < 4; i++)
            {
                numbers[i] = easyPuzzles[randomIndex][i];
            }
        }
        if (debugBool && !easyBool)
        {
            int randomIndex = rand() % 3188;
            for (int i = 0; i < 4; i++)
            {
                numbers[i] = debugSolutions[randomIndex][i];
            }
        }
        if (!debugBool && !easyBool)
        {
            debugMode(debugSolutions, debugBool);
            int randomIndex = rand() % 3188;
            for (int i = 0; i < 4; i++)
            {
                numbers[i] = debugSolutions[randomIndex][i];
            }
        }
        printf("The numbers to use are: %d, %d, %d, %d.\n", numbers[0], numbers[1], numbers[2], numbers[3]);
        printf("Enter the three operators to be used, in order (+,-,*, or /): ");
        scanf("%s", operators);
        if (strlen(operators) != 3 || operators[0] == '\n')
        {
            printf("Error! The number of operators is incorrect. Please try again.\n");
            continue;
        }
        bool validoperators = true;
        for (int i = 0; i < 3; i++)
        {
            if (operators[i] != '+' && operators[i] != '-' && operators[i] != '*' && operators[i] != '/')
            {
                validoperators = false;
                break;
            }
        }
        if (!validoperators)
        {
            printf("Error! Invalid operator entered. Please try again.\n");
            continue;
        }
        bool result = assess(numbers[0], numbers[1], numbers[2], numbers[3], operators[0], operators[1], operators[2]);
        if (result)
        {
            printf("Well done! You are a math genius.\n\n");
        }
        else
        {
            printf("Sorry. Your solution did not evaluate to 24.\n\n");
        }
        printf("Would you like to play again? Enter N for no and any other character for yes. \n");
        scanf(" %c", &playAgain);
        if (playAgain == 'N')
        {
            printf("Thanks for playing!\n");
            break;
        }
    }
}

/*
This is the main function of the program.
It takes in two arguments: argc (the number of arguments passed to the program)
and argv (an array of strings representing the arguments passed to the program).
The function starts by looping through the arguments (starting from 1 to exclude the name of the program).
For each argument, it checks if it is "-e". If it is, it checks the next argument to see if its first character is "0".
If the next argument starts with "0", it sets the easyBool variable to false.
For each argument, it checks if it is "-d". If it is, it checks the next argument to see if its first character is "0".
If the next argument starts with "0", it sets the debugBool variable to true.
Finally, the function calls the play_game function with the easyBool and debugBool variables as the argument and returns 0.
*/
int main(int argc, char *argv[])
{
    srand(1);
    bool easyBool = true;
    bool debugBool = false;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-e") == 0)
        {
            if (argv[i + 1][0] == '0')
            {
                easyBool = false;
            }
        }
        else if (strcmp(argv[i], "-d") == 0)
        {
            if (argv[i + 1][0] == '1')
            {
                debugBool = true;
            }
        }
    }
    play_game(easyBool, debugBool);
    return 0;
}
