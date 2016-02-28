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

# include <string.h>

# ifndef READABILITY_STRING_H
# define READABILITY_STRING_H


# define str_compare(str1, str2) strcmp(str1, str2)
# define str_copy(src, dest) strcpy(dest, src)
# define str_append(src, dest) strcat(dest, src)
# define str_find(needle, haystack) strstr(haystack, needle)
# define str_len(str) strlen(str)


# endif /* READABILITY_STRING_H */
