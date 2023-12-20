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

#include <stdexcept>
#include <string>
#include <iostream>
#include "SamplesHelperBase.hpp"

namespace SamplesHelper
{

    class Example : public SamplesHelperBase
    {
    protected:
        std::function<void()> func;

    public:
        explicit Example(std::string name, std::string description, decltype(func) func)
            : SamplesHelperBase(name, description), func(func)
        {
        }

        void start()
        {
            std::cout << "Starting Example: \"" << this->name << ": " << this->description << "\"\n" << std::endl;
            this->func();
        }
    };
}
