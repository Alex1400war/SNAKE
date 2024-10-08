#include <unistd.h>
#include <stdlib.h>

typedef struct snake
{
	char	head;
	char	body;
	int	size;
	char	obj;

} snake;

char	**Mboard()
{
	struct snake snake;
	int	x;
	int	y;
	char	**map;

	map = (char **)malloc(6 * sizeof(char *));
	for (int i = 0; i < 6; i++)
		map[i] = (char *)malloc(6 * sizeof(char));

	snake.head = 's';
	snake.body = 'x';
	snake.size = 1;
	snake.obj = 'O';
	x = 0;
	y = 0;
	while (y < 6)
		{
			x = 0;
			while (x < 6)
			{
				if ( y == 3 && x == 3)
					map[y][x] = snake.head;
				else
					map[y][x] = '.';
				x++;
			}
			y++;
		}
	return (map);
}

void	print_board(char **board)
{
	int	x;
	int	y;
	struct snake snake;

	x = 0;
	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			write(1, &board[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
} 	


int	Snake_Size()
{
	char	**map;
	int	x;
	int	y;
	int	size;
	struct snake snake;

	x = 0;
	y = 0;
	size = 0;
	map = Mboard();
	if (map[y][x] == snake.obj && map[y][x] == snake.head)
	{
		map[y][x] == snake.head;
		snake.size++;

	}
	size = snake.size;
	return (size);
}

int	main()
{
	char **board;
	int	i;

	board = Mboard();
	print_board(board);

	for (i = 0; i < 6; i++)
		free(board[i]);
	free(board);

	return 0;
}
