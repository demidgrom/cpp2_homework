#include "entity.hpp"

int main()
{
    Client a;

    Entity_v1 *b = &a;

    b->test_v1();
}