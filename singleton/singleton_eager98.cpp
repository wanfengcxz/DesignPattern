//
// Created by wanfengcxz on 2024/6/11.
//
#include <iostream>

using namespace std;

/// 懒汉模式 C++98

class Singleton {
private:
    Singleton() { x = 3; }

    Singleton(const Singleton &);

    Singleton &operator=(const Singleton &);

    static Singleton ins;

public:
    static Singleton &getIns();

    int x;
};

Singleton &Singleton::getIns() {
    return ins;
}

/// y的值和这两行前后顺序（即初始化顺序）有关
// x=3 y=0
static int y = Singleton::getIns().x;
Singleton Singleton::ins;

// x=3 y=3
//Singleton Singleton::ins;
//static int y = Singleton::getIns().x;


int main() {
    /// 不管析构函数是private还是public，都不会释放new得到的内存Singleton

    Singleton &ins = Singleton::getIns();
    cout << "x=" << ins.x << endl;
    cout << "y=" << y << endl;
//    Singleton ins2;           // 构造为private
//    Singleton ins3 = ins;    // 拷贝构造为private

    return 0;
}
