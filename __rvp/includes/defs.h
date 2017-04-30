#ifndef DEFS_H
# define DEFS_H

# define BOARD_MAX_WIDTH 800
# define BOARD_MAX_HEIGHT 800
# define BOARD_NAME ("FdF")

# define KEY_EXIT 53
# define KEY_PARA 0
# define KEY_ISO 0

# ifdef PI
# undef PI
# define PI 3.14159265358979323846
# endif

# ifdef DEBUG
# define DEBUG_VALUE 1
# else
# define DEBUG_VALUE 0
# endif

#endif