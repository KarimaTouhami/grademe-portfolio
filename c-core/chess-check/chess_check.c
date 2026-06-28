#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2) return (0);

	char	*b = argv[1];
	int		size = 0, kx = -1, ky = -1;

	while (b[size] && b[size] != '\n')
		size++;

	int i = 0, r = 0, c = 0;
	while (b[i])
	{
		if (b[i] == '\n') { r++; c = 0; }
		else {
			if (b[i] == 'K') { kx = c; ky = r; }
			c++;
		}
		i++;
	}
	if (kx == -1) return (0);

	int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
	int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};

	for (int d = 0; d < 8; d++)
	{
		int x = kx + dx[d];
		int y = ky + dy[d];

		while (x >= 0 && x < size && y >= 0 && y < size)
		{
			char p = b[y * (size + 1) + x];

			if (p != '.')
			{
				if (d < 4 && (p == 'R' || p == 'Q'))
					return (write(1, "Success\n", 8), 0);
				if (d >= 4 && (p == 'B' || p == 'Q'))
					return (write(1, "Success\n", 8), 0);
				if (d >= 4 && d <= 5 && y == ky + 1 && p == 'P')
					return (write(1, "Success\n", 8), 0);

				break;
			}
			x += dx[d];
			y += dy[d];
		}
	}

	write(1, "Fail\n", 5);
	return (0);
}