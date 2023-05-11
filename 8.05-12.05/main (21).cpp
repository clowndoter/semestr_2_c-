#include <iostream>
using namespace std;

class Tree {
public:
    virtual void draw() = 0;
};

class Tree1 : public Tree {
public:
    void draw() override {
        cout << "  /\\\n //\\\\\n";
    }
};

class Tree2 : public Tree {
public:
    void draw() override {
        cout << "  /\\\n /**\\\n";
    }
};

class Tree3 : public Tree {
public:
    void draw() override {
        cout << "  /\\\n /++\\\n";
    }
};

int main() {
    Tree* trees[3];
    trees[0] = new Tree1();
    trees[1] = new Tree2();
    trees[2] = new Tree3();
    for (int i = 0; i < 3; i++) {
        cout << "Drawing " << i + 1 << ":\n";
        trees[i]->draw();
    }
    return 0;
}