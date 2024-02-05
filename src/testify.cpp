#include "testify.h"
#include "mymath.h"

bool test_abs_math()
{
    int result = MyMath::abs(-3);
    assert(result, 3);
}

bool test_sqrt_math()
{
    double result = MyMath::sqrt(36);
    assert(result, 6);
}

int main(int argc, char** argv)
{
    add_test(test_abs_math);
    add_test(test_sqrt_math);
    sumarize();
}