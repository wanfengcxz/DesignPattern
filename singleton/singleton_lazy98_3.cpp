#include <iostream>

using namespace std;

/// 懒汉模式 C++98

class Singleton {
private:
    Singleton() { x = 3; }

    ~Singleton();

    static Singleton *ins;

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

Singleton *Singleton::getIns(){
    // https://www.drdobbs.com/cpp/c-and-the-perils-of-double-checked-locki/184405726
    /**
    Step 1. Allocate memory to hold a object.Singleton
    Step 2. Construct a object in the allocated memory.Singleton
    Step 3. Make point to the allocated memory.pInstance

    Singleton* Singleton::instance() {
       if (pInstance == 0) {
          Lock lock;
          if (pInstance == 0) {
             pInstance = // Step 3
                operator new(sizeof(Singleton)); // Step 1
             new (pInstance) Singleton; // Step 2
          }
       }
       return pInstance;
    }
    */
    /// DCL双检测锁 但是多线程不安全 存在编译器指令重排问题
    if (ins == NULL) {
//        Lock lock;
        if (ins == NULL) {
            ins = new Singleton;
        }
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
    Singleton::deleteIns();


    return 0;
}
