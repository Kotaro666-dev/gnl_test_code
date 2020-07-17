/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 08:40:10 by yiwasa            #+#    #+#             */
/*   Updated: 2020/07/17 11:58:52 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		return_value;
	int		i;
	int		escape;

	escape = argc;
	fd = open(argv[1], O_RDONLY);

	// ERROR出力テスト用
	// fd = 42;
	i = 1;
	printf("-------------------------\n");
	while (1)
	{
		return_value = get_next_line(fd, &line);

		// ERROR出力
		if (return_value == -1)
		{
			printf("ERROR: return_value = %d\n", return_value);
			break ;
		}

		printf("[LINE: %d]\n", i);
		printf("-------------------------\n");
		printf("[RETURN VALUE: %d] TEXT: \"%s\"\n", return_value, line);
		if (return_value == 0)
		{
			break;
		}
		printf("-------------------------\n");
		free(line);
		i++;
	}
	printf("-------------------------\n");
	close(fd);
	return (0);
}
