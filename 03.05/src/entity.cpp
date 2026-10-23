#include "entity.hpp"

int main() {
  Client client;

  Entity_v1& v1 = client;
  Entity_v2& v2 = client;

  v1.test();
  v2.test();
}