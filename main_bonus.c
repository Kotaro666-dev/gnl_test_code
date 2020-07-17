/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:20:01 by kkamashi          #+#    #+#             */
/*   Updated: 2020/07/17 11:42:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(void)
{
	int		fd[3];
	char	*line;
	int		return_value[3];
	int		i;

	fd[0] = open("text_bonus_first.txt", O_RDONLY);
	fd[1] = open("text_bonus_second.txt", O_RDONLY);
	fd[2] = open("text_bonus_third.txt", O_RDONLY);

	// ERROR出力テスト用
	// fd = 42;
	i = 1;
	while (1)
	{
		return_value[0] = get_next_line(fd[0], &line);
		printf("\x1b[31m");     /* 前景色を赤に */
		printf("-------------------------\n");
		printf("LINE %d(FIRST TEXT)\n", i);
		printf("-------------------------\n");
		printf("TEXT: %s\n", line);
		printf("return_value: %d\n", return_value[0]);
		printf("-------------------------\n");
		free(line);

		return_value[1] = get_next_line(fd[1], &line);
		printf("\x1b[32m");     /* 前景色を緑に */
		printf("-------------------------\n");
		printf("LINE %d(SECOND TEXT)\n", i);
		printf("-------------------------\n");
		printf("TEXT: %s\n", line);
		printf("return_value: %d\n", return_value[1]);
		printf("-------------------------\n");
		free(line);

		return_value[2] = get_next_line(fd[2], &line);
		printf("\x1b[33m");     /* 前景色を黄色に */
		printf("-------------------------\n");
		printf("LINE %d(THIRD TEXT)\n", i);
		printf("-------------------------\n");
		printf("TEXT: %s\n", line);
		printf("return_value: %d\n", return_value[2]);
		printf("-------------------------\n");

		free(line);

		if (return_value[0] == 0 && return_value[1] == 0 && return_value[2] == 0 )
		{
			break;
		}
		i++;
		printf("\n\n");
	}

	i = 0;
	while (i < 3)
	{
		close(fd[i]);
		i++;
	}
	printf("\x1b[0m");      /* デフォルトに戻す */
	return (0);
}
