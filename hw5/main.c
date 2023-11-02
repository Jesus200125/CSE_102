#include <stdio.h>
#include <math.h>
enum COLOR { RED, GREEN, BLUE, YELLOW, ORANGE };
double red_vector[3] = {1.0, 0.0, 0.0};
double green_vector[3] = {0.0, 1.0, 0.0};
double blue_vector[3] = {0.0, 0.0, 1.0};
double yellow_vector[3] = {0.5, 0.5, 0.0};
double orange_vector[3] = {0.5, 0.4, 0.2};
#define SIZE 3

void drawBoard(char board[SIZE][SIZE]);
int makeMove(char board[SIZE][SIZE], int player);
int hasWinner(char board[SIZE][SIZE]);

int letter_control(char c){   // here controlled is it a letter or not
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char to_lower(char c) {  // if letter is upper here calculated
    if(c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

void letter_count(FILE *fp, int *counts) {  // here read letter from file and added to array
    char c;
    while(fscanf(fp,"%c",&c) == 1){
        if(letter_control(c)){
            c = to_lower(c);
            counts[c - 'a']++;
        }
    }
}

void part_one() // this part one
{
  FILE *fp = fopen("file.txt", "r"); //open file
  if(fp == NULL){ // file does not exist
      printf("Error opening file.\n");
      return;
  }
  int counts[26] = {0};

  letter_count(fp, counts); // call letter count function

  fclose(fp);

  for(int i = 0; i < 26; i++)     printf("%c: %d\n", 'A' + i, counts[i]);
}

double *get_color(int c) {
    switch (c) {
        case RED:
            return red_vector;
        case GREEN:
            return green_vector;
        case BLUE:
            return blue_vector;
        case YELLOW:
            return yellow_vector;
        case ORANGE:
            return orange_vector;
    }
}

double euclidean(double *v1, double *v2) {  // here calculated  with euclidean formula
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    return sqrt(sum);
}

int closest_color(double *vector) {
    int closest = RED;
    double min_distance = euclidean(vector, get_color(RED));  //  here calculated with first min distance
    for (int i = GREEN; i <= ORANGE; i++) {
        double distance = euclidean(vector, get_color(i)); // here calculated other colors and find min distance
        if (distance < min_distance) {
            closest = i;
            min_distance = distance;
        }
    }
    return closest;
}

double mix_colors(int c1, int c2) { // here mixed colors that taken from user
    double mixed_vector[3];
    double *v1 = get_color(c1);  // call first color
    double *v2 = get_color(c2);  // call second color
    for (int i = 0; i < 3; i++) {
        mixed_vector[i] = (v1[i] + v2[i]) / 2; // mix colors
    }
    return closest_color(mixed_vector);
}

int colorMixer(int c1, int c2, double(*mixer)(int c1, int c2)) {  // here sent function as pointer argument
    return mixer(c1, c2);
}

void part_two()
{
  int color1;
  int color2;
  printf("Enter first color (r,g,b,y,o):");
  char c1;
  scanf(" %c",&c1);
  switch (c1) {
      case 'r':
          color1 = RED;
          break;
      case 'g':
          color1 = GREEN;
          break;
      case 'b':
          color1 = BLUE;
          break;
      case 'y':
          color1 = YELLOW;
          break;
      case 'o':
          color1 = ORANGE;
          break;
  }

  printf("Enter second color (r,g,b,y,o): ");
  char c2;
  scanf(" %c",&c2);
  switch (c2) {
      case 'r':
          color2 = RED;
          break;
      case 'g':
          color2 = GREEN;
          break;
      case 'b':
          color2 = BLUE;
          break;
      case 'y':
          color2 = YELLOW;
          break;
      case 'o':
          color2 = ORANGE;
          break;
  }
  int mc = colorMixer(color1, color2, mix_colors);
  printf("Mixed color:");
  if(mc == 0)  printf("RED [1, 0, 0]\n");
  else if(mc == 1) printf("GREEN [0, 1, 0]\n");
  else if(mc == 2) printf("BLUE [0, 0, 1]\n");
  else if(mc == 3) printf("YELLOW [0.5, 0.5, 0]\n");
  else if(mc == 4) printf("ORANGE [0.5, 0.4, 0.2]\n");
}

void part_three()
{
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1;
    int winner = 0;
    int moves = 0;

    while (!winner && moves < SIZE * SIZE) {  // this loop working till board filled
        drawBoard(board);  // draw board
        if (!makeMove(board, player)) {
            continue;
        }
        winner = hasWinner(board);
        player = player == 1 ? 2 : 1;
        moves++;
    }

    drawBoard(board);

    if (winner) {
        printf("Player %d is the winner!\n", winner);
    } else {
        printf("It's a draw!\n");
    }

    char playAgain;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &playAgain);

    if (playAgain == 'y' || playAgain == 'Y') {
        part_three();  // here call again part three
    }
}

void drawBoard(char board[SIZE][SIZE]) {  // here draw  board
    for (int i = 0; i < 2; i++) {
        printf("\n");
    }
    printf("\nTic-Tac-Toe\n\n");

    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i != SIZE - 1) {
            printf("---+---+---\n");
        }
    }
}

int makeMove(char board[SIZE][SIZE], int player) {
    int row, col;
    printf("\nPlayer %d, enter your move (row [1-3] and column [1-3]): ", player);
    scanf("%d%d", &row, &col);

    if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != ' ') { // if invalid input
        printf("Invalid move. Try again.\n");
        return 0;
    }

    board[row - 1][col - 1] = player == 1 ? 'X' : 'O';  // if player equal 1 put X else put 0
    return 1;
}

int hasWinner(char board[SIZE][SIZE]) {  // here controlled who is win
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {  // here controlled row
            return board[i][0] == 'X' ? 1 : 2;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {  // here controlled row
            return board[0][i] == 'X' ? 1 : 2;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) { // here controlled diogonal
        return board[0][0] == 'X' ? 1 : 2;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 'X' ? 1 : 2;
    }

    return 0;
}

int main() {

  int a=0;
  while(a != 4)
  {
    printf("PART 1\nPART 2\nPART 3\nEXIT 4\nChoose a part:");
    scanf("%d",&a);
    switch(a){
      case 1: part_one(); break;
      case 2: part_two(); break;
      case 3: part_three(); break;
      case 4: return 0;
    }
  }
    return 0;
}
