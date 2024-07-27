/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:23:28 by rceschel          #+#    #+#             */
/*   Updated: 2024/07/27 20:32:48 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>
void ft_putstr(char *str);
int ft_strlen(char *str)
{
    int l;
    
    l = 0;
    while(str[l])
        l++;
    return (l);
}

char reverse_str(char *str)
{
    char *temp;
    int i;
    int j;
	int size;

	i = 0;
	size = ft_strlen(str);
    while(i < size)
    {
        temp[i] = str[j];
        j--;
		i++;
    }
	str = temp;
}

int *find_line(char *str, int *number_of_line)
{
	int i;
	int ln;

	i = ft_strlen(str) - 1;
	ln = 0;
	while(i >= 0)
	{
		if(str[i] == '0')
		break;
	
		if(i < 2)
		{
			
		}

		if(i % 3 == 0)
		{
			if(str[i] != '0')
				number_of_line[ln++] = str[i] - '0';	
			number_of_line[ln++] = i + 30;
		}
		else if(i % 3 == 1)
		{
			if(str[i] == '1')
			{	
				number_of_line[ln++] = str[--i] - '0' + 10;
				number_of_line[ln++] = i + 30;
			}
			else
			{
				number_of_line[ln++] = str[i] - '0' + 20;
				number_of_line[ln++] = str[--i] - '0';
				number_of_line[ln++] = i + 30;
			}
		}
		else
		{
			if(str[i] != '0')
				number_of_line[ln++] = str[i] - '0';
			number_of_line[ln++] = 32;
		}
		i--;
	}
	i = 0;
	while(i < ln)
	{
		printf("linea :");
		printf("%d", number_of_line[i]);
		printf("\n");
		i++;
	}

	return number_of_line;
}


void ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}

int main()
{
	char *nbr = "987654321";
	int *number_of_line = (int *) malloc(sizeof(int) * 100);
	ft_putstr(nbr);
    ft_putstr("\n");
	number_of_line = find_line(nbr, number_of_line);
	
	int i = 0;
    return 0;

}
