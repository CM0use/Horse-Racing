/**
 ** This file is part of Horse-Racing project
 ** Copyright 2023 CM0use dilanuzcs@gmail.com
 ** URL: https://github.com/CM0use/Horse-Racing
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

#ifndef UTILITIES_H
#define UTILITIES_H

# include <thread>

# define ANIMALS      (9)
# define ICON         ('A')
# define ICON_FLOOR   ('_')
# define TIME         (0.123s)
# define MIN          (0)
# define MAX          (70)

# ifdef _WIN32
# define CLEAN_SCREEN system("CLS")
# elif __APPLE__
# define CLEAN_SCREEN system("clear")
# elif __linux__
# define CLEAN_SCREEN system("clear")
# endif

void startSettings(std::array<std::array<std::uint8_t, MAX>, ANIMALS> &animals,
                   std::array<std::uint8_t, ANIMALS> &icons);

void race(const std::array<std::array<std::uint8_t, MAX>, ANIMALS> &animals);

std::uint8_t currentPos(const std::array<std::uint8_t, MAX> &animal,
                        const char &ICON_ANIMAL);

std::uint8_t lucky(const uint8_t &random);

void movement(std::array<std::uint8_t, MAX> &animal,
              const std::uint8_t &pos, const uint8_t &steps,
              const char &ICON_ANIMAL);

#endif // UTILITIES_H
