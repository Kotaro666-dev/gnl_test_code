# コンパイルするコマンド
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=XX main.c get_next_line.c get_next_line_utils.c

# Large BUFF_SIZE (>1024)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 main.c get_next_line.c get_next_line_utils.c

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000 main.c get_next_line.c get_next_line_utils.c

# Small BUFF_SIZE (< 8, and 1)
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 main.c get_next_line.c get_next_line_utils.c

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c

# 1 byte variant (+/-) between the line and the BUFF_SIZE
text_short_line_multi.txt has 3 lines.

# line + 1
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=4 main.c get_next_line.c get_next_line_utils.c

# line - 1
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=2 main.c get_next_line.c get_next_line_utils.c

# Read on stdin
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main_stdin.c get_next_line.c get_next_line_utils.c

# Bonus
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c
