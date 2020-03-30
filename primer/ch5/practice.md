#### swich语句注意点：
* case标签必须是整型常量表达式:
````c++
char ch = getVal();
int ival = 42;
switch(ch){
case 3.14: // 错误：必须是整型
case ival: // 错误：必须是常量
}
````
* 变量必须定义在块内
````c++
ｃase true:
{
    string file_name;
    int ival = 0;
    int jval;
    break;
}
case false:
if(file_name.empty()) // 错误：　file_name不在作用域之内。
````
#### Q5.9: 编写一段程序，使用一系列if语句统计从cin读入的文本中有多少元音子们。
#### A:见5-9.cpp。
#### Q5.10: 我们之前实现的统计元音字母的程序存在一个问题：如果元音字母以大写形式出现，不会被统计在内。编写一段城西，既统计元音字母的小写形式，也统计大写形式，也就是说，新程序遇到'a'和'A'都应该递增aCnt的值，以此类推。
#### A: 将输入的字母都转换为小写字母，见5-10.cpp。