#include "../cub3d.h"

void parsir2(char *str, t_zone *zone, int a)
{
	int	i[2];
	char **str2;

	i[0] = 0;
	i[1] = 0;
	if (str[i[0]] == "F")
	{
		str2 = ft_split(str, " ");
		zone->F = ft_strdup(str2[1]);
		free (str2);
	}
	else if (str[i[0]] == "C")
	{
		str2 = ft_split(str, " ");
		zone->F = ft_strdup(str2[1]);
		free (str2);
	}
	return (1);
}

void parser(char *str, t_zone *zone, int a)
{
	int	i;
	int a;
	char **str2;

	a = 0;
	i = 0;
	if (str[i] == "N" && str[i + 1] == "O")
	{
		str2 = ft_split(str, " ");
		zone->NO = ft_strdup(str2[1]);
		free (str2);
	}
	else if (str[i] == "S" && str[i + 1] == "O")
	{
		str2 = ft_split(str, " ");
		zone->SO = ft_strdup(str2[1]);
		free (str2);
	}
	else if (str[i] == "W" && str[i + 1] == "E")
	{
		str2 = ft_split(str, " ");
		zone->WE = ft_strdup(str2[1]);
		free (str2);
	}
	else if (str[i] == "E" && str[i + 1] == "A")
	{
		str2 = ft_split(str, " ");
		zone->EA = ft_strdup(str2[1]);
		free (str2);
	}
	else
		parser2(str, zone, a);
}

int main(int argc, char **argv)
{
	int	i;
	int	a;
	FILE *file;
	char *str;
	t_zone zone;
	i = 0;
	a = 0;

	str = NULL;
	if (argc != 2)
		return(0);
	if (!(file = open(argv[1], O_RDWR)))
		return(0);
	while (str = get_next_line(file))
	{
		if (ft_strncmp(str, "\n", 1) == 0 )
			parser(str, &zone, i);
		i++;


		
	}
}
