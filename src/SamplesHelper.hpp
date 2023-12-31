// SamplesHelper - A project that will make creating samples easier.
//
// Copyright (C) 2023  vp817
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Test.hpp"
#include "Example.hpp"

#ifndef CREATE_TEST
#define CREATE_TEST(name, description, arg, list...)       \
    int main()                                             \
    {                                                      \
        auto argument = arg;                               \
        SamplesHelper::Test test(name, description, list); \
        test.start();                                      \
        return 0;                                          \
    }
#endif

#ifndef CREATE_EXAMPLE
#define CREATE_EXAMPLE(name, description, arg, function)             \
    int main()                                                       \
    {                                                                \
        auto argument = arg;                                         \
        SamplesHelper::Example example(name, description, function); \
        example.start();                                             \
        return 0;                                                    \
    }
#endif
