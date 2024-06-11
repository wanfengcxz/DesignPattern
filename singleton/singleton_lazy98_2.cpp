#include <iostream>

using namespace std;

/// 懒汉模式 C++98

class Singleton {
private:
    Singleton() { x = 3; }

    ~Singleton();

    static Singleton *ins;

    class Deletor {
    public:
        ~Deletor() {
            cout << "delete Singleton" << endl;
            if (Singleton::ins != NULL) {
                delete Singleton::ins;
            }
        }
    };

    static Deletor deletor;

public:
    static Singleton *getIns();

    static void deleteIns();

    int x;
};

/// 类外初始化
Singleton *Singleton::ins = NULL;

Singleton::~Singleton() {
    cout << "delete Singleton" << endl;
}

Singleton *Singleton::getIns() {
    if (ins == NULL) {
        ins = new Singleton;
    }
    return ins;
}

void Singleton::deleteIns() {
    if (ins != NULL) {
        delete ins;
        ins = NULL;
    }
}


int main() {

    Singleton *ins = Singleton::getIns();
    cout << "x=" << ins->x << endl;
//    Singleton ins2 = *ins;    // 析构函数为private 还是无法拷贝 因为拷贝完无法释放
    //    delete ins;
    /// 可以手动释放ins指向的内存，但是可能会被某个线程提前释放掉 又得重新new
    /// 将析构函数声明为private，就可以避免别人随便delete
    /// 此时需要提供特定的静态成员函数/友元函数来释放。或者使用嵌套类。
    Singleton::deleteIns();
    Singleton::deleteIns();

    /// 使用嵌套类来释放内存的行为发生在main之外了，main函数结束之后析构静态变量。

    return 0;
}
