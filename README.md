# Irog Static Analyzer 

A CLI utility written in C++ which does static code analysis 

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Introduction

This utility was written by me in order to get more familiar with how C++ static file analysis is done.

Used [this](https://itnext.io/how-to-create-a-c-c-static-code-analysis-tool-3247f9341a43) blogpost as guidance for writing the project, but I intend to add more rules as practice. This is just the initial stage of the project.
Also [this book](https://www.amazon.com/Getting-Started-LLVM-Core-Libraries/dp/1782166920) was a good reference.

Todo:
 - Add more rules, make the tool more versatile and configurable like clang-tidy

## Features

- Read a `.cpp` or `.hpp` file and based on the predefined rules from the program, output if there are any errors. 

## Installation

Prerequisites:

You might need to install `clang`, `llvm` and `libclang-dev`
```bash
sudo apt-get install clang
sudo apt-get install llvm
sudo apt-get install libclang-dev
```

In order to compile the program you run the following commands from the project's root folder:

```bash
cmake -S . -B build
cmake --build build
```

Once you've run these commands, you can find the executable in:
```bash
./build/irog-static-analyzer
```

## Usage

```bash
irog-static-analyzer <file name>
```

## License

Specify the project's license. Choose an appropriate open-source license that suits your project's needs.

