#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

int line_is_valid(int grid[10][10], int i, int j)
{
	while (j >= 0)
	{
		j--;
		if (j < 0)
			break;
		if (grid[i][j] == 1)
			return (0);
	}
	return (1);
}

int high_diagonal_is_valid(int grid[10][10], int i, int j)
{
	while (i >= 0 || j >= 0)
	{
		i--;
		j--;
		if (i < 0 || j < 0)
			break;
		if (grid[i][j] == 1)
			return (0);
	}
	return (1);
}

int low_diagonal_is_valid(int grid[10][10], int i, int j)
{
	while (i <= 9 || j >= 0)
	{
		i++;
		j--;
		if (i > 9 || j < 0)
			break;
		if (grid[i][j] == 1)
			return (0);
	}
	return (1);
}

void write_solution(int grid[10][10])
{	
	int i;
	int j;

	j = 0;
	while (j <= 9)
	{
		i = 0;
		while (i <= 9)
		{
			if (grid[i][j] != 0)
			{
				ft_putchar(i + '0');
			}
			i++;
		}
		j++;
	}
	ft_putchar('\n');
}

void initilize_grid(int grid[10][10])
{
	int i;
	int j;

	i = 0;
	while (i <= 9)
	{
		j = 0;
		while (j <= 9)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int solver(int grid[10][10], int j, int *count)
{
	int i;

	i = 0;
	/* condition d'arret*/
	if (j > 9 && i > 9)
		return (1);
	/*fonction recursive*/
	while (i <= 9)
	{
		if (line_is_valid(grid, i, j) && high_diagonal_is_valid(grid, i, j) 
				&& low_diagonal_is_valid(grid, i, j))
		{
			grid[i][j] = 1;
			if (j == 9)
			{
				write_solution(grid);
				(*count)++;
			}
			if (solver(grid, j + 1, count))
				return (1);
		}
		i++;
	}
	/*on réinitialise la colonne*/
	i = 0;
	while (i <= 9)
	{
		grid[i][j - 1] = 0;
		i++;
	}
	return (0);

}
int ft_ten_queens_puzzle(void)
{
	int grid[10][10];
	int count;

	count = 0;
	initilize_grid(grid);
	solver(grid, 0, &count);
	write(1, "count = ", 8);
	ft_putnbr(count);
	return (count);
}

int main()
{
	int rtn;

	printf("return = %d\n", ft_ten_queens_puzzle());

	rtn = ft_ten_queens_puzzle();
	write(1, "rtn = ", 6);
	ft_putnbr(rtn);
}
