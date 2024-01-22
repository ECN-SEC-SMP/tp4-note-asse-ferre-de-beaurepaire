#include <iostream>
#include <string>
#include <vector>

class Constructible {
public:
    virtual ~Constructible() = default;
    virtual float surfaceconstructible() const = 0;
};