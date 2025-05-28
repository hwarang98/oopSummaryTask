#include <iostream>
#include <array>
#include "Animals/Animal.h"
#include "./Animals/Dog/Dog.h"
#include "./Animals/Cat/Cat.h"
#include "./Animals/Cow/Cow.h"
#include "Animals/Zoo/Zoo.h"

int main()
{
  array<Animal*, 3> animals;

  // 동물 객체 생성
  Dog dog;
  Cat cat;
  Cow cow;
  Zoo zoo;

  // 배열에 포인터 저장
  animals[0] = &dog;
  animals[1] = &cat;
  animals[2] = &cow;

  // 동물 추가
  zoo.addAnimal(std::shared_ptr<Animal>(new Dog));
  zoo.addAnimal(std::shared_ptr<Animal>(new Cat));
  zoo.addAnimal(std::shared_ptr<Animal>(new Cow));

  zoo.performActions();
  Animal* randomAnimal = zoo.createRandomAnimal();

  if (randomAnimal != nullptr)
  {
    cout << "random animal sound: ";
    randomAnimal->makeSound();  // 동물 소리 출력 (Animal 클래스 내 가상 함수)
    cout << "\n";
  }
  
  return 0;
}
