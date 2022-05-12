#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_lcs(char *str1, char *str2)
{
	int	i;
	int	j;
	int	i_idx;
	int	max_len;
	int	**table;
	char	*lcs;

	max_len = 0;
	i_idx = 0;
	table = (int **)malloc(sizeof(int *) * (strlen(str1) + 1));
	i = 0;
	while (i < strlen(str1) + 1)
	{
		table[i] = (int *)malloc(sizeof(int) * (strlen(str2) + 1));
		i++;
	}
	i = 0;
	while (i < strlen(str1) + 1)
	{
		j = 0;
		while (j < strlen(str2) + 1)
		{
			if (i == 0 || j == 0)
				table[i][j] = 0;
			else if (str1[i - 1] == str2[j - 1])
			{
				table[i][j] = table[i - 1][j - 1] + 1; 
				if (table[i][j] > max_len)
				{
					max_len = table[i][j];
					i_idx = i;
				}
			}
			else
				table[i][j] = 0;
			j++;
		}
		i++;
	}
	lcs = (char *)malloc(sizeof(char) * (max_len + 1));
	i = 0;
	while (i < max_len)
	{
		lcs[i] = str1[i_idx - max_len + i];
		i++;
	}
	lcs[i] = 0;
	i = 0;
	while (i < strlen(str1) + 1)
	{
		free(table[i]);
		i++;
	}
	free(table);
	return (lcs);
}

int	main(void)
{
	char	str1[4001];
	char	str2[4001];
	char	*lcs;

	scanf("%s", str1);
	scanf("%s", str2);
	lcs = ft_lcs(str1, str2);
	printf("%lu", strlen(lcs));
	return (0);
}