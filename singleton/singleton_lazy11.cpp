#include <iostream>

using namespace std;

/// 懒汉模式 C++11

class Singleton {
private:
    Singleton() { x = 3; }

public:

    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

    /// 返回引用最好，返回指针可能被人调用delete
    static Singleton &getIns();

    int x;
};

/**
 * C++11保证了局部静态变量是线程安全的
 *
 */
Singleton &Singleton::getIns() {
    static Singleton ins;
    return ins;
}


int main() {
    /// 不管析构函数是private还是public，都不会释放new得到的内存Singleton

    Singleton &ins = Singleton::getIns();
    cout << "x=" << ins.x << endl;
//    Singleton ins2;           // 构造为private
//    Singleton ins3 = ins;    // 拷贝构造被delete
    return 0;
}
