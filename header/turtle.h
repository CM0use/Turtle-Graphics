/**
 ** This file is part of Turtle-Graphics project
 ** Copyright 2023 CM0use dilanuzcs@gmail.com
 ** URL: https://github.com/CM0use/Turtle-Graphics
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

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
