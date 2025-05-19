#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base* generate() {
    std::srand(std::time(0));
    int r = std::rand() % 3;
    if (r == 0) return new A;
    if (r == 1) return new B;
    return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
		std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p) {
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A\n";
        return;
    }
	catch (std::exception& e){
		std::cout << "Convertion A is not OK : " << e.what() << "\n";
	}
    try {
        static_cast<void>(dynamic_cast<B&>(p));
        std::cout << "B\n";
        return;
    }
	catch (std::exception& e){
		std::cout << "Convertion B is not OK : " << e.what() << "\n";
	}
    try {
        static_cast<void>(dynamic_cast<C&>(p));
        std::cout << "C\n";
        return;
    }
	catch (std::exception& e){
		std::cout << "Convertion C is not OK : " << e.what() << "\n";
	}
}

int main() {
    Base* obj = generate();
	std::cout << "Check with pointer: \n";
    identify(obj);
	std::cout << "Check with reference: \n";
    identify(*obj);
    delete obj;
    return 0;
}

//rtti activ with one virtual method
