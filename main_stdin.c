/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 06:38:23 by user42            #+#    #+#             */
/*   Updated: 2020/07/17 11:07:20 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		return_value;
	int		i;

	i = 0;
	fd = 0; // 0 == stdin
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

		printf("LINE %d\n", i);
		printf("-------------------------\n");
		printf("TEXT: %s\n", line);
		printf("return_value = %d\n", return_value);
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
