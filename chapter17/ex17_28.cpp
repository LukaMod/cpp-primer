#include <random>
#include <iostream>

using namespace std;

unsigned rand_generator();

unsigned rand_generator(unsigned);

unsigned rand_generator(unsigned, unsigned, unsigned);

int main()
{
    cout << rand_generator() << endl;
    cout << rand_generator(7) << endl;
    cout << rand_generator(93, 7, 14) << endl;

    return 0;
}

unsigned rand_generator()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u;
    return u(e);
}

unsigned rand_generator(unsigned seed)
{
    default_random_engine e(seed);
    uniform_int_distribution<unsigned> u;
    return u(e);
}

unsigned rand_generator(unsigned seed, unsigned min, unsigned max)
{
    default_random_engine e(seed);
    uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}
