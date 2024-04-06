## mini-xnlo 0.0.1 (mini - X Neon Light Object)

xnlo 配置文件代码语法API简化比较好，快速生成xnlo配置文件。支持压缩代码、更多嵌套。

不许重复键！

```c
#include "mini_xnlo.hpp"
// API
Xnlo test = Xnlo();
test.key["a"] = "hello";
test["a"]["b"]["c"]["d"].key["ok"] = "ohhhhh!";
test.str();  // 生成xnlo的内容这样
std::cout << test.str() << std::endl;

Pnlo ptest = Pnlo();
ptest["a"] = "hello";
ptest["a"]["b"]["c"]["d"]["ok"] = "ohhhhh!";
ptest.str();  // 生成pnlo的内容这样
std::cout << ptest.str() << std::endl;

```
## 程序的test输出这样:
```
"a" = "hello" ; "a" > "b" > "c" > "d" > "ok" = "ohhhhh!" ; ~~~~
"a" = "hello" ; "a" > "b" > "c" > "d" > "ok" = "ohhhhh!" ; ~~~~
```
