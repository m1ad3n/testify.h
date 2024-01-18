# testify.h - Lightweight C++ Testing Framework

## Overview

`testify.h` is a simple C++ header file providing a lightweight testing framework for writing and running tests in C++ projects. It includes functionality for defining and running tests, as well as asserting test conditions.

## Features

- Easy test definition using the `add_test` macro.
- Assertion support through the `assert` macro.
- Cross-platform colorized output for test results.
- Symbolic representation of pass and fail status.

## Usage

### Test Definition

Tests are defined using the `add_test` macro, which takes a test function as an argument. For example:

```cpp
add_test(my_test_function);
```

This will create a test instance with the given function and run it.

### Assertions

Assertions are made using the assert macro, comparing the actual result (got) with the expected result (wanted). For example:

```cpp
assert(my_value, 42);
```

This will return true if my_value is equal to 42, otherwise, it returns false.

## Platform-Specific Notes
### Linux

- Text color is utilized for test result visualization.
- Green color represents a passing test.
- Red color represents a failing test.

### Windows

- Console text attributes are used for colorizing text.
- Green text represents a passing test.
- Red text represents a failing test.

## Example

```cpp
#include "testify.h"

bool my_test_function() {
    // Your test logic here
    assert(result, wanted_result);
    
    // or you can return the value
    // return true;
}

int main() {
    add_test(my_test_function);
    return 0;
}
```