#include <iostream>

class Test {
    private:
        int x;
        int y;
        static int hell;
    public:
        Test() {
            hell = 6;
            x = 0;
            y = 5;
        }
        int get_value() {
            return (x);
        }
        void set_value (int value) {
            x = value;
        }
        static int  hell_yeah(int value) {
            hell = value;
            return (hell);
        }
};

int main (){
    Test hel;
    std::cout << hel.hell_yeah(20);
    std::cout << Test::hell_yeah(10);
}