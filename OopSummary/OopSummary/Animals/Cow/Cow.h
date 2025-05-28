#pragma once

#ifndef COW_H
#define COW_H

#include "../Animal.h"

class Cow: public Animal
{
public:
  void makeSound() const override;
  
};

#endif