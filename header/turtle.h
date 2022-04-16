
//          Copyright CM0use.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

# ifndef TURTLE_H
# define TURTLE_H

# include <stdlib.h>
# include <stdint.h>

# ifdef _WIN32
# define CLEAN_SCREEN system("CLS");
# elif __APPLE__
# define CLEAN_SCREEN system("clear");
# elif __linux__
# define CLEAN_SCREEN system("clear");
# endif

# define MAX_COLUMNS (8)
# define MAX_ROWS (16)
# define ICON ('O')

typedef struct {
	uint16_t y, x;
	char icon;
	enum {
		ABOVE = 0,
		BELOW,
		DRAFT
	} pen;
	enum {
		UP = 0,
		DOWN,
		LEFT,
		RIGHT
	} direction;
}animal;

void instructions(void);
void startSettings(animal *const, char [MAX_COLUMNS][MAX_ROWS]);
void showValues(const animal *const);
void showMap(char [MAX_COLUMNS][MAX_ROWS]);
void orientation(animal *const);
void move(animal *const, char [MAX_COLUMNS][MAX_ROWS]);
uint16_t input(uint16_t *const);

# endif
