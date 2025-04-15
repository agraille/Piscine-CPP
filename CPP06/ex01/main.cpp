#include "Serializer.hpp"

struct Data {
    int test;
    std::string name;
};

int main() {
    Data data = {42, "agraille"};

    std::cout << "Original pointer: " << &data << "\n";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized (uintptr_t): " << raw << "\n";

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << "\n";

    std::cout << "Data ID: " << ptr->test << ", Name: " << ptr->name << "\n";

    if (ptr == &data)
        std::cout << "Pointer match! Serialization works.\n";
    else
        std::cout << "Pointer mismatch! Something went wrong.\n";

    return 0;
}
