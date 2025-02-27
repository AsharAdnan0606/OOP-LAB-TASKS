#include <iostream>

using namespace std;

class Blend {
public:
    void blendJuice() {
        for (int i = 0; i < 4; i++) {
            cout << "Blending..." << endl;
        }
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding..." << endl;
        for (volatile int i = 0; i < 100000000; i++);
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;
public:
    void makeJuice() {
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready!" << endl;
    }
};

int main() {
    JuiceMaker jm;
    jm.makeJuice();
    return 0;
}

