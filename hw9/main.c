#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int row;
	int col;
}Point;

typedef struct{
	char type;
	int value;
}Block;

typedef struct{
	int length;
	int moves;
	Point* body;
}Snake;

Block*** init_board();

void draw_board(Block*** board);

void play(Block*** board);

void move(Snake* snake);

int check_status(Snake* snake, Block*** board);

int update(Snake* snake, Block*** board);

int main() {

	Block*** board = init_board();
	play(board);
	return 0;
}

void play(Block*** board){

	//initialize snake
	  int move=0;
	  Snake snake;
    snake.length = 1;
    snake.moves = 0;
    snake.body = (Point*)malloc(sizeof(Point));
    snake.body[0].row = 0;
    snake.body[0].col = 0;
    //update the board for snake
    board[0][0]->type = 's';
    board[0][0]->value = 0;
		do {
    draw_board(board);
    if (!update(&snake, board)) {
        break; // finish loop
    }
} while (1);
}

Block*** init_board(){

	int i, j;//counter for the for loops
	srand(time(NULL));//read time

	//allocate memory for game board
	Block*** board = (Block*)malloc(10 * sizeof(Block**));
	for(i = 0; i < 10; i++)
	{
		board[i] = (Block**)malloc(10 * sizeof(Block*));
		for(j = 0; j < 10; j++)
		{
			board[i][j] = (Block***)malloc(sizeof(Block));
			board[i][j]->type = 'e';
			board[i][j]->value = 0;
		}
	}

	//place a random obstacle
	int obs_row, obs_col;
	do{
		obs_row = rand() % 10;
		obs_col = rand() % 10;
	}while(obs_row == 0 && obs_col == 0);
	board[obs_row][obs_col]->type = 'o';
	board[obs_row][obs_col]->value = 1;

	do{
		obs_row = rand() % 10;
		obs_col = rand() % 10;
	}while(obs_row == 0 && obs_col == 0 && board[obs_row][obs_col]->type != 'o' );
	board[obs_row][obs_col]->type = 'o';
	board[obs_row][obs_col]->value = 1;

	//place a random bait
	int bait_row, bait_col;
	do{
		bait_row = rand() % 10;
		bait_col = rand() % 10;
	}while((bait_row == 0 && bait_col == 0) || (bait_row == obs_row && bait_col == obs_col));
	board[bait_row][bait_col]->type = 'b';
	board[bait_row][bait_col]->value = 0;

	return board;
}

void move(Snake* snake)
{
	char direction, clear;
	int valid_move = 0;
	while(!valid_move){
		printf("\nMove the snake. 'w' for up, 's' for down, 'a' for left and 'd' for right: ");
		scanf(" %c", &direction);
		switch (direction){
			case 'w':
				snake->body[0].row--;
				valid_move = 1;
				break;
			case 's':
				snake->body[0].row++;
				valid_move = 1;
				break;
			case 'a':
				snake->body[0].col--;
				valid_move = 1;
				break;
			case 'd':
				snake->body[0].col++;
				valid_move = 1;
				break;
			default:
				valid_move = 0;
				printf("Invalid move!\n");
				break;
		}
	}
}

int update(Snake* snake, Block*** board)
{
	Point head;
	Point tail;
	Point temp;
	int baitrow, baitcol;
	int obsrow, obscol;
	int s; // counter for snake
	int obscounter = 0;
	int i, j;
	int gamestate = 0;
	int random;

	//store the previous location
	head = snake->body[0];
	tail = snake->body[snake->length - 1];
	//get the new location
	move(snake);
	snake->moves++;
	//check the new location
	gamestate = check_status(snake, board);

	if(gamestate == 1)
	{
		return 0;
	}

	//if ate the bait
	if(board[snake->body[0].row][snake->body[0].col]->type == 'b'){
		//increase length of the snake
		snake->length++;
		//allocate memory for new snake parts
		Point* new_body;
		new_body = (Point*)realloc(snake->body, snake->length * sizeof(Point));
		if(new_body != NULL)
		{
			snake->body = new_body;
			snake->body[snake->length - 1].row = 0;
			snake->body[snake->length - 1].col = 0;
		}
		else
		{
			printf("Memory fully.Dynamic allocation is not working!");
			return 0;
		}
		//generate new bait
		do{
			baitrow = rand() % 10;
			baitcol = rand() % 10;
		}while(board[baitrow][baitcol]->type != 'e');
		board[baitrow][baitcol]->type = 'b';
	}

	//shift snake
	for(s = 1; s < snake->length; s++){
		temp = snake->body[s];
		snake->body[s] = head;
		head = temp;
	}
	//update board
	for(s = 0; s < snake->length; s++){
		board[snake->body[s].row][snake->body[s].col]->type = 's';
		if(s == 0){
			board[snake->body[s].row][snake->body[s].col]->value = 0;
		}else if(s == 1 || s == 2){
			board[snake->body[s].row][snake->body[s].col]->value = 1;
		}else{
			board[snake->body[s].row][snake->body[s].col]->value = 2;
		}
	}
	//update tail's previous location
	board[tail.row][tail.col]->type = 'e';
	board[tail.row][tail.col]->value = 0;
  int randobs,obsvalue;
	int a,b,c;

	// remove obstacle
	if(snake->moves % 5 == 0)
	{
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				if(board[i][j]->type == 'o')
				{
					board[i][j]->type = 'e';
					board[i][j]->value = 0;
				}
			}
		}
	}
	//add obstacle
	if(snake->moves % 5 == 0)
	{
		randobs = rand() % 3 + 1;
		for(a=0; a<randobs; a++)
		{
			obsrow = rand() % 10;
			obscol = rand() % 10;
			if(board[obsrow][obscol]->type == 'e')
			{
				obsvalue = rand() % snake->length + 2;
				while(obsvalue > 9)
				{
					obsvalue = rand() % snake->length + 2;
				}
				board[obsrow][obscol]->type = 'o';
				board[obsrow][obscol]->value = obsvalue;
			}
			else a--;
		}
	}
	return 1;
}

int check_status(Snake* snake, Block*** board){
	Point head;
	head = snake->body[0];
	//check if snake hits wall
	if(head.row < 0 || head.row  >= 10 || head.col < 0 || head.col >= 10){
		printf("GAME OVER!!! Total move : %d\n",snake->moves);
		return 1;
	}
	//check if snake hits his own body
	if(board[head.row][head.col]->type == 's' && board[head.row][head.col]->value == 2){
		printf("GAME OVER!!! Total move : %d\n",snake->moves);
		return 1;
	}
	//check if snake hits obstacle longer than itself
	if(board[head.row][head.col]->type == 'o' && board[head.row][head.col]->value > snake->length){
		printf("GAME OVER!!! Total move : %d\n",snake->moves);
		return 1;
	}
	return 0;
}

void draw_board(Block*** board)
{
	int i, j;
	printf("\n");
	printf("------------\n");
	for(i = 0; i < 10; i++){
		printf("|");
		for(j = 0; j < 10; j++){
			if(board[i][j]->type == 's' && board[i][j]->value == 0)
			{
				printf("O");//head of the snake
			}
			else if(board[i][j]->type == 's' && (board[i][j]->value == 1 || board[i][j]->value == 2))
			{
				printf("X");//body of the snake
			}
			else if(board[i][j]->type == 'o')
			{
				printf("%d", board[i][j]->value);//obstacle cell
			}
			else if(board[i][j]->type == 'b')
			{
				printf(".");//bait cell
			}
			else
			{
				printf(" ");//empty cell
			}
		}
		printf("|\n");
	}
	printf("\b-------------\n");
}
