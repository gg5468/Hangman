#include <string>

class Figure {
public:
    Figure();
    void AddBodyPart();
    void Display() const;
	int GetBodyParts() const { return body_parts; };
private:
    int body_parts;
};