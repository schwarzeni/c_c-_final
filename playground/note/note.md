## 函数后加const

https://stackoverflow.com/questions/751681/meaning-of-const-last-in-a-function-declaration-of-a-class
The const means that the method promises not to alter any members of the clas

## 虚函数

其到规范（接口）作用，继承时需要实现
允许用基类的指针来调用子类的这个函数

虚函数主要是用来实现多态和多重继承的
没有虚函数理论上也可以实现多态，但是太麻烦了，没有虚函数清晰
主要是在多态上使用。

当类中出现一个virtual指针时编译器就自动在类的成员变量里加入一个指针成员。
这个指针成员指向这个类的虚表指针。
当子类重写父类方法时
同时也是把继承自父类的虚表中对应函数的索引的函数指针从父类函数改成了自己的函数
这就造成了子类和父类对象里面的虚表内容不同。
所以动态联编时 去子类 或者父类里面找虚表，调用的函数不同。

### 纯虚函数

```cpp
virtual void draw() const = 0;
```

## 函数初始化优化

explicit Person(std::string name): name(std::move(name)) {}
explicit
std::move

## explicit
explicit用来防止由构造函数定义的隐式转换。

## 'std_move'
The first thing to note is that std::move() doesn't actually move anything.
It converts an expression from being an lvalue (such as a named variable) to being an xvalue.
An xvalue tells the compiler:

constructors, operator methods, standard-library-algorithm-like functions etc.
where objects get created and destroyed automagically a lot

## 拷贝构造函数

---

## 重载 struct << 运算符

```cpp
friend std::ostream &operator<<(std::ostream &os, const Shiyanlou &shiyanlou) {
    os << shiyanlou.description;
    return os;
}
```

---

## 迭代器

/Users/nizhenyang/my-project/back-end/c_c++/playground/task/task_2/quze1/quze1.h

---

## 随机数
[a,b) [0,4) rand() % 4
- 产生(a,b]的随机数，可以使用 (rand() % (b-a))+a+1;
- 通用公式：a+rand() % n;
- 其中：a为范围起始位置，n为整数的范围

```cpp
srand((unsigned)time(NULL))
rand()...
```

---

## KMP 算法

---

## c++基础

### 以 `#` 开头的为**预处理器**处理的命令

`#pragma once`             “同一个文件”是指物理上的一个文件
vs
```txt
#ifndef __SOMEFILE_H__
#define __SOMEFILE_H__
... ... // 声明、定义语句    编译器支持较好
#endif
```


### 对运算符进行重载

```cpp
class P {
public:
    std::string name;

    explicit P(std::string name) : name(std::move(name)) {}

    friend std::ostream &operator<<(std::ostream &os, const P &p) {
        os << "name: " << p.name;
        return os;
    }

};
```

### 浮点数格式化 iomanip

setprecision
setw 宽度

```cpp
std::cout << 1.2456 << std::endl;
std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3) << 1.2456 << std::endl;
std::cout << std::setprecision(3) << 1.2456 << std::endl;
```

### 枚举

```cpp
enum State {...., ..., ...}
```

### 一元作用域

```cpp
int num = 5;
{
    int num = 7;
    cout << ::num  // 5
}

```

### static

book/cpt7/static.h

函数中设置static后多次调用的是同一个

### sizeof

char    1
short   2
int     4
long    4
float   4
double  8
long double 8

// book/cpt8/ptr.h
```cpp
char color[] = "blue";
std::cout << sizeof(color) << std::endl; // 5
```

### 指针

指针数组
const char* const suit[4] = { "asdas", "ewqeqw", "dasds", "ds" }

函数指针
void ptrFunc(void (*cb)(int));

### 指针和引用

链接：https://www.zhihu.com/question/37608201/answer/72766337

对象的定义：对象是指一块能存储数据并具有某种类型的内存空间一个对象a，它有值和地址&a
指针也是对象
引用：看成常量，声明的同时必须初始化，所有调用时不会为空
另：
    常量指针: 被指向的对象是常量
    指针常量: 指针本身是常量
```cpp
r=3;//正确：等价于a=3
int &rr;//出错：引用必须初始化
p=&a;//正确：p中存储a的地址，即p指向a
*p=4;//正确：p中存的是a的地址，对a所对应的存储空间存入值4
p=&b//正确：p可以多次赋值，p存储b的地址
```

### 打乱数组
std::shuffle(std::begin(idxs), std::end(idxs), std::mt19937(std::random_device()()));
std::random_shuffle(std::begin(idxs), std::end(idxs));

### 类型转换

static_cast 编译时进行转换  失败报错
dynamic_cast 运行时进行转换 失败 nullptr

### 内联函数

关键字 inline 必须与函数定义体放在一起才能使函数成为内联

一种“用于实现的关键字”，而不是一种“用于声明的关键字”

内联函数有些类似于宏。内联函数的代码会被直接嵌入在它被调用的地方，
调用几次就嵌入几次，没有使用call指令。这样省去了函数调用时的一些额外开销，
比如保存和恢复函数返回地址等，可以加快速度。

不过调用次数多的话，会使可执行文件变大，这样会降低速度。
相比起宏来说，内核开发者一般更喜欢使用内联函数。因为内联函数没有长度限制，格式限制。
编译器还可以检查函数调用方式，以防止其被误用。

static inline的内联函数，一般情况下不会产生函数本身的代码，
而是全部被嵌入在被调用的地方。如果不加static，则表示该函数有可能会被其他编译单元所调用，
所以一定会产生函数本身的代码。所以加了static，一般可令可执行文件变小。
内核里一般见不到只用inline的情况，而都是使用static inline。

inline

关键字inline表明要优化函数的可执行代码，
这可以通过将函数的代码合并到调用程序的代码中来实现。
Linux内核使用的inline函数大多被定义为static 类型。
一个"static inline"函数促使编译程序尝试着将其代码插入到所有调用它的程序中。

这一合并能够免除函数调用的任何开销，#define语句也可以排除额外的函数调用。

另外，使用inline会增加二进制映像的大小，而这会降低访问CPU高速缓存的速度，
所以不能在所有的函数定义中使用它。

- static inline 它不使用函数调用，直接将汇编代码插入在调用该函数处。static inline函数
                和static函数一样，其定义的范围是local的，
                即可以在程序内有多个不同的定义(只要不位于同一个文件内即可)。


---

## 类

getline(cin, str)

### 初始化列表

链接：https://www.nowcoder.com/questionTerminal/cb59a271f49b4f03804122d5786e8e2c
有一个类A，其数据成员如下：
```cpp
class A {
...
private:
     int a;
public:
     const int b;
     float* &c;
     static const char* d;
     static double* e;
};
```


则构造函数中，成员变量一定要通过初始化列表来初始化的是：______。
a b c
b c
b c d e
b c d
b
c

### 双冒号的作用

- 作用域符号::的前面一般是类名称，后面一般是该类的成员名称 A::member就表示类A中的成员member
- 全局作用域符号
- 作用域分解运算符 那么在类外定义f时，就要写成voidA::f()

### 友元

book/cpt10/friend.h
在类中声明，在别处定义

### static

book/cpt10/static.h
在cpp文件中初始化
int cpt10_static::Person::count = 0;

---

## 文件操作

EOF -1  ctrl-d(*unx) c-z(win)

---

## 时间操作

```cpp
const time_t currentTime = time( 0 );
const tm *localTime = localtime( &currentTime );
setTime( localTime->tm_hour, localTime->tm_min, localTime->tm_sec );
```

---

## 抽象数据类型 ADT

抽象数据类型 int char double

---

## 运算符重载

不可重载的运算符：. | .* | :: | ?:

赋值运算符需成为类的成员  `()[]->`

----

// TODO: 大数相乘 .. 9 11 431

---

## 继承

### protected

基类，友元，以及其派生出的类和友元访问

---

## 多态

https://blog.csdn.net/qq_33724710/article/details/51645228
https://www.ibm.com/developerworks/cn/java/j-lo-polymorph/index.html

多态练习题：book/cpt13/task/content.h

- 派生类重写基类的虚函数实现多态，要求函数名、参数列表、返回值完全相同。(协变除外)
- 基类中定义了虚函数，在派生类中该函数始终保持虚函数的特性
- 只有类的成员函数才能定义为虚函数，静态成员函数不能定义为虚函数
- 如果在类外定义虚函数，只能在声明函数时加virtual关键字，定义时不用加
- 构造函数不能定义为虚函数，虽然可以将operator=定义为虚函数，但最好不要这么做，使用时容 易混淆
- 不要在构造函数和析构函数中调用虚函数，在构造函数和析构函数中，对象是不完整的，可能会 出现未定义的行为
- 最好将基类的析构函数声明为虚函数。(析构函数比较特殊，因为派生类的析构函数跟基类的析构 函数名称不一样，但是构成覆盖，这里编译器做了特殊处理)
- 虚表是所有类对象实例共用的

我们知道了man对象中维护了一个虚表指针，虚表中存放着虚函数的地址。
基于这个虚表指针，实现动态绑定，才可以用基类指针调用了Man类中的虚函数。

---

## 模板

即使模板只写一次，但是在编译阶段会初始化多个类模板特化

类模板的非类型参数
```cpp
template< typename T, int elements >
```

特化与偏特化
https://www.jianshu.com/p/4be97bf7a3b9

特化 ---> T指定数据类型 etc:double

```cpp
template <class T>
class Compare

//....

template <>
class Compare<float>
```

偏特化 -->  指定变量类型 etc:const,指针..
```cpp
template <class T, class T1>
class TestClass

// .....

template <class T, class T1>
class TestClass<T*, T1*>
```

对性能：每一个特化都会占用相应的存储空间，影响占用生成程序的大小和内存使用

---

## 输入输出流

std::cin.get()      截取的字符留在输入流中
std::cin.getline()  丢弃截取的字符

---

## 异常

### 一般

```cpp
#include <stdexcept>
class DivideByZeroExpcetion : public std::runtime_error {}
```

try --> try --> try --> terminate --> abort
                    --> 改变参数 set_terminate --> 其它函数

### 程序退出机制

直接 `throw` 会调用 **terminate** 函数 --> abort() 不会释放内存
非规格异常 会调用 **unexpected** 函数结束

### 构造函数中异常处理

可能会无法释放资源：--> 1.初始化一个局部资源来获取资源 2.当异常发生时调用析构函数
当异常是由一个new表达式构建对象时引出的话，其动态分配的内存空间将被释放

new失败时抛出 bad_alloc的异常
使用set_new_handler /* #include <new> */, 调用 abort /* #include <cstdlib> */


### 智能指针使用 book/cpt16/cpt16_auto_ptr.h

deprecated auto_ptr --> unique_ptr

### 异常层次

- exception exception
    - runtime_error stdexcept
        - overflow_error
        - underflow_error
    - logic_error   stdexcept
        - invalid_argument
        - length_error
        - out_of_range
    - bad_alloc
    - bad_cast
    - bad_type_id
    - bad_exception

### STL异常类型

- out_of_range      下标
- invalid_argument  传参无效
- lenght_error      创建长度过长
- bad_alloc         内存不够


---

## 文件处理

文件 <-- 记录 <-- 字段 <-- 字节 <-- 位

### 处理模式

ios::app 添加到末尾
ios::ate 打开一个文件作为输出文件，并移动到文件末尾
ios::in  打开一个文件作为输入文件
ios::out 打开一个文件作为输出文件
ios::trunc  如果文件有内容则将其丢弃
ios::binary 以非文本的方式进输入或输出

### close

由流的析构函数关闭

### 一些api

- 对输入流操作：seekg（）与tellg（）
- 对输出流操作：seekp（）与tellp（）

seekg（）是对输入文件定位，它有两个参数：
第一个参数是偏移量，第二个参数是基地址。
第二个参数可以是：
    - ios::beg：表示输入流的开始位置
    - ios::cur：表示输入流的当前位置
    - ios::end：表示输入流的结束位置
    - tellg()函数不需要带参数，它返回当前定位指针的位置，也代表着输入流的大小。

---

## 字符串

不能使用char或int进行初始化

### 一些api

- assign
- at
- append
- size 
- length
- erase
- string::npos 不存在该位置

### 字符串比较

```cpp
std::string str1 ("green apple");
std::string str2 ("red apple");
if (str1.compare(6,5,str2,4,5) == 0)
std::cout << "therefore, both are apples\n";
```

### 字符串查找


- find
    - Find content in string (public member function )
- rfind
    - Find last occurrence of content in string (public member function )
- find_first_of
    - Find character in string (public member function )
- find_last_of
    - Find character in string from the end (public member function )
- find_first_not_of
    - Find absence of character in string (public member function )
- find_last_not_of
    - Find non-matching character in string from the end (public member function )
---

### 注意的题目

book_task/cpt18/cpt18_q_task_20.h 一些函数的使用 strtok

---

### 字符串分割

// task/task_2/quze1/quze1.h

```cpp
// 分割字符串
std::string inputStr = "i-an-a-boy";
std::istringstream is(inputStr);
std::string output;
while (std::getline(is, output, '-')) {
    std::cout << output << std::endl;
}
```

```cpp
char *tokenPtr;
char sentence[80] = "22233 323232  3232 43";
tokenPtr = std::strtok(sentence, " ");
while (tokenPtr != 0) {
    auto *newString = new std::string(tokenPtr);
    std::cout << *newString << std::endl;
    tokenPtr = strtok(0, " ");
}
```

```cpp
std::vector<std::string> split_string(const std::string &data, char c) {
    std::vector<std::string> ret;
    auto old = std::cbegin(data);
    for(auto it = old; it != std::cend(data); ++it) {
        if( *it == c ) {
            ret.emplace_back( old, ++it );
            old = it;
        }
    }
    if( old != cend(data) ) {
        ret.emplace_back( old, cend(data) );
    }
    return ret;
}
```




---

## 搜索和排序

- 选择排序 n^2
- 插入排序 n^2

---

## 树左倒向打印

```cpp
template< typename NODETYPE >
void Tree< NODETYPE >::outputTreeHelper( TreeNode< NODETYPE > *ptr, int totalSpaces ) const
{
   if ( ptr != 0 )
   {
      outputTreeHelper( ptr->rightPtr, totalSpaces + 5 );

      for ( int i = 1; i <= totalSpaces; i++ )
         cout << ' ';

      cout << ptr->data << '\n';
      outputTreeHelper( ptr->leftPtr, totalSpaces + 5 );
   }
}
```

---

## 位，字符，c字符串和结构体

### 结构体的洞

存储结构需要对其，所有可以会有残余的空间 p684

---

### 打印二进制

```cpp
void displayBits(unsigned value) {
    const int SHIFT = 8 * sizeof(unsigned) - 1;
    const unsigned MASK = 1 << SHIFT;
    for (unsigned i = 1; i <= SHIFT + 1; i++) {
        std::cout << (value & MASK ? '1' : '0');
        value <<=  1;

        if ( i % 8 == 0) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;
}
```

---

### 位域

```cpp
struct BitCard {
    unsigned face : 4;  // 4 bits 0-15
    unsigned suit : 2;  // 2 bits 0-3
    unsgined color: 1;  // 1 bit  0-1
};
```

---

### 字符处理

cctype 头文件

isdigit
isalpha
isalnum  字母或数字
isxdigit 十六进制
islower
isupper
tolower
toupper
isspace

iscntrl 控制字符 \n \f 换页符 \r \t \v \a \b 退格符
ispunct 除空格数字字母之外的可打印字符
isprint 可打印字符
isgraph 除空格外的可打印字符

可打印字符：
可打印字符的ASCII码值大于 0x1f（除了0x7f(DEL)），
这些字符可以显示到屏幕上，让我们看到；
不能显示在屏幕上，我们看不到的，叫控制字符，
ASCII码值为 0x00 ~ 0x1f，再加上 0x7f(DEL)。
检测控制字符请使用 iscntrl() 函数。

---

### 字符串处理函数

cstring 头文件

char *strcpy(char *s1, const char *s2)
char *strncpy(char *s1, const char *s2, size_t n)

char *strcat(char *s1, const char *s2) 终止字符由s2第一个字符改写
char *strncat(char *s1, const char *s2, size_t n)

int strcmp(const char *s1, const char *s2)
int strncmp(const char *s1, const char *s2, size_t n)

char *strtok(char *s1, const char *s2)
size_t strlen(const char *s)

---

### 基于指针的字符串转换函数

cstdlib 头文件

double atof     (const char *nPtr)
int    atoi     (const char *nPtr)
long   atol     (const char *nPtr)
double strtod   (const char *nPtr, char **endPtr)
long   strtol   (const char *nPtr, char **endPtr, int base) 0 2-36
unsigned strtoul ...

---

### 基于指针的字符串搜索函数

char*   strchr      (string char)      (const char *s, int c)      找到c第一次出现的位置，返回地址
char*   strrchr     (....)             (const char *s, int c)      找到c最后一次出现的位置，返回地址
size_t  strspn      (string span)      (const char *s, const char *s2)  检索字符串 str1 中第一个不在字符串 str2 中出现的字符下标
                                                     ABCDEFG019874  ABCD --> 4
char*   strpbrk     (string pointer break)      (const char *s, const char *s2)  检索字符串 str1 中第一个匹配字符串 str2 中字符的字符
                                                    abcde2fghi3jk4l 34 ----> 3
size_t  strcspn     (string complement span)    (const char *s, const char *s2)   检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符
                                                    ABCDEF4960910   013 ---> 10
char*   strstr      (const char *s, const char *s2)   在字符串 s 中查找第一次出现字符串 s2 的位置，不包含终止符
                                                    RUNOOB NOOB      ----> NOOB

---

### 基于指针的处理内存的函数

void*       memcpy       (void *s1, const void *s2, size_t n)           被复制的数据对象区域不能覆盖要复制额字符区域
void*       memmove      (void *s1, const void *s2, size_t n)           ..................可以覆盖..............
int         memcmp       (const void *s1, const void *s2, size_t n)
void*       memchr       (const void *s1, int c, size_t n)
void*       memset       (void *s, int c, size_t n)                     复制c至s的前n个位置


---

## STL

### 分类

序列容器
    vector
    deque
    list
关联容器
    set
    multiset
    map
    multimap
容器适配器
    stack
    queue
    priority_queue

---

### 迭代器

input
        forward  bidirectional random_access
output

iterator                    -> rw
const_iterator              -> r
reverse_iterator            <- rw
const_reverse_iterator      <- rw

序列容器
    vector  random_access
    deque   random_access
    list    bidirectional
关联容器
    set         bidirectional
    multiset    bidirectional
    map         bidirectional
    multimap    bidirectional
容器适配器
    stack
    queue
    priority_queue

---

### STL异常类型

- out_of_range      下标
- invalid_argument  传参无效
- lenght_error      创建长度过长
- bad_alloc         内存不够

---

### 序列容器

book/cpt22_stl/cpt22_stl_playground.h

vector 数组

list 在任何地方高效插入  实现了双向列表

deque 双端队列

---

### 关联容器

- multiset

- set

- multimap

- map

---

### 适配容器

- stack

- queue

- priority_queue

---

### 算法法

- 生成器 fill，fill_n，generate，generate_n

---

## 预处理命令

```txt
# include
# define
# if # elif # else
# undef 取消
# ifndef (#if !define(name)) # endif
# error
# pragma
__LINE__
__FILE__
__DATE__
__STDC__ 是否符合ANSI/IOS c标准
__TIME__ hh:mm:ss
__cplusplus

```


