# SamplesHelper
This project will make creating samples for your library project easier.

To compile a sample from the `samples` directory write the `g++ -Isrc src/SampleName.cpp -o sample` command.

Inside of the `samples/math` directory there is a simple math library that shows an example of how to use `SamplesHelper.cmake` inside of your cmakelist file.

## How to use
1. Look at the `samples` directory and understand how to use it.
2. Include `SamplesHelper.cmake` to your cmake project.
3. Done.

## Platforms
Every platform that cmake supports.

## Tested on
- Static libraries
- Shared libraries
