#ifndef OOP_TRATAMENT_HPP
#define OOP_TRATAMENT_HPP

#pragma once
#include <iosfwd>

class Tratament {
public:
    virtual ~Tratament() = default;
    virtual void applyTreatment(ostream& os) = 0;
};

#endif //OOP_TRATAMENT_HPP