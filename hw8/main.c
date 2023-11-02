#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct board {
    int grid[3][3]; // A 3x3 array to store the numbers
    int empty_row; // The row index of the empty space
    int empty_col; // The column index of the empty space
};

struct board puzzle; // The puzzle board
int moves; // The number of moves taken
int best_score; // The best score achieved
void init_board(); // Initialize the puzzle board with random number
void print_board(); // Print the puzzle board to the screen
void save_board(); // Save the puzzle board to a file
int is_solved(); // Check if the puzzle is solved
int is_legal(int num, char dir); // Check if a move is legal
void swap(int *a, int *b); // Swap two integers
void move(int num, char dir); // Move a number in a direction
void play_user(); // Play the game as a user
void play_pc(); // Play the game with PC
int auto_finish(); // Solve the puzzle automatically with random moves
void load_best_score(); // Load the best score
void init_board() {
    // Initialize the puzzle board with random numbers
    // Use a temporary array to store the numbers from 0 to 8
    int temp[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    // Shuffle the array using Fisher-Yates algorithm
    srand(time(NULL)); // Set the random seed
    for (int i = 8; i > 0; i--) {
        int j = rand() % (i + 1); // Pick a random index from 0 to i
        swap(&temp[i], &temp[j]); // Swap the elements at i and j
    }
    // Copy the shuffled array to the puzzle board
    int k = 0; // A counter for the array index
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            puzzle.grid[i][j] = temp[k]; // Assign the number to the grid cell
            if (temp[k] == 0) { // If the number is zero, mark it as the empty space
                puzzle.empty_row = i;
                puzzle.empty_col = j;
            }
            k++; // Increment the counter
        }
    }
}

void print_board() {

    printf("The puzzle board is:");
    for (int i = 0; i < 3; i++) {
        printf("\n"); // Print a horizontal line
        for (int j = 0; j < 3; j++) {
            if (puzzle.grid[i][j] == 0) { // If the cell is empty, print a space
                printf(" _ ");
            } else { // Otherwise, print the number
                printf(" %d ", puzzle.grid[i][j]);
            }
        }
        //printf("\n"); // Print a vertical line
    }
    printf("\n"); // Print a horizontal line
}

void save_board() {

    FILE *fp=fopen("puzzle.txt","a");
    fprintf(fp, "The puzzle board is:");
    for (int i = 0; i < 3; i++) {
        fprintf(fp,"\n");
        for (int j = 0; j < 3; j++) {
            if (puzzle.grid[i][j] == 0) {
                fprintf(fp, "   ");
            } else {
                fprintf(fp, " %d ", puzzle.grid[i][j]);
            }
        }
    }
    fprintf(fp, "\n");
    fclose(fp);
}

int is_solved() {
    // Check if the puzzle is solved
    int k = 1; // A counter for the expected number
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (puzzle.grid[i][j] != k) { // If the cell does not match the expected number
                if (i == 2 && j == 2 && puzzle.grid[i][j] == 0) { // If it is the last cell and it is empty, then it is solved
                    return 1;
                } else { // Otherwise, it is not solved
                    return 0;
                }
            }
            k++; // Increment the counter
        }
    }
}

int is_legal(int num, char dir) {
    // Check if a move is legal
    if (num < 1 || num > 8) { // If the number is out of range, it is illegal
        return 0;
    }
    int row, col; // The row and column indices of the number to be moved
    int found = 0; // A flag to indicate if the number is found on the board
    for (int i = 0; i < 3 && !found; i++) {
        for (int j = 0; j < 3 && !found; j++) {
            if (puzzle.grid[i][j] == num)
 if (puzzle.grid[i][j] == num) { // If the number is found on the board
                row = i; // Store its row index
                col = j; // Store its column index
                found = 1; // Set the flag to true
            }
        }
    }
    if (!found) { // If the number is not found on the board, it is illegal
        return 0;
    }
    switch (dir) {
        case 'U':
            if (row == 0 || puzzle.grid[row - 1][col] != 0) { // If it is at the top edge or there is a non-zero number above it, it is illegal
                return 0;
            }
            break;
        case 'D':
            if (row == 2 || puzzle.grid[row + 1][col] != 0) { // If it is at the bottom edge or there is a non-zero number below it, it is illegal
                return 0;
            }
            break;
        case 'L':
            if (col == 0 || puzzle.grid[row][col - 1] != 0) { // If it is at the left edge or there is a non-zero number to its left, it is illegal
                return 0;
            }
            break;
        case 'R':
            if (col == 2 || puzzle.grid[row][col + 1] != 0) { // If it is at the right edge or there is a non-zero number to its right, it is illegal
                return 0;
            }
            break;
        default: // If it is not a valid direction, it is illegal
            return 0;
    }
    return 1; // If none of the above cases apply, it is legal
}

void swap(int *a, int *b) {
    // Swap two integers
    int temp = *a; // Store the value of a in a temporary variable
    *a = *b; // Assign the value of b to a
    *b = temp; // Assign the value of temp to b
}

void move(int num, char dir) {
    // Move a number in a direction
    int row, col; // The row and column indices of the number to be moved
    int found = 0; // A flag to indicate if the number is found on the board
    for (int i = 0; i < 3 && !found; i++) {
        for (int j = 0; j < 3 && !found; j++) {
            if (puzzle.grid[i][j] == num) { // If the number is found on the board
                row = i; // Store its row index
                col = j; // Store its column index
                found = 1; // Set the flag to true
            }
        }
    }
    switch (dir) { // Check the direction of the move
        case 'U': // If it is up
            swap(&puzzle.grid[row][col], &puzzle.grid[row - 1][col]); // Swap the number with the empty space above it
            puzzle.empty_row++; // Update the row index of the empty space
            break;
        case 'D': // If it is down
            swap(&puzzle.grid[row][col], &puzzle.grid[row + 1][col]); // Swap the number with the empty space below it
            puzzle.empty_row--; // Update the row index of the empty space
            break;
        case 'L': // If it is left
            swap(&puzzle.grid[row][col], &puzzle.grid[row][col - 1]); // Swap the number with the empty space to its left
            puzzle.empty_col++; // Update the column index of the empty space
            break;
        case 'R': // If it is right
            swap(&puzzle.grid[row][col], &puzzle.grid[row][col + 1]); // Swap the number with the empty space to its right
            puzzle.empty_col--; // Update the column index of the empty space
            break;
    }
    moves++; // Increment the number of moves taken
}

void play_user() {

    init_board(); // Initialize the puzzle board with random numbers
    FILE *fp = fopen("puzzle.txt", "a"); // Open a file to save the puzzle board
    if (fp == NULL) { // If the file cannot be opened, print an error message and exit
        printf("Cannot open file.\n");
        return;
    }
    fprintf(fp,"User playing\n");
    fclose(fp);
    save_board(); // Save the initial state of the puzzle board to the file

    print_board(); // Print the puzzle board to the screen

    while (!is_solved()) { // While the puzzle is not solved
        int num; // The number to be moved
        char dir; // The direction of the move
        printf("Enter a number and a direction (U/D/L/R) to move (e.g., 2-R): ");
        scanf("%d-%c", &num, &dir); // Read the user input
        if (is_legal(num, dir)) { // If the move is legal
            move(num, dir); // Make the move
            save_board(); // Save the updated state of the puzzle board to the file
            print_board(); // Print the puzzle board to the screen
        } else { // If the move is illegal
            printf("Invalid move. Try again.\n"); // Print a warning message
        }
    }
    printf("Congratulations! You solved the puzzle in %d moves.\n", moves); // Print a congratulatory message
    int score = 1000 - 10 * moves; // Calculate the score
    printf("Your score is %d.\n", score); // Print the score

    load_best_score(); // Load the best score

    if (score > best_score) { // If the user has the best score
        printf("You have the best score!\n"); // Print a message
        best_score = score; // Update the best score
        FILE *fp2 = fopen("best_score.txt", "w"); // Open a file to save the best score
        if (fp2 == NULL) { // If the file cannot be opened, print an error message and exit
            printf("Cannot open file.\n");
            exit(1);
        }
        fprintf(fp2, "%d\n", best_score); // Save the best score to the file
        fclose(fp2);
    }
}

void play_pc() {

    init_board(); // Initialize the puzzle board with random numbers

    FILE *fp = fopen("puzzle.txt", "w"); // Open a file to save the puzzle board
    if (fp == NULL) { // If the file cannot be opened, print an error message and exit
        printf("Cannot open file.\n");
        return;
    }
    fprintf(fp,"Computer playing\n");
    fclose(fp);
    int max_move = 100000,count=0;
    save_board(); // Save the initial state of the puzzle board to the file

    print_board(); // Print the puzzle board to the screen

    if(auto_finish(max_move,count) == -1)
    {
      printf("The PC is not solve the puzzle in %d moves.\n",max_move);
      return;
    } // Solve the puzzle automatically with random moves

    printf("The PC solved the puzzle in %d moves.\n", moves);
    return;
}

int auto_finish(int a, int b) {

    if (is_solved()) { // If the puzzle is solved, return from the function
        return 0;
    }
    if (b == a)  return -1;  // if computer make 100000 move
    int num; // The number to be moved
    char dir; // The direction of the move

    do {
        num = rand() % 8 + 1; // Pick a random number from 1 to 8
        dir = "UDLR"[rand() % 4]; // Pick a random direction from U/D/L/R
    } while (!is_legal(num, dir)); // Repeat until a legal move is found

    move(num, dir); // Make the move

    //save_board(); // Save the updated state of the puzzle board to the file
    FILE *fp=fopen("puzzle.txt","a");
    fprintf(fp, "Computer move %d-%c:",num,dir);
    for (int i = 0; i < 3; i++) {
        fprintf(fp,"\n");
        for (int j = 0; j < 3; j++) {
            if (puzzle.grid[i][j] == 0) {
                fprintf(fp, "   ");
            } else {
                fprintf(fp, " %d ", puzzle.grid[i][j]);
            }
        }
        //fprintf(fp, "|\n");
    }
    fprintf(fp, "\n");
    fclose(fp);

    //print_board(); // Print the puzzle board to the screen
    //printf("The puzzle board is:");
    for (int i = 0; i < 3; i++) {
        printf("\n"); // Print a horizontal line
        for (int j = 0; j < 3; j++) {
            if (puzzle.grid[i][j] == 0) { // If the cell is empty, print a space
                printf(" _ ");
            } else { // Otherwise, print the number
                printf(" %d ", puzzle.grid[i][j]);
            }
        }
    }
    printf("\n\nComputer move %d-%c\n",num,dir);
    b++;
    auto_finish(a,b); // Call the function recursively until the puzzle is solved
}

void load_best_score() {

    FILE *fp = fopen("best_score.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return;
    }
    fscanf(fp, "%d", &best_score); // Read the best score from the file
    fclose(fp);
}

int main() {

    int choice;
    do {
        printf("Welcome to 8-puzzle game!\n");
        printf("Please choose an option:\n");
        printf("(1) Play game as a user\n");
        printf("(2) Finish the game with PC\n");
        printf("(3) Show the best score\n");
        printf("(4) Exit\n");
        scanf("%d", &choice);

        switch (choice) { // Check the user's choice
            case 1:
                moves = 0;
                play_user(); // Play the game as a user
                break;
            case 2:
                moves = 0;
                play_pc(); // Play the game with PC
                break;
            case 3:
                load_best_score(); // Load the best score
                printf("The best score is %d.\n", best_score);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
