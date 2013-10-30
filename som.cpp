#include "som.h"
#include <cstdlib>
#include <fstream>

int main()
{
    typedef double type;
    const type lr_decay = 0.001;
    const type nbdw_decay = 0.001;
    const type lr = 0.1;
    const type nbdw = 2.0;
    
    std::ifstream file("data24.txt", std::ios::in);
    kohonen<type, 2, 4, 2> run1(file, lr_decay, nbdw_decay, lr, nbdw);
    file.close();
    file.open("data24.txt", std::ios::in);
    kohonen<type, 2, 4, 4> run2(file, lr_decay, nbdw_decay, lr, nbdw);
    file.close();
    file.open("data24.txt", std::ios::in);
    kohonen<type, 2, 2, 3> run3(file, lr_decay, nbdw_decay, lr, nbdw);
    file.close();
    file.open("data33.txt", std::ios::in);
    kohonen<type, 2, 4, 2> run4(file, lr_decay, nbdw_decay, lr, nbdw);
    file.close();
    file.open("data33.txt", std::ios::in);
    kohonen<type, 2, 1, 4> run5(file, lr_decay, nbdw_decay, lr, nbdw);
    file.close();
    
    run1.train(5000);
    run2.train(5000);
    run3.train(5000);
    run4.train(5000);
    run5.train(5000);
    
    run1.print();
    std::cout << std::endl;
    run2.print();
    std::cout << std::endl;
    run3.print();
    std::cout << std::endl;
    run4.print();
    std::cout << std::endl;
    run5.print();
    
    return EXIT_SUCCESS; // Even though this is C++, I still like to do this :)
}