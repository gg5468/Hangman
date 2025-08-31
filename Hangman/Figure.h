#include <string>

class Figure {
public:
    Figure();
    void AddBodyPart();
    void Display();
	int GetBodyParts() { return body_parts; };
private:
    int body_parts;
};