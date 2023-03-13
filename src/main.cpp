/**
 ** This file is part of https://github.com/CM0use/Horse-Racing
 ** Copyright 2023 CM0use <dilanuzcs@gmail.com>.
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

# include <iostream>
# include <random>

# include "../header/utilities.h"

int main()
{
std::system("clear");
    using namespace std::chrono_literals;
    std::string repeat;
    do {
        std::array<std::array<std::uint8_t, MAX>, ANIMALS> animals;
        std::array<std::uint8_t, ANIMALS> icons;
        std::vector<std::uint8_t> winners;
        std::uint8_t pos, steps;
        bool condition{true};
        std::random_device rd{};
        std::mt19937 engine{ rd() };
        std::uniform_int_distribution<std::uint8_t> dist{1, 10};

        startSettings(animals, icons);

        std::puts("\nPRESS ENTER TO START THE RACE");
        race(animals);
        std::getchar();

        CLEAN_SCREEN;
        std::puts("BANG !!!!!\nAND THE'RE OF !!!!!");
        race(animals);
        std::this_thread::sleep_for(TIME+0.5s);

        while (condition) {
            CLEAN_SCREEN;
            std::puts("\n");
            race(animals);
            std::this_thread::sleep_for(TIME);

            for(std::uint8_t index{0}; auto &animal: animals) {
                pos = { currentPos(animal, icons[index]) };
                steps = { lucky(dist(engine)) };
                movement(animal, pos, steps, icons[index++]);
                if (animal[MAX-1] != ICON_FLOOR) {
                    winners.push_back(animal[MAX-1]);
                    condition = {false};
                }
            }
        }
        CLEAN_SCREEN;
        std::puts("\n");
        race(animals);

        (winners.size() == 1)? std::printf("WINNER: "):
                               std::printf("WINNERS: ");
        for(const auto &w: winners)
            printf("\'%c\' ", w);

        std::puts("\n\nDo you want to play again? [Y/y/S/s/n/N]");
        std::getline(std::cin, repeat);
        CLEAN_SCREEN;
    } while (std::tolower(repeat[0]) == 'y' || std::tolower(repeat[0]) == 's');

    return EXIT_SUCCESS;
}
