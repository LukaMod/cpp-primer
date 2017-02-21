#include <iostream>
int main()
{
    int sum = 0, val = 50;

    while (val <= 100)
    {
<<<<<<< HEAD
        sum += val;
        ++val;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;
=======
	sum += val;
	++val;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
	      << sum << std::endl;
>>>>>>> d3792854abc4fe658b3e38e81ecdb80f22456b53
    return 0;
}