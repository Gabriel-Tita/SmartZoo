#ifndef OOP_TRATAMENT_HPP
#define OOP_TRATAMENT_HPP

#include <iosfwd>

class Treatment {
public:
    virtual ~Treatment() = default;
    virtual void applyTreatment(ostream& os) const = 0;
};

#endif //OOP_TRATAMENT_HPP
