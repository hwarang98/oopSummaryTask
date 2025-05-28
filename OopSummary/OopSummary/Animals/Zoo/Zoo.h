#pragma once

#ifndef ZOO_H
#define ZOO_H

#include "../Animal.h"
#include <array>

class Zoo {
private:
  std::array<std::shared_ptr<Animal>, 10> animals; // -> 스마트 포인터로 delete를 직접 호출 하지 않아도 된다.

public:
  Zoo();

  void addAnimal(std::shared_ptr<Animal> animal);
  void performActions();
  Animal* createRandomAnimal();  
};

#endif
