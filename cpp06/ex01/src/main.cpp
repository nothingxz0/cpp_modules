#include <iostream>
#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data *data = new Data();
    data->name = "Soufiane";
    data->value = 1337;

    uintptr_t raw = Serializer::serialize(data);
    Data *deserialized = Serializer::deserialize(raw);

    std::cout << "Original: " << data << std::endl;
    std::cout << "Serialized as uintptr_t: " << raw << std::endl;
    std::cout << "Deserialized: " << deserialized << std::endl;

    if (data == deserialized) {
        std::cout << "Successful!" << std::endl;
        std::cout << "Name: " << deserialized->name << ", Value: " << deserialized->value << std::endl;
    }
    else
        std::cout << "Failed!" << std::endl;

    delete data;
    return 0;
}