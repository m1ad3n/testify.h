#ifndef __TESTIFY_H
#define __TESTIFY_H

#include <iostream>
#include <vector>
#include <functional>

#ifdef _WIN64
  #include <Windows.h>

  #define PASS_SYMBOL (char)251
  #define FAIL_SYMBOL 'x'
#endif

#ifdef __linux__
  #define PASS_SYMBOL "\u2714"
  #define FAIL_SYMBOL "\u2718"

  #define RESET_COLOR "\033[0m"
  #define GREEN_COLOR "\033[32m"
  #define RED_COLOR "\033[31m"
#endif

#define TAB "  "

#define add_test(function) tests.push_back(Test(function, #function))
#define sumarize() __sumarize()
#define assert(got, wanted) return got == wanted ? true : false

typedef struct Test {
  std::function<bool()> test_function;
  std::string test_name;
  bool passed;

  Test(std::function<bool()> func, std::string func_name)
  {
    this->test_function = func;
    this->test_name = func_name;
    this->passed = false;
  }

  void run()
  {
    this->passed = this->test_function();
    if (this->passed)
    {
      #ifdef __linux__
        std::cout << GREEN_COLOR << PASS_SYMBOL << " " << this->test_name << std::endl;
      #endif
      #ifdef _WIN64
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
        std::cout << PASS_SYMBOL << " " << this->test_name << std::endl;
      #endif
    }
    else
    {
        #ifdef __linux__
          std::cout << RED_COLOR << FAIL_SYMBOL << " " << this->test_name << std::endl;
        #endif
        #ifdef _WIN64
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
          std::cout << FAIL_SYMBOL << " " << this->test_name << std::endl;
        #endif
    }
    #ifdef __linux__
        std::cout << RESET_COLOR;
    #endif
    #ifdef _WIN64
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    #endif
  }

} Test;

static std::vector<Test> tests;
static void __sumarize()
{
  unsigned short passed = 0, failed = 0;
  for (auto te : tests)
  {  
    te.run();
    if (te.passed) passed++;
    else failed++;
  }

  std::cout << std::endl << tests.size() << " completed test\n" << TAB <<
    passed << " test passed\n" << TAB << failed << " test failed" << std::endl;
}

#endif
