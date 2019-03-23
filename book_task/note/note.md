## TODO

第7章习题

A -> 65
a -> 97

---

## 1. 简介

### 1.1 笔记

c++系统组成：                                                程序开发环境 语言 c++标准库
c++经历6阶段：                                               编辑，预处理，编译，连接，载入，执行
c++后缀名：                                                  cpp，cxx，cc，C

### 1.2 填空习题

6个主要逻辑单元：                                              输入单元 输出单元 内存单元 算数逻辑单元 中央处理器单元 辅助存储单元
在编译器翻译阶段开始执行的程序                                   预处理器
将编译器输出和库函数结合                                        连接器
将可执行程序从磁盘到内存                                        载入器
从面向对象的观点出发分析和设计系统的过程                          面向对象的分析和设计(OOAD)

---

## 2. c++编程入门

### 2.1 笔记

变量命令规范                                                  不以数字开头，由数组，字符，下划线组成 
为了可移植性，变量命名的最大长度                                 31

### 2.2 填空习题

每个函数体的启止处                                              左，右花括号
`%`是否只能和整数一起使用？                                      T
  
---

## 3. 类和对象介绍

### 3.1 笔记

类定义末尾是否需要加分号                                        T
形参(parameter)，实参(argument)区别                            函数定义时使用的参数；传入函数的参数          
如何获取一整行用户输入                                          std::getline(std::cin, std::string)
UML函数形参声明                                                同Golang的声明方式
UML构造函数的声明                                              `<<constructor>> T(name : String)`
get，set方法的别称                                             accessor访问器，mutator更换器
预处理命令include的`<>` `""` 区别                               前者现在标准库中寻找，后者先在用户的工作目录下寻找
函数原型中的参数名是否为可选的                                    T
接口(.h)和实现(.cpp)对程序的影响                                 不影响使用，仅影响编译和连接 

### 3.2 填空习题

类的对象维护它自己的属性副本时，表示属性的变量被认为是：              数据成员
关键词public是                                                  成员访问说明符      
`::`                                                           （一）二元作用域分辨运算符 

---

## 4. 控制语句（一）

### 4.1 笔记

三种控制结构                                                      顺序，选择，循环
UML活动图 开始，结束，注释，判断                                    实心圆，白边实心圆，右上角折过来的矩形(虚线连接)，菱形
static_cast, dynamic_cast                                        在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；
                                                                 在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全。
                                                                 dynamic_cast还支持交叉转换（cross cast）
未初始化的int类型变量值为                                           32766

### 4.2 填空习题

一组指令重复执行指定次数的循环称为                                   定数的循环
事先不知道循环的次数，可以用一个__结束循环                            标记、信号、标志、哑元

---

### 4.3 编程习题

如何用一行语句获取int的位数                                         (int)std::log10((double)binary) + 1;
尽量复用数据
++(x + y) 是否正确                                                 F

---

## 5. 控制语句（二）

### 5.1 笔记

for语句执行顺序                                                      `I --> II --> (...) --> III --> II .....`
输出char类型时的类型转换                                              static_cast<char>var
switch使用的变量                                                     int，char，short，long（常整数），或const型的int

### 5.2 填空习题

使用 setprecison 是否会进行四舍五入运算                                 333.546372 --> 333.55   std::pow(2.5, 3) --> 15.62
default中是否要使用break                                               F
是否能用浮点数控制循环                                                  F

### 5.3 编程习题

static_cast<> 和运算符优先级比较                                       优先级仅比后置运算符低
`<<>>`和逻辑运算符优先级比较                                            优先级仅比`!`低 
十进制转二进制思路                                                     和同位数的二的阶乘比较大小 

---

## 6 函数和递归入门

### 6.1 笔记

函数签名                                                       函数名和实参类型部分(按顺序)
数据类型层次                                                    long double > double > float
                                                              > unsigned long int > long int
                                                              > unsigned int > int
                                                              > unsigned short int > short int
                                                              > unsigned char > char > bool
常用标准库                                                      p200
生成整形随机数的公式                                             起始位置+rand() % 整数的范围
五种存贮类别说明符                                               auto       根据初始化表达式自动推断被声明的变量的类型
                                                               register   定义存储在寄存器中，且不能对它应用一元的 '&' 运算符；局部变量和形参
                                                               extern     用于提供一个全局变量的引用
                                                               mutable    它允许对象的成员替代常量
                                                               static     修饰局部变量可以在函数调用之间保持局部变量的值；全局的话作用域在单个文件中
如果可靠地使用全局变量                                             ::var
编译器对名称的更改                                                 int square(int x) --> __Z6squarei
                                                                 void nothing2(char a, float &c) --> __Z8nothing2cRf

---

### 6.2 填空习题

C++中的程序组件被成为                                                类 函数
函数用__来调用                                                      函数调用
标识符的__指它在程序中可使用的部分                                     作用域
从被调用函数中返回控制权的三种方法                                     return;  return表达式   函数右花括号     
__允许编译器检查函数传实参的个数，顺序，类型                            函数原型
标识符6种可能作用域                                                  语句块，函数，函数原型，文件，类，namespace 

---

### 6.3 编程习题

`std::fabs(0.0)` 结果                                               0
使用std::floor对数据进行舍入运算                                      std::floor(x * 舍入精度 + .5) / 舍入精度
std::rand()的原理                                                   线性同余法；生成0-RAND_MAX中一个无符号整数；伪随机数，默认的时间种子固定
std::srand((unsigned)time(0))                                      读取自己的时钟来获取种子的值；1970年起始的秒数      
如何快速找出所有数字的因子                                            写一个循环，但是到这数字的1/2就可以终止了   
求一个数是否为素数                                                    循环只需要到平方根就可以了
数字反向输出                                                         cpt_6/cpt_6_q_30.h 
汉诺塔（递归，非递归实现）                                             cpt_6/cpt_6_q_38_39.h

---

## 7 数组与vector

### 7.1 笔记

如何对 `=`，`[]`进行重载                                                `T &operator[](int idx)`  `MyArr &operator=(const MyArr &otherArr)`

---

### 7.2 填空习题

数组中的元素是相关的，因为它们有相同的____和____                            名字和类型

---

### 7.3 编程习题 (有几个大坑)

一行语句将数组全部加1                                                     `std::for_each(std::begin(arr), std::end(arr), [](int &i) { i += 1; });`

---

## 8 指针

### 8.1 笔记

`*`运算符的别称                                                           间接运算符/间接引用(dereference)运算符
C++三种传参方式                                                           值，引用，指针
四种指针                                                                  指向非常量的非常量指针
                                                                         指向常量的非常量指针
                                                                         指向非常量的常量指针
                                                                         指向常量的常量指针 （指针命名从右向左读）   
在函数中使用`sizeof`获取数组参数是否正确                                     错误，得到的是指针的大小   
`sizeof`是什么阶段的运算符                                                  编译时，编译器就会将其换为常量
数组名也是指针，它的类型是__                                                 常量指针，执行`arr+=1`会报错
引用数组元素的四种表示方法                                                   数组名下标           `b[i]`
                                                                          数组名作为指针偏移量   `*(b+i)`
                                                                          指针下标              `bPtr[i]`  `int *bPtr = b`
                                                                          指针偏移量             `*(bPtr+i)`    
请填写并理解下面的结果

```cpp
    const char str[] = "01234567";
    // 9
    std::cout << sizeof(str) << std::endl;
    // 8
    std::cout << strlen(str) << std::endl;

    const char *str2 = "01234567";
    // 8
    std::cout << sizeof(str2) << std::endl;
    // 8
    std::cout << strlen(str2) << std::endl;

    const char str3[20] = "01234567";
    // 20
    std::cout << sizeof(str3) << std::endl;
    // 8
    std::cout << strlen(str3) << std::endl;

    const char str4[] = {"01234567"};
    // 9
    std::cout << sizeof(str4) << std::endl;
    // 8
    std::cout << strlen(str4) << std::endl;

    const char *str5 = {"01234567"};
    // 8
    std::cout << sizeof(str5) << std::endl;
    // 8
    std::cout << strlen(str5) << std::endl;

    const char str6[] = {'0', '1', '2', '3', '4', '5', '6', '7'};
    // 8
    std::cout << sizeof(str6) << std::endl;
    // 16
    std::cout << strlen(str6) << std::endl;
```

如何控制用户输入字符的长度                                                   使用std::setw，
                                                                          或 cin.getline(chars,n,'\n')会自动扩容，包含'\0'
---

### 8.2 填空习题

关于`void*`注意事项                                                         void指针不能被间接引用，没有特定类型，
                                                                           void指针只有在类型转换后才能赋给其他指针
                                                                           编译器不能确认间接引用的内存字节数和该指针指向的数据类型  
                                                                           类型转换：otherPtr = *static_cast<int*>(sPtr)

数组名称不能进行运算
函数指针不带变量名

---

## 9 类的深入剖析（第一部分）

### 9.1 笔记


自己编写array

```cpp
template<typename T>
class MyArr {
public:
    explicit MyArr(int capacity) : capacity(capacity), size(0) {
        this->arr = new T(capacity);
    }

    template<class>
    class Ref {
    public:
        Ref(MyArr<T> *myArr, int idx) : myArr(myArr), idx(idx) {}

        // 这是赋值方法
        Ref &operator=(T value) {
            if (this->myArr->size >= this->myArr->capacity - 1) {
                std::ostringstream ostr;
                throw std::out_of_range("数组越界");
            }
            this->myArr->arr[this->idx] = value;
            this->myArr->size++;
            return *this;
        }

        // 这是取值方法
        operator T() const {
            if (this->myArr->size < this->idx) {
                std::ostringstream ostr;
                ostr << "数组越界！" << "当前最大下标：" << this->myArr->size << " ,取值下标：" << this->idx << std::endl;
                throw std::out_of_range(ostr.str());
            }
            return this->myArr->arr[this->idx];
        }

    private:
        MyArr<T> *myArr;
        int idx;
    };

    Ref<T> operator[](int idx) {
        return Ref<T>(this, idx);
    }

    friend std::ostream &operator<<(std::ostream &os, const MyArr &arr) {
        for (int i = 0; i < arr.capacity; i++) {
            os << arr.arr[i] << " ";
        }
        os << std::endl;
        return os;
    }

    ~MyArr() {
        delete[] this->arr;
    }

private:
    T *arr;
    int size;
    int capacity;
}
```

---

## 10 类的深入剖析（第二部分）

### 10.1 笔记

对const对象，C++编译器不允许进行成员函数调用，除非成员函数也是const
使用成员初始化器初始化const成员（总：成员初始化列表），无法在构造函数中赋值且其必须初始化

友元函数：编写函数原型是声明为friend类型，便于全局运算符重载

this作为一个隐式参数传递给对象的每一个非static函数成员
this 指针常量 --> 根据对象是否为const --> 是否为常量指针

初始化static变量(仅一次) --> int Class::Static = 0;

---

### 10.2 填空习题

___数据成员表示的是每个类范围的信息                                                                            static
如果没有为类的对象成员提供初始化器，则该对象的___被调用                                                           默认构造函数
如果成员函数不访问____类成员，则它应该被声明为static                                                             非static
成员对象在包含它们的类___构造                                                                                  之前

---

### 10.3 编程习题

是否重复 `T(data=2){}   T(){}`                                                                                 是的

---

## 11 运算符重载

### 11.1 笔记

运算符重载通过___和___函数实现                                                                                  非static成员函数或全局函数
对类，不用重载的运算符为__,__,__                                                                               `=`, `.`, `&`
不可以重载的运算符为__,__,__,__                                                                                `.`, `.*`, `::`, `?:` 
重载运算符何时作为全局/局部函数？                                                                                根据左操作数的类型
何为**虚悬指针**                                                                                               两个指针指向同一片动态内存区域，A释放了空间，则B指向为空
如何阻止类的一个对象赋值给另一个对象                                                                              将重载的`=`声明为`private`
如何阻止类对象的复制                                                                                            将重载的`=`和复制构造函数声明为`private`
重载时进行类型转换                                                                                              `A::operator char*() const`，遇到`statc_cast<char*>(s)`时调用 
如果重载前/后缀运算符                                                                                           前`T &operator++(T&)` 后 `T &operator(T&, 0)`
何为**转换构造函数**                                                                                            能把其他类型的对象(包括基本类型)转换成特定类对象的单参数构造函数
对于___必须作为成员函数进行重载                                                                                   赋值运算符`()` `[]` `->`

---

### 11.2 填空习题

重载运算符并不能改变运算符的__,__,__                                                                              优先级，结合律，元数
比较 `new`,`new[]`,`delete`,`delete[]`之间的异同                                                                https://blog.csdn.net/zyazky/article/details/52627200
                                                                                                                带`[]`会额外分配一段内存空间记录长度  
---

## 12 继承

### 12.2 填空习题

单继承中，基类与其派生类之间是一种___关系                                                                            层次 

---

## 13 多态

### 13.1 笔记

何为**纯指示符**                                                                                                  `virtual void draw() const = 0;` 0为**纯指示符**
**typeid**                                                                                                       运行时获取变量的名称 https://blog.csdn.net/gatieme/article/details/50947821
使用多态特性时，虚基类需要声明虚析构函数
构造函数是否能为virtual                                                                                             F

---

### 13.2 填空习题

把基类对象当做是___是错误的                                                                                          派生类对象
如果一个类至少包含一个纯virtual函数，那么该类为___类                                                                    抽象类
如果一个类可以实例化对象，那么该类为___类                                                                              具体类
___需要使用一个基类指针或引用来调用基类和派生类对象的virtual函数                                                          多态
将基类指针强制类型转换为派生类指针称为____                                                                              向下强制类型转换     
请比较一个动态绑定和静态绑定                                                                                          **对象的静态类型**：对象在声明时采用的类型。是在编译期确定的。
                                                                                                                   **对象的动态类型**：目前所指对象的类型。是在运行期决定的。对象的动态类型可以更改，但是静态类型无法更改
                                                                                                                   **静态绑定**：绑定的是对象的静态类型，某特性（比如函数）依赖于对象的静态类型，发生在编译期。
                                                                                                                   **动态绑定**：绑定的是对象的动态类型，某特性（比如函数）依赖于对象的动态类型，发生在运行期。

---

## 14 模板

### 14.1 笔记

函数模板和宏的区别                                                                                                   都能实现软件复用，但是前者通过完整的C++检测消除了许多类型的错误
模板格式                                                                                                            `template< typename T >` `teamplate< class ElementType >`
编译时模板会生成不同的副本(特化)，会占用内存
类模板也被称为____                                                                                                    参数化类型

---

### 14.2 填空习题

函数模板定义的模板参数是用来说明___,___及___                                                                             函数参数类型，函数返回值类型以及声明函数的变量类型
任何在类模板外定义的成员函数必须以模板头作为开头
请解释何为 **函数模板特化**，**类模板特化**                                                                              模板只需用一个单独的代码段表示一整套的相关的函数(类)
类模板也称为____类型                                                                                                   参数化类型
____运算符和类模板名一起将成员函数定义限定在类模板范围内                                                                    二元作用域分辨  
尽可能使静态成员在___范围内初始化                                                                                        文件      
比较：**函数模板** **函数模板特化**；**类模板** **类模板特化**                                                             (见第一次笔记)https://blog.csdn.net/thefutureisour/article/details/7964682       
函数模板和重载之间的关系                                                                                                 函数特化可以防止隐式转换

---

## 15 输入/输入流

### 15.1 笔记

如何输出 `char*` 的地址                                                                                   `static_cast<void*>(const char *const var)`
`setw`,`cin.width` 只生效一次
如何获取格式的初始值                                                                                       `std::ios_base::fmtflags`  `cout.flags()`

---

### 15.2 填空习题

可以设置和重置格式状态的函数是___                                                                           `flags`
ostream成员函数___用于实现非格式化的输出                                                                     `write` 
类___支持输入操作                                                                                          `istream`
类___支持输出操作                                                                                          `ostream`
流操作符___ ____ ____ 分别以八进制，十六进制，十进制输出
使用流操纵符____要求正整数显示加号                                                                            `showpos`
默认情况下，内存地址以____显示

从输入流中忽略6个字符                                                                                         `std::cin.ignore(6)`  
不移除分隔符/移除分隔符                                                                                        `get`, `getline`
获取当前精度                                                                                                  `cout.precision()`
改变基数                                                                                                      `std::.setbase()`      

---

## 16 异常处理

### 16.1 笔记

意料之外的异常产生的原因                                                                                        对于抛出的异常，找不到相应的catch块
                                                                                                             析构函数试图在堆栈展开时抛出异常  
                                                                                                             在没有异常要处理时试图重新抛出异常
                                                                                                             调用函数unexpected将默认调用函数terminate
`abort` 和 `exit` 区别                                                                                        `exit`正常退出，`abort` --> `SIGABRT` 可能不会释放部分资源
处理 `bad_alloc` 使用到的函数                                                                                   `set_new_handler`
```txt
└── exception
    ├── bad_alloc
    ├── bad_cast
    ├── bad_exception
    ├── bad_type_id
    ├── logic_error
    │   ├── invalid_argument
    │   ├── length_error
    │   └── out_of_range
    └── runtime_error
        ├── overflow_error
        └── underflow_error
``` 

---

## 17 文件处理

### 17.1 笔记

层次结构：位 字节 字段 记录 文件
如何对指针进行强制转换                                                                                         `reinterpret_cast` 在编译阶段完成
几种打开文件的形式
    - ios::app
    - ios::ate
    - ios::in
    - ios::out 
    - ios::trunc (ios::out的默认设置)
    - ios::binary
```txt
basic_ios  <-- basic_istream <-- basic_ifstream
                             <-- basic_iostream <-- basic_fstream 
           <-- basic_ostream <-- basic_ofstream
                             <-- basic_iostream <-- basic_fstream   
```

---

## 18 string处理

### 18.1 笔记

**pragma** tells the compiler to do stuff. Here are a couple of ways I use it:

```cpp
typedef basic_string<char, char_traits<char>, allocator<char> > string;
typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstring;
```

字符串是否以`\0`结尾

1. **`const char*`** 字符串 以 “\0”结尾。

2. **`char[]`** 字符串 以 “\0”结尾。

3. **`string`** 字符串 不以 “\0”结尾。

4. **`char[n]`** = "string", 当string 长度+“\0”>n时，会因空间不足出错。

5. **`string.c_str()`** 转 const char* 时， 会在字符串末尾 自动补“\0”

6. **`char*`** 转string 时， 会自动把末尾的 “\0” 去掉。

7. **`strlen()`** 是取字符串除去结尾符 “\0” 的长度。
