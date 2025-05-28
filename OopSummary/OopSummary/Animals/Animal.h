#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

// 추상 클래스 Animal
class Animal {
public:
  virtual void makeSound() const = 0; // 순수 가상 함수
  virtual ~Animal() = default;        // 가상 소멸자
};

#endif // ANIMAL_H
