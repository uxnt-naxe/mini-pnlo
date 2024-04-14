#include <iostream>
#include <string>
#include <list>
#include <map>

// mini-Pnlo
class Pnlo {
public:
    enum Type {
        pnlo_null = 0,  // null value
        pnlo_bool,      // bool value
        pnlo_int,       // integer value
        pnlo_double,    // double value
        pnlo_string,    // string value
        // -----------------------------
        // pnlo_key_value, // key value
        pnlo_array,     // array value
        pnlo_object     // object value
    };
    


    // 默认构造函数
    Pnlo() {}   // ! ok

    // 访问操作符的重载，支持链式调用
    Pnlo & operator[] (const std::string& key) {
        return m_object[key];
    }   // ! ok

    // 重载赋值操作符，用于给 Pnlo 对象赋值
    Pnlo & operator = (const std::string& val) {
        m_value = val;
        return *this;
    }

    operator std::string() {
        return m_value;
    }

    // 将 Pnlo 对象转换为字符串
    std::string str() const {
        std::string result = "";
        for (auto it = m_object.begin(); it != m_object.end();it++) { 
            if (it != m_object.begin()) {
                // result += " , ";
            }
            if(!it->second.m_value.empty()){
                result += "\"" + it->first + "\" = \"" +it->second.m_value + "\" ; ";
            } else { 
                result += "\"" + it->first + "\" > ";
                result += it->second.str();
                result += "~ ";
            }
        }
        return result;
    }

// 私用
private:
    Type m_type;                               // 类型
    std::map<std::string, Pnlo> m_object;      // 链式调用 ok
    std::string m_value;                       // value 值
    // std::list<Pnlo> m_array;                  // ???
};















int main() {
    // API
    Pnlo ptest = Pnlo();
    ptest["1"] = "hello";  // 不许重复键！
    ptest["a"]["b"]["c"]["d"]["ok"] = "ohhhhh!";
    ptest.str();  // 生成pnlo的内容这样
    std::cout << ptest.str() << std::endl;
}
