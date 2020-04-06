#### Q6.4: 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。
#### A：　见6-4.cpp。
#### q6.5:编写一个函数暑促其实参的绝对值。
#### A: 见6-5.cpp。
#### Q6.6: 说明形参、局部变量以及静态局部变量的区别。
#### A: 
* 形参也是函数内的一种局部变量，只是形参是被实参初始化，函数执行结束后形参的生命周期结束；
* 局部变量是函数体内定义的普通变量，如果没有显示初始化会执行默认初始化，对于内置类型就是未定义的行为；函数执行结束后局部变量的生命周期也结束；
* 静态局部变量是函数体内定义变量时加上static关键字，这种变量只在函数执行过程中第一次经过该变量时初始化一次，如果没有显示初始化，对于内置类型默认初始化为０或空字符串；静态局部变量的生命周期与进程一致。
#### Q6.7: 编写一个函数，当它第一次被调用时返回０，以后每次被调用返回值加１．
#### A:使用静态局部变量，见6-7.cpp。
#### 函数只能定义一次，但可以声明多次。因为函数的声明不包含函数体，所以就无须形参的名字。事实上，在函数的生命中经常省略形参的名字。
#### Q6.10: 编写一个函数，使用指针形参叫喊两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
#### A: 见6-10.cpp。
#### 一个函数只能用return返回一个值，引用形参为我们提供了一次返回多个结果的功能。
#### Q6.12: 编写一个函数，使用引用交互两个整数变量的值。
#### A: 见6-12.cpp。
#### 当实参不需要修改时，形参尽量定义为常量引用。如果定义为普通引用，则调用该函数时传入的实参只能是非常量变量，具有局限性。
````c++
string::size_type find_char(string &s, char c, string::size_type &occurs);

bool is_sentence(const string &s)
{
    // 如果在s的末尾有且只有一个句号，则s是一个句子。
    string::size_type ctr = 0;
    return find_char(s, '.', ctr) == s.size -1 && ctr == 1;
}
// 报错：find_char的string参数为普通引用，不能绑定到常量s；
// 此时，要么修改is_sentence的常量string为非常量string,但如果有其他常量形参函数调用is_sentence还是会出现一样的错误，不建议这么做；
// 另一种可行方法是在is_sentence函数内部定义一个非常量的string局部变量，将s　拷贝给这个临时变量，再传参给find_char;
// 这样设计代码不够优化，所以推荐将find_char的参数改为常量引用。
````
#### Q6.17: 编写一个函数，判断string对象中是否含有大写字母。编写另一个函数,把string对象全部改写成小写形式。在这两个函数中使用的形参相同吗？为什么？
#### A: 第一个函数不修改形参，所以定义为常量引用；第二个函数需要修改传入的实参，定义为普通引用。见6-17.cpp。
#### Q6.18: 为下面的函数编写声明，从给定的名字中推测函数具备的功能。
(a)　名为compare的函数，返回布尔值，两个参数都是matrix类的引用。
(b)　名为change_var的函数，返回vector<int>的迭代器，有两个参数：一个是int,另一个是vector<int>的迭代器。
#### A:
````c++
(a)
bool compare(const matrix &m1, const matrix &m2); // 判断两个矩阵是否相等。
(b)
vecotr<int>::iterator change_var(vector<int>::iterator it, const int i);
// 通过迭代器修改整数形参所指定位置的元素值，并返回指向该元素位置的迭代器。
````
#### 数组的两个特性：不允许拷贝和使用数组时通常会将其转换为指针，这两个特性决定了指针数组作为形参时的使用方式。
#### 数组作为形参的４种形式：
* 数组实参本身包含一个结束标记，这种方法常用于C风格的字符串,在存在字符数组中时，最后一个字符后面跟着一个空字符，函数处理字符数组时遇到控制符停止：
````c++
void print(const char *cp)
{
    if(cp)
        while(*cp)  // 遇到控制符时终止循环
            cout << *cp++; // 输出当前字符后向前移动一个位置
}
````
* 传递数组的首指针和尾后指针，可使用标准空中的begin和end函数获取指针
````c++
void print(const int *beg, const int *end)
{
    // 输出beg到end之间（不含end）的所有元素
    while(beg != end)
    {
        cout << *beg++ << endl;
    }
}
````
* 传递数组和一个表示数组大小的形参
````c++
void print(const int ia[], size_t size)
{
    for(size_t i = 0; i < size; ++i)
    {
        cout << ia[i] << endl;
    }
}

// 调用
int j[] = {0, 1, 2};
print(j, end(j) - begin(j)); // 自动计算数组大小
````
* 数组引用形参
````c++
// 必须指定数组大小，所以引用形参的方法只能用于访问特定的数组。
void print(int (&ia)[10])
{
    for(auto elem : ia)
        cout << elem << endl;
}
// 使用
int i = 0, j[2] = {0, 1};
int k[10] = {0, 1. 2, 3, 4, 5, 6, 7, 8, 9};
print(&i); // 错误
print(j); // 错误：实参不是含有10个整数的数组
print(k); // 正确。
````
#### 传递多维数组
````c++
// 列的维度必修指出
void print(int (*matrix)[10], int rowSize);
// 等价于
void print(int matrix[][10], int rowSize);
````
#### Q6.21: 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较ｉｎｔ、的值和指针所指的值，返回较大的那个。在函数中指针的类型应该是什么？
#### A: 常量指针
````c++
const int compare(const int a, const int *const p)
{
    if(a > *p)
        return a;
    return *p;
}
````
#### Q6.22: 编写一个函数，令其交换两个int指针。
#### A
````c++
void swap(int *p1, int *p2)
{
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}
````
#### 6.24: 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
````c++
void print(const int ia[10])
{
    for(size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl; 
}
````
#### A: 该函数想通过下标访问的方式输出传入的数组的每个元素，但实际传入的数组元素个数可能小于１０，形参定义的１０个元素没有意义。
````c++
// 传入一个形参表示数组长度
void print(const int ia[], size_t num)
{
    for(size_t i = 0; i != num; ++i)
        cout << ia[i] << endl; 
}
````
#### 6.25:　编写一个main函数，令其接受两个实参。把实参的内容链接成一个string对象并输出出来。
#### A:　见6-25.cpp。
#### 6.26: 编写一个函数，使其接受版本所示的选项；输出传递给main函数的实参的内容。
#### A: 见6-26.cpp。

----
#### 含有你可变形参的函数
* 用途：　假设想要编写代码输出程序产生的错误信息，最好用同一个函数实现该项功能，以便对所有错误的处理能够整齐划一。然而，错误信息的种类不同，传递实参的个数也不相同。
* initializer_list形参: 该形参也是一个容器，只是内部的元素永远是常量值
````c++
void error_msg(ErrCode e, initializer_list<string> sl)
{
    cout << e.msg() << ": ";
    for(auto beg = sl.begin(); beg != sl.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}
// 使用. expected和actual是string对象
if(expcted != actual)
{
    error_msg(ErrCode(42), {"functionX", expected, actual});
}
else
{
    error_msg(ErrCode(0), {"functionX", "okay"});
}
````
* 省略符形参：仅仅用于C++访问某些特殊的C代码而设置的。
````c++
void foo(parm_list, ...)
````
----

#### Q6.27: 编写一个函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和。
#### A: 见6-27.cpp。
#### Q6.28: 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？
#### A: elem是const string类型的对象。
#### Q6.29: 在范围for循环中使用initializer_list对象时，应该将循环控制变量什么为引用类型吗？为什么？
#### A: 建议声明为引用类型，因为initializer_list是一个容器，其内部元素不一致指出拷贝赋值；而且，使用引用降低拷贝赋值产生的资源消耗；initializer_list内部的元素全是常量值，即使引用后也不会被修改它的值。

----
### 返回值
* 不要返回局部对象的引用或指针
* 调用一个返回音乐的函数得到左值，可以为返回类型是非常量引用的函数的结果赋值：
````c++
char &get_var(string &str, string::size_type ix)
{
    return str[ix];
}

int main()
{
    string a("a value");
    cout << a << endl;
    get_val(s, 0) = 'A'; // 将s[0]的值改为A.
    cout << s << endl;
}
````
----
#### Q6.30: 编译第200也的str_subrange函数，看看你的编译器是如何处理函数中的错误的。
#### A: 见6-30.cpp。
````c++
bool str_subrange(const string &str1, const string &str2)
{
    if(str1.size() == str2.size())
    {
        return str1 == str2;
    }

    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    for(decltype(size) i = 0; i < size; ++i)
    {
        if(str1[i] != str2[i])
        {
            return; //error: return-statement with no value, in function returning ‘bool’ [-fpermissive].
        }
    }
}
````
#### Q6.31: 什么情况下返回的引用无效？什么情况下返回常量的引用无效？
#### A:
* 返回函数体内局部变量的引用无效
* 函数声明时返回值类型是非常量引用：
````c++
int &test() // 错误：非常量引用不能绑定到常量字面值。
{
    return 10;
}
// 修改为
const int &test()
{
    return 10;
}
````
#### Q6.32: 下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
````c++
// 返回数组元素的引用。
int &get(int *array, int index)
{
    return array[index];
}
int main()
{
    int ia[10];
    for(int i = 0; i != 10; ++i)
    {
        get(ia, i) = i;
        cout << get(ia, i) << endl;
    }

    return 0;
}
````
#### A: 合法，　通过函数返回数组元素的引用来给每个元素赋值。见6.32.cpp。
#### Q6.33:编写一个递归函数，输出vector对象的内容。
#### A: 使用局部静态变量。见6-33.cpp。
#### Q6.34: 如果factorial函数的停止条件如下所示，将发生什么情况？
````c++
if(val != 0)
````
#### A:不影响最终结果，只是会阶乘中会出现两两次乘1.
#### Q6.35: 在调用factorial函数时，为什么我们传入的值是val-1而非val--?
#### A:因为val--是先使用后减１，如果传入它会导致阶乘变为(val*val)*((val-1) * (val-1))...

----
### 返回数组指针
* 使用类型别名：
````c++
typedef int arrT[10]; // arrT是一个类型别名，它表示的类型是含有１０个整数的数组。
using arrT = int[10]; // arrT的等价声明
arrT* func(int i); // 返回一个指向含有１０个整数的数组的指针
````
* 普通的定义返回数组指针的函数形式：
    * `Type (*function(parameter_list))[dimension]`
````c++
int (*func(int i)) [10];
// 理解方法：
// func(int i)表示调用func函数时需要一个int类型的实参；
// (*func(int i)) 意味着我们可以对函数调用的结果进行解引用；
// (*func(int i)) [10]表示解引用后的结果是一个大小为１０的数组；
// int (*func(int i)) [10]// 数组元素类型是ｉｎｔ型
````
* 使用尾置返回类型: `auto func(int i) -> int(*)[10]`,func返回一个指针，该指针指向含有10个整数的数组
* 使用decltype: 适用于知道函数返回的指针指向哪个数组的情况
````c++
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltyp(odd) *arrPtr(int i) // 返回指向含有５个整数的数组的指针
{
    return (i%2)?&odd : &even; // 必须返回指向该数组的指针
}
````
----
#### Q6.36:编写一个函数的声明，使其返回数组的引用并且该数组包含１０个string对象。不要使用尾置返回类型、decltype或者类型别名。
#### A: `string (&arr)[10] func();`
#### Q6.37: 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？
#### A:
````c++
// 使用类型别名
using arrS = string[10];
arrS& func();
// 使用尾置返回类型
auto func -> string(&)[10];
// 使用decltype关键字
string arrS[] = {"he", "ll", "ss", "d", "da", "d", "dda", "das", "sad", "Dads"};
decltype((arrS)) &func(); // decltype使用双括号定义引用类型.
````
#### 6.38: 修改arrPtr函数，使其函数返回数组的引用。
#### A: 见6-38.cpp。

###6.3 函数重载
* 函数重载的定义：同一作用域内，形参数量或形参类型不同的同名函数。
    * 不同返回值类型不能用于实现重载函数
    * 顶层const也不能用于实现重载
````c++
Record lookup(Phone);
Record lookup(const Phone); // 值拷贝属于顶层const，不能构成重载

Record lookup(Phone *p);
Record lookup(Phone *const p); // 常量指针也是顶层const,不能构成重载
````
    * 底层const可以用于实现重载
````c++
Record lookup(Account&);
Record lookup(const Account&); // 底层const可以实现重载

Record lookup(Account*);
Record lookup(const Account*); // 底层const可实现重载
````
### 6.5 特殊用途语言特性
#### 6.5.1默认实参
* 默认实参负责填补函数调用缺少的尾部实参，不能前面几个的实参用默认值而只修改后面的实参。
* 一旦某个形参被赋予了默认值，它后面的所有形参都必须有默认值
#### Q6.40: 下面的那个声明是错误的？为什么？
````c++
(a) int ff(int a, int b = 0, int c = 0); // 正确
(b) char *init(int ht = 24, int wd, char bckgrnd); // 错误：　一旦某个形参被赋予了默认值，它后面的所有形参都必须有默认值。
````
#### Q6.41: 下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
````c++
char *init(int hg, int wd = 80, char bckgrnd = ' ');
(a)init(); // 错误：必须至少给定一个实参
(b)init(24, 10); // 正确，等价于init(24, 10, ' ');
(c)init(14, '*'); // 错误：初衷是修改给第一和第三个形参赋值，第二个形参使用默认值；但不能跳过中间某个参数只修改后面的默认参数
// 正确调用为
init(14, 80, '*');
````
#### Q6.42: 给make_plural函数的第二个形参赋予默认实参's',利用新版本的函数输出单词success和failure的单数和复数形式。
#### A: 见６6-42.cpp。
#### 6.5.2 内联函数和constexpr函数
* 内联函数可避免函数调用的开销
* constexpr函数是指能用于常量表达式的函数：
    * 函数的返回类型及所有形参都必须是字面值类型
    * 函数体中必须有且只有一条return语句
    * constexpr函数不一定返回常量表达式
    
###6.6函数匹配
* 候选函数具备的两个特征：
    * 与被调用的函数同名
    * 其声明在调用点可见
* 可行函数：
    * 其形参数量与本次调用提供的实参数量相等
    * 每个实参的类型与对应的形参类型相同，或者能转换成形参的类型
* 从可行函数中选择与本次调用最匹配的函数，如果没有找可行函数，编译器报告无匹配函数的错误
#### 6.49: 什么是候选函数？什么是可行函数？
#### A:候选函数就是在同一作用域内与被调用函数同名的那些函数；可行函数就是候选函数中的重载函数。
#### 6.50: 已知对函数f的声明如下，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
````c++
// f的声明
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

// 调用
(a)f(2.56, 42);
(b)f(42);
(c)f(42, 0);
(d)f(2.56,3.14);
````
#### A
````c++
// 可行函数：f(int, int),f(double, double = 3.14)
// 调用具有二义性
(a)f(2.56, 42);

// 可行函数：f(int),f(double, double = 3.14)
// 最佳匹配:f(int)
(b)f(42);

//可行函数：f(int, int),f(double, double = 3.14)
//最佳匹配: f(int, int)
(c)f(42, 0);

//可行函数：f(int, int),f(double, double = 3.14)
//最佳匹配: f(double, double = 3.14)
(d)f(2.56,3.14);
````
#### Q6.51:编写函数f的4个版本，令其各输出一条可以区分的消息。验证上一题的答案，如果你回答错了，反复研究本节的内容直到你弄清自己错在何处。
#### A:见6-51.cpp。

----
### 6.7:函数指针
* 函数指针指向的是函数而非对象，函数类型由它的返回类型和形参类型共同决定，与函数名无关
* 函数指针声明：`返回类型 (*变量名)(形参列表)`
* 函数名可自动转换为指针:
````c++
// pf是函数指针, lengthCompare是函数名
pf = lengthCompare;
pf = &lengthCompare; // 与上面等价
````
* 不同类型函数指针之间不能相互转换
* 重载函数的指针：指针类型必须与重载函数中的某一个精确匹配
````c++
// 重载函数
void ff(int*);
void ff(unsigned int);

// 定义重载函数的指针
void (*pf1) (unsigned int) = ff;// 正确：pf指向void ff(unsigned int).
void (*pf2) (int) = ff; // 错误：没有任何一个ff与该形参列表匹配
double (*pf3) (int*) = ff; // 错误：ff和pf3的返回类型不匹配。
````
* 函数指针作为形参：
````c++
// 第三个形参是函数类型，它会自动地转换成指向函数的指针
//即将形参以声明函数的形式进行定义
void useBigger(int a, int b, bool pf(const string &, const string &));
//等价声明
void useBigger(int a, int b, bool (*pf) (const string &, const string &));

// 调用：直接把函数名作为实参
useBigger(a, b, lengthCompare);
````
* 使用类型别名和decltype声明函数指针
````c++
// typedef
typedef bool (*FuncP) (const string &, const string &);
typedef decltyp(lengthCompare) *FuncP2;
using FuncP3 = bool (*) (const string &, const string &);

// 重新声明useBigger函数
void useBigger(int a, int b, FuncP);
void useBigger(int a, int b, FuncP2);
void useBigger(int a, int b, FuncP3);
````
* 返回函数指针的声明
````c++
// 声明一个函数指针，指向的函数类型为：返回值类型为int,形参类型为(int*, int).
// 传统形式(难以理解)
int (*f1(int)) (int*, int); // 由内往外读
// 使用类型别名
using pf = int (*) (int*, int);
pf f1(int); // 简介明了
// 使用尾置返回类型
auto f1(int) -> int (*) (int*, int);
````
----
#### Q6.54: 编写函数的声明，令其接受两个int形参并且返回类型也是int;然后声明一个vector对象，令其元素是指向该函数的指针。
#### A:
````c++
int func(int, int);

// 使用typedef和decltype
typedef int(*pf1)(int ,int);
vector<pf1> pfVec1;
typedef decltype(func) *pf2;
vector<pf2> pfVec2;
// 使用using
using pf3 = int(*)(int, int);
vector<pf3> pfVec3;
````
#### Q6.55: 编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。
#### A: 见6-55.cpp。
#### Q6.56: 调用上述vector对象中的每个元素并输出其结果
#### A:　见6-55.cpp。
* 函数指针的优点：使用函数指针指针同一类型的函数，能够便捷地对多个函数进行调用。