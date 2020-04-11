 #### this指针
 * 默认情况下this是一个常量指针，它的类型是`classname *const`，所以，默认情况下,this指针不能访问常量对象(因为访问常量对象需要指向常量的指针)；
 * 常量成员函数：在成员函数的形参列表后面加`const`用于声明在调用该函数时this指针被定义为了指向常量的指针，即`const classname *const this;`;
 #### Q7.2: 曾在2.6.2节的练习中编写了一个Sanles_data类，请向这个类添加combine和isbn成员。
 #### A:见7-2.h和7-2.cpp。
 #### Q7.3: 修改7.1.1节的交易处理程序，令其使用这些成员。
 #### A:见7-3.h和7-3.cpp。
 #### Q7.4: 编写一个名为Person的类，使其表示人员的姓名和住址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。
 #### A: 见person.h。
 #### Q7.5: 在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是const的呢？请解释原因。
 #### A:见person.h和person.cpp。这些函数应该是const的，因为只是查看姓名和地址，不需要修改。
 * 如果非成员函数是类接口的组成部分，则这些函数的声明建议与类在同一个头文件内。
 #### Q7.7: 使用这些新函数重写7.1.2节练习中的交易处理程序。
 #### A: 见7-7.h和7-7.cpp。
 #### Q7.8: 为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用？
 #### A:因为read函数需要将输入流的数据写入数据成员，而print函数只访问数据成员，不需要修改。
 #### Q7.9: 对于7.1.2节练习中的代码，添加读取和打印Person对象的操作。
 #### A: 见person.h和person.cpp。
 * 如果类包含有内置类型或者复合类型的成员，则只有当这些成员全部被赋予了类内的初始值时，这个类才适合于使用合成的默认构造函数。
 #### Q7.11&Q7.12: 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。
 #### A: 见7-11.h和7-11.cpp。
 #### Q7.13:使用istream构造函数重写第229页的程序。
 #### A:见7-13.h和7-13.cpp。
 #### Q7.15:为你的Person类添加正确的构造函数.
 
 ----
 #### 类对象拷贝的几种情况：
 * 初始化
 * 以值的方式传递(赋值、传参)
 * 返回类对象
 #### 访问控制与封装
 * `struct`关键字的默认访问权限是**public**,`class`关键字的默认访问权限是**private**
 #### 友元
 * 类允许其他类或者函数访问它的非公有成员：令其他类或者函数成为它的友元；
 * 在类内部的其他类或函数的声明前加关键字`friend`可声明为友元: 
    * 友元类或函数自身的声明
    * 友元类或函数在被访问类内部以关键字`friend`开头再次进行声明；
 ----
 #### Q7.18: 封装是何含义？它有什么用处？
 #### A:封装就是使用访问说明符限定数据成员和成员函数的访问权限，能够强制用户只能通过类开放的接口访问类，而不能直接访问类的实现细节。
 #### Q7.19: 在你的Person类中，你将把哪些成员声明成publick的？哪些成员声明成privat的？解释你这样左的原因。
 #### A: 将数据成员声明为private以达到保护数据的目的，避免外部程序直接修改数据成员。将访问数据成员的借口和构造函数声明为public,给外部程序访问该类。
 ````c++
class Person{
public:
    Person() = default;
    Person(const std::string &id, const std::string& addr) :
           name(id), address(addr){}
    Person(std::istream &is)
    {
        is >> name >> address;
    }

    std::string getName() const {return name;} // 返回值不能是普通引用类型，因为常量函数体内的变量被隐式声明为了常量；
//    const std::string &getName() const {return name;} // 正确
    std::string getAddress() const {return address;}
//    const std::string &getAddress() const {return address;} // 正确
private:
    std::string name;
    std::string address;
};
````
#### Q7.20: 友元在什么时候有用？请分别列举出使用友元的利弊。
#### A: 友元在外部程序想要直接访问目标类非共有成员时可用；友元为用户提供更多的接口访问目标类，但是会破坏目标类的封装。
#### Q7.21: 修改你的Sales_daa类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重写编译程序，确保其正常工作。
#### A:见7-21.h和7-21.cpp。

----

###　类的一些特性
#### 类型成员
* 使用`typedef`或`using`定义类型成员
* 类型成员必须先定义后使用，因此，类型成员通常在类开始处定义；
#### 可变数据成员
* mutable数据成员丢失了const属性，常量成员函数和非常量成员函数都能修改它的值。
* mutable主要用来修饰常量成员函数想要修改的那些变量；
#### 类内初始值
* 当我们在类内部为另一个类提供初始值时，必须以符号=或者花括号表示。
----

#### Q7.23 & 7.24: 编写你自己的Screen类。
#### A: 见7-23.h

----
### 返回*this的成员函数
* 返回引用的函数是左值的，即返回的是调用这个函数的对象的本身；
* 返回*this可以实现函数的连续调用，如
````c++
myScreen.move(4).set('#');
````
* const成员函数如果以引用的形式返回*this，则返回的对象被转换成常量引用。
* 常量对象只能调用常量成员函数，而非常量成员函数即可调用常量成员函数也可调用非常量成员函数
* 当非常量成员函数调用常量成员函数时，**this指针会被隐式地转换为指向常量的指针，但该常量属性只在常量函数内有效**，如
````c++
class Screen{
public:
    Screen &display(std::ostream &os)
    {
        do_display(os); // this指针被隐式转换为指向常量的指针，隐式转换的常量属性只在do_display内有效；
        return *this;   // 解引用后得到非常量对象
    }
    // 重载为常量函数，返回类型只能是常量，this指针被隐式转换为指向常量的指针
    const Screen &display(std::ostream &os) const
    {
        do_display(os); // this指针以及是指向常量的指针，不用再转换。
        return *this;  // 在该函数内，this指针始终指向常量，所以解引用后得到的对象是常量，所以返回类型只能是常量类型。
    }
private:
    // 常量函数
    void do_display(std::ostream &os) const
    {
        os << contents;
    }
    std::string contents;
};
````
----
#### Q7.27: 给你自己的Screen类添加 move, set和display函数，通过执行下面的代码检验你的类是否正确。
````c++
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
````
#### A:见7-23.h和7-23.cpp。
### 将类前向声明的用途(不完全类型)：定义指向这种类型的指针或引用，以这种不完全类型作为参数或者返回类型的函数。
### 可以在类内部声明指向自身的指针或引用，但不能是普通对象
#### Q7.31: 定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。
#### A: 将类Y进行前向声明。
````c++
class Y;
class X{
    Y *py;
};

class Y{
    X x;
};
````
### 如果一个类指定了友元类，则友元类的成员函数可以访问此类包括非公有成员在内的所有成员:
* 友元类声明
````c++
class A{
    friend class B;    
};
// B可以访问Ａ的所有成员
class B{
    
};
````
### 友元关系不存在传递性。(ps:朋友的朋友不一定是朋友。):
````c++
class A{
    friend class B;    
};
// B可以直接访问Ａ的所有成员
class B{
    frend class C;
};
// C可以直接访问B的所有成员，但不能直接访问A的任何成员.
class C{};
````
###　声明成员函数作为友元，不是真的声明函数，所以需要先声明函数再声明才能使用友元：
````c++
// B可以访问Ａ的所有成员
class B{
   void func(); 
};

class A{
    // 友元函数必须在A类之前被声明
    friend void B::func();    
};
````
#### Q7.32: 定义你自己的Screen和Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。
#### 编译器处理完类中的全部声明后才会处理成员函数的定义。
#### 类型名不能覆盖类作用域外的声明：
````c++
typedef double Money;
class Account{
public:
    Money balance(){return bal;} // 使用外层作用域的Money.
private:
    typedef double Money; // 错误：不能重新定义Money.
    Money bal;
};
````
#### Q7.34: 如果我们把第256页的Screen类的pos的typedef放在类的最后一行会发生什么情况？
#### A: 使用pos的时候会报错，显示pos是不可知的。因此，在使用类型名之前，必须先声明。
#### Q7.35: 解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
````c++
typedef string Type;
Type initVal();
class Exercise{
public:
    typedef double Type; // 错误：不能重复定义Type，删除该定义或重命名
    Type setVal(Type);
    Type initVal();
private:
    int val;
};

Type Exercise::setVal(Type parm)
{
    val = parm + initVal(); // 成员函数initVal().
    return val;
}
````

----
### 构造函数
* 必须通过构造函数初始值列表进行初始化的案例：
    * 成员是const或引用时必须执行初始化，而不是在构造函数中赋值
    * 成员是某种类类型且该类没有默认构造函数时
    * 初始值列表不限定顺序，编译器会自动根据数据成员在类中声明的顺序进行初始化；特例，某个数据成员被另一个成员初始化时，必须注意初始化顺序：
````c++
 class X{
    int i;
    int j;
    // 改正初始化顺序
    //int j;
    //int i;
public:
    // i是未定义的，看似j先被初始化了，然后再用j初始化i;
    // 但实际初始化顺序是先i后j，再初始化i时j是未定义的。
    // 修改：将数据成员的声明顺序对调一下即可。
    x(int val) : j(val), i(j){}
}; 
````
* 所有形参都有默认值（常用的是１个形参）的构造函数具有两个特征：默认构造函数和提供给定实参的构造函数：
````c++
class A{
public:
    A(int a = -1){}
};

// 实例化
A a1;   // 实现默认构造函数的功能
A a2(0);
````
* 委托构造函数：　重复利用已有的构造函数进行初始化
````c++
class Sales_data{
public:
    // 非委托构造函数
    Sales_data(std::string s, unsigned cnt, double price) : 
        bookNo(s), units_sold(cnt), revenue(cnt*price){}
    // 委托上面的构造函数进行初始化
    Sales_data() : Sales_data("", 0, 0){}
    // 委托第一个构造函数进行初始化
    Sales_data(std::string s) : Sales_data("", 0, 0){}
    // 委托第二个构造函数进行初始化
    Sales_data(std::istream &is) : Sales_data(){read(is, *this);}
};
````
----
#### Q7.36:下面的初始值是错误的，请找出问题所在并尝试修改它。
````c++
struct X{
    X(int i, int j) : base(i), rem(base%j){} // 实际上，base在rem之后初始化，引发未定义行为
//    int rem, base;
    // 修改为
    int base, rem;
};
````
#### Q7.38:有些情况下我们希望提供cin作为接受istream&参数的构造函数的默认实参，请声明这样的构造函数。
#### A:
````c++
class A{
public:
    A(std::istream& is);
};
````
#### Q7.43: 假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。定义类C,C有一个NoDefault类型的成员，定义C的默认构造函数。
#### A:见7-43.cpp。
````c++
#include <iostream>
#include <vector>

class NoDefault{
public:
    NoDefault(int a) : i(a){}

private:
    int i;
};

class C{
public:
    C() : obj(-1){}
//    C(){} // 错误，要求显示初始化成员obj。
private:
    NoDefault obj;
};

int main()
{
    C c;
    return 0;
}
````
#### Q7.44:下面这条声明合法吗？如果不，为什么？
````c++
vector<NoDefault> vec(10);
````
#### A:不合法，NoDefault类没有默认构造函数，不能构造除对象元素;修改为：
````c++
vector<NoDefault> vec(10, NoDefault(0));
````
#### Q7.46: 下面哪些论断是不正确的？为什么？
(a) 一个类必须至少提供一个构造函数。　// 错，简单类（不包含其他类类型）可以不提供构造函数，编译器会自动创建一个。
(b) 默认构造函数是参数列表为空的构造函数。　// 错，参数列表全是默认参数的构造函数也是默认构造函数。
(c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。 // 错，即使用默认构造函数初始化一些无意义的初始值也是有用的，避免不可知的行为发生。
(d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应的默认值。 // 错，只有没有自己定义构造函数的类，编译器才会自动生成一个；而且，不是所有数据成员都能被初始化，如某种没有定义默认构造函数的类类型不能初始化。

----
### 隐式的类类型转换
* 能通过一个实参调用的构造函数(只有一个形参的构造函数、第一个形参无默认值，其他形参都有默认值、所有形参都有默认值三种构造函数)定义了一条从构造函数的参数类型向类类型隐式转换的规则：
````c++
class Sales_data{
public:
    // 非委托构造函数
    Sales_data(std::string s, unsigned cnt, double price) : 
        bookNo(s), units_sold(cnt), revenue(cnt*price){}
    // 委托上面的构造函数进行初始化
    Sales_data() : Sales_data("", 0, 0){}
    // 委托第一个构造函数进行初始化
    Sales_data(std::string s) : Sales_data("", 0, 0){}
    // 委托第二个构造函数进行初始化
    Sales_data(std::istream &is) : Sales_data(){read(is, *this);}
};

string null_book = "三体";
Sales_data item;
item.combine(null_book); //编译器会调用第三个构造函数自动创建一个Sales_data对象；
item.comint(std::cin); // 调用第四个构造函数创建一个临时的Sales_data对象；
// 拷贝形式初始化也会进行隐式类类型转换
Sales_data item1 = null_book;
````
* 只允许进行一步隐式类类型转换:
````c++
item.combine("藏地密码"); // 错误：没有对应字符串字面值常量的构造函数；需要先把字符串字面值转换为string对象,然后转转换为Sales_data对象，但不允许。
// 改正为
item.combine(std::string("藏地密码"));
````

* 使用关键字`explicit`抑制隐式的类类型转换,在构造对象时强制只能执行直接初始化或显示使用构造函数进行转换
````c++
class Sales_data{
public:
    // 非委托构造函数
    Sales_data(std::string s, unsigned cnt, double price) : 
        bookNo(s), units_sold(cnt), revenue(cnt*price){}
    // 委托上面的构造函数进行初始化
    Sales_data() : Sales_data("", 0, 0){}
    // 委托第一个构造函数进行初始化
    explicit Sales_data(std::string s) : Sales_data("", 0, 0){}
    // 委托第二个构造函数进行初始化
    Sales_data(std::istream &is) : Sales_data(){read(is, *this);}
};
string null_book = "三体";
Sales_data item;
item.combine(null_book); //错误
item.combine(Sales_data(num_book)); // 正确：显示使用构造函数进行转换。
item.combine(static_cast<Sales_data>(num_book)); // 正确：显示使用构造函数进行转换。
item.comint(std::cin); // 正确
// 拷贝形式初始化也会进行隐式类类型转换
Sales_data item1 = null_book; // 错误
Sales_data item2(null_book); // 正确
````
----
#### Q7.49: 对于combine函数的三种不同声明，当我们调用i.combine(s)时分别发生什么情况？其中i是一个Sales_data，而s是一个string对象。
````c++
Sales_data &combine(Sales_data); // 正确：进行了隐式转换
Sales_data &combine(Sales_data&); // 错误：不能创建一个Sales_data的临时对象绑定到string对象上；相当于Sales_data &temp = Sales_data(s);非常量引用右值是非法的
Sales_data &combine(const Sales_data&); // 正确：右值只能被 const 类型的 reference 所指向，非 const 的引用则是非法的；相当于const Sales_data &temp = Sales_data(s).
````
#### Q7.52: vector将其但参数的构造函数定义为explicit的，而string则不是，你觉得原因何在？
#### A: 因为当定义一个int类型的vector对象时，如果单参数构造函数不是explicit的，会出现含义不明确的情况，如：
````c++
vector<int> ivec(10); // ivec的包含10个元素；
vector<int> ivec = 10; // 开发者的意图可能是定义10个元素的vector对象，也可能是定义只包含1个元素的vector对象，初始值为10；
````
#### 而string则不存在这种歧义:`string s("hello");`和`string s = "hello"`的含义都很明确，就是创建一个string对象s，它的初始值是hello.
###聚合类：
* 所有成员都是public的
* 没有定义任何构造函数
* 没有类内初始值
* 没有基类，也没有virtual函数（所以可以有成员函数）
#### Q7.52: 使用2.6.1(第64页)的Sales_data类，解释下面的初始化过程。如果存在问题，尝试修改它。
````c++
//64页的Sales_data定义
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0.0;
    double revenue = 0.0;
};
Sales_data item = {"978-0590353403", 25, 15.99};
````
#### A: Sales_data不是聚合类，因其内部成员有类内初始值，因此不能用花括号的初始值列表进行初始化。
### 字面值常量类：
* 数据成员都是字面值类型的聚合类
* 或满足一下条件：
    * 数据成员都必须是字面值类型
    * 类必须至少含有一个constexpr构造函数
    * 如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式；或者如果成员属于某种类型，则初始值必须使用成员自己的constexpr构造函数
    * 类必须使用析构函数的默认定义（即不能自己定义析构函数）
* 用途,即自定义字面值常量，可以用于编译时初始化一些const变量：So the advantage of the "literal type" rules is that they allow you to define new class types that can be used in constant expressions.参考:[When should literal classes be used in C++?](https://stackoverflow.com/questions/14307996/when-should-literal-classes-be-used-in-c)
### 静态成员的特性
* 类内初始化：只能为字面值常量类型的静态成员提供const整数类型的类内初始值；
* 静态成员可以使不完全类型，如静态成员的类型可以使它所属类的类类型，非而非静态成员则只能是指针或引用；
````c++
class Bar{
public: 
    // ...
private: 
    static Bar mem1; // 正确
    Bar *mem2; // 正确
    Bar mem3;  // 错误。
};
````
* 静态成员属于整个类所有，不需要依赖任何对象,需要在类外单独分配空间(所以需要在类外定义)
* 可以通过类名直接访问public静态成员
* 可以通过对象名访问public静态成员
* 成员函数可以直接访问静态成员变量
* 从命名空间的角度理解：
    * 类的静态成员只是类这个命名空间中的全局变量和全局函数
    * 不同的是，类可以对静态成员进行访问权限的限制，而命名空间不行
* 从面向对象的角度理解：
    * 类的静态成员属于类概念本身
    * 类的所有对象共享相同的静态成员
#### Q7.58:下面的静态数据成员的声明和定义有错误吗？请解释原因。
````c++
// example.h
class Example{
public:
    static double rate = 6.5; //　错误：非字面值类型的静态成员不能在类内初始化。
    static const int vecSize = 20;// 错误：非字面值类型的静态成员不能在类内初始化。
    static vector<double> vec(vecSize);// 错误：非字面值类型的静态成员不能在类内初始化。
};
````