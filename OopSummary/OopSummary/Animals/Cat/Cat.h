﻿#pragma once

#ifndef CAT_H
#define CAT_H

#include "../Animal.h"

class Cat: public Animal
{
public:
  void makeSound() const override;
  
};

#endif