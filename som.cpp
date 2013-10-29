#include "som.h"
#include <cstdlib>

int main()
{
    typedef double type;
    const type lr_decay = 0.001;
    const type nbdw_decay = 0.001;
    const type lr = 0.1;
    const type nbdw = 2.0;
    
    kohonen<tpye, 2, 4, 2> run1(std::cin, lr_decay, nbdw_decay, lr, nbdw);
    kohonen<type, 2, 4, 4> run2(std::cin, lr_decay, nbdw_decay, lr, nbdw);
    kohonen<type, 2, 2, 3> run3(std::cin, lr_decay, nbdw_decay, lr, nbdw);
    kohonen<type, 2, 4, 2> run4(std::cin, lr_decay, nbdw_decay, lr, nbdw);
    kohonen<type, 2, 1, 1> run5(std::cin, lr_decay, nbdw_decay, lr, nbdw);
    
    run1.train();
    run2.train();
    run3.train();
    run4.train();
    run5.train();
    
    std::cout << run1 << std::endl;
    std::cout << run2 << std::endl;
    std::cout << run3 << std::endl;
    std::cout << run4 << std::endl;
    std::cout << run5 << std::endl;
    
    return EXIT_SUCCESS; // Even though this is C++, I still like to do this :)
}