#include <iostream>
#include <string>

class B1 {
public:
    B1(int val) : b1(val) {}
    virtual ~B1() {}
    virtual void show() {
        std::cout << "Type: B1, Field: " << b1 << std::endl;
    }
private:
    int b1;
};

class B2 {
public:
    B2(int val) : b2(val) {}
    virtual ~B2() {}
    virtual void show() {
        std::cout << "Type: B2, Field: " << b2 << std::endl;
    }
private:
    int b2;
};

class D1 : public B1 {
public:
    D1(int b1_val, int d1_val) : B1(b1_val), d1(d1_val) {}
    ~D1() {}
    void show() override {
        B1::show();
        std::cout << "Type: D1, Field: " << d1 << std::endl;
    }
private:
    int d1;
};

class D2 : private B2 {
public:
    D2(int b2_val, int d2_val) : B2(b2_val), d2(d2_val) {}
    ~D2() {}
    void show() override {
        B2::show();
        std::cout << "Type: D2, Field: " << d2 << std::endl;
    }
private:
    int d2;
};

class D3 : private D1, public D2 {
public:
    D3(int b1, int d1, int b2, int d2, int d3) : D1(b1, d1), D2(b2, d2), d3(d3) {}
    ~D3() {}
    void show() override {
        D1::show();
        D2::show();
        std::cout << "Type: D3, Field: " << d3 << std::endl;
    }
private:
    int d3;
};

int main() {
    D3 d3(1, 2, 3, 4, 5);
    std::cout << "Size of D3: " << sizeof(d3) << std::endl;
    d3.show();
    return 0;
}
