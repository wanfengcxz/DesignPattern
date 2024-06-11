#include <iostream>

using namespace std;

/// 懒汉模式 C++98

class Singleton {
private:
    Singleton() { x = 3; }

    Singleton(const Singleton &);

    Singleton &operator=(const Singleton &);

    static Singleton *ins;
public:
    static Singleton *getIns();

    ~Singleton();

    int x;
};

/// 类外初始化
Singleton *Singleton::ins = NULL;

Singleton *Singleton::getIns() {
    if (ins == NULL) {
        ins = new Singleton();
    }
    return ins;
}

Singleton::~Singleton() {
    cout << "delete Singleton" << endl;
}

int main() {
    /// 不管析构函数是private还是public，都不会释放new得到的内存Singleton

    Singleton *ins = Singleton::getIns();
    cout << "x=" << ins->x << endl;
//    Singleton ins2;           // 构造为private
//    Singleton ins3 = *ins;    // 拷贝构造为private

    return 0;
}
