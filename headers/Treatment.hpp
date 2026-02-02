#ifndef OOP_TRATAMENT_HPP
#define OOP_TRATAMENT_HPP

#include <iosfwd>

/**
 * @class Treatment
 * @brief Interface for animals that can receive a treatment.
 *
 * Classes that implement this interface must define applyTreatment().
 */
class Treatment {
public:
    /** @brief Virtual destructor. */
    virtual ~Treatment() = default;

    /**
     * @brief Applies a treatment and writes details to a stream.
     * @param os Output stream used to print the treatment steps.
     */
    virtual void applyTreatment(ostream &os) const = 0;
};

#endif //OOP_TRATAMENT_HPP
