#include "Array.hpp"
#include <iostream>
#include <string>

int main(void)
{
    Array<int> empty;
    std::cout << "empty size: " << empty.size() << std::endl;

    Array<int> nums(5);
    std::cout << "nums size: " << nums.size() << ", nums[0]: " << nums[0] << std::endl;

    for (unsigned int i = 0; i < nums.size(); i++)
        nums[i] = i * 10;

    Array<int> copy(nums);
    nums[0] = 999;
    std::cout << "nums[0]=" << nums[0] << "  copy[0]=" << copy[0] << std::endl;

    Array<int> assigned(2);
    assigned = nums;
    nums[1] = 888;
    std::cout << "nums[1]=" << nums[1] << "  assigned[1]=" << assigned[1] << std::endl;

    try {
        std::cout << nums[42] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    const Array<int> frozen(nums);
    std::cout << "const read: " << frozen[2] << std::endl;

    Array<std::string> words(2);
    words[0] = "hello";
    words[1] = "world";
    std::cout << words[0] << " " << words[1] << std::endl;

    return 0;
}