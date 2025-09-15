#include <string>

class Figure {
public:
    Figure();
    void const AddBodyPart();
    void const Display();
	int const GetBodyParts() { return body_parts; };
private:
    int body_parts;
};