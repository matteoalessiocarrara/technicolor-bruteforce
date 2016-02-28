/*
 * Copyright 2016 Matteo Alessio Carrara <sw.matteoac@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

# ifndef READABILITY_OPERATORS_H
# define READABILITY_OPERATORS_H


/* Boolean logic */
# define and &&
# define not !
# define or ||
# define xor ^

/* Equality testing */
# define is ==
# define is_not !=

/* DEPRECATED */
# define isnot is_not

/* Order relations */
# define less <
# define more >
# define lessoris <=
# define moreoris >=

/* Bitwise shifts */
# define shiftleft <<
# define shiftright >>


# endif /* READABILITY_OPERATORS_H */
