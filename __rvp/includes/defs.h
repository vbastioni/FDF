#ifndef DEFS_H
# define DEFS_H

# define BOARD_MAX_WIDTH 800
# define BOARD_MAX_HEIGHT 800
# define BOARD_NAME ("FdF")

# define KEY_EXIT 53
# define KEY_PARA 18
# define KEY_ISO 19

# define COL_LOW 0x15439b
# define COL_HIGH 0x9b4815
# define COL_DEF 0xFFFFFF

# ifdef PI
# undef PI
# define PI 3.14159265358979323846
# endif

# ifdef DEBUG
# define DEBUG_VALUE 1
# else
# define DEBUG_VALUE 0
# endif

typedef unsigned char   t_uchar;

#endif