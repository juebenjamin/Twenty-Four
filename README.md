# Twenty-Four

![](https://user-images.githubusercontent.com/47327357/219986631-dfca3d9f-8b35-42dd-ac1c-ed4ec9e5b803.gif)


This is a C program for a game called TwentyFour.
This is a C program for a game called TwentyFour. The program generates 4 random numbers and prompts the user to enter three operators to be used to evaluate the expression ((a op1 b) op2 c) op3 d, where a, b, c, d are the four generated numbers and op1, op2, op3 are the operators entered by the user. The program then uses the compute function to perform the operations and evaluates the expression. If the result is equal to 24, the user wins; otherwise, the user loses.

The program provides two optional arguments:

"-e": to set the game difficulty. If the next argument starts with "0", it sets the game difficulty to hard; otherwise, the default value is easy.
"-d": to enable the debug mode. If the next argument starts with "0", it disables the debug mode; otherwise, the default value is enabled.
The program uses a 2D array named debugSolutions to store solutions for mathematical computation. It also defines a constant 2D array named easyPuzzles that holds easy puzzle numbers.

The program has several functions:

compute function: takes in two numbers (a, b) and an operator (operator) and performs the computation a operator b. The function returns the result of the operation.
debugMode function: takes an array of solutions and a boolean flag indicating whether the debug mode is enabled or not. If the debug mode is enabled, the function prints each solution to the console and returns the array of solutions. If the debug mode is not enabled, the function will not print out all the solutions.
assess function: takes in 4 numbers (a, b, c, d) and 3 operators (op1, op2, op3) and evaluates the expression ((a op1 b) op2 c) op3 d. The function uses the compute function to perform the operations and returns true if the result is equal to 24, and false otherwise.
play_game function: implements the game of TwentyFour by generating 4 random numbers and prompting the user to enter 3 operators. The function then calls the assess function to evaluate the result of the computation. If the result is equal to 24, the user wins, otherwise the user loses. The function then asks the user if they want to play again and continues until the user decides to stop.
main function: is the entry point of the program. It processes the optional arguments and calls the play_game function with the easyBool and debugBool variables as the argument.
