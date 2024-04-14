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
// m_type :
    ~Pnlo(){}
    Pnlo():m_type(pnlo_null){}
    Pnlo(Type type):m_type(type){
        switch (m_type){
            case pnlo_null:
                break;
            case pnlo_bool:
                break;
            case pnlo_int:
                break;
            case pnlo_double:
                break;
            case pnlo_string:
                m_value = "";
                break;
            case pnlo_array:
                break;
            case pnlo_object:
                m_object = std::map<std::string, Pnlo>();
                break;
            default:
                break;
        }
    }
    Type type() const { return m_type; }







    // 访问操作符的重载，支持链式调用
    Pnlo & operator[] (const std::string& key) {
        if (m_type != pnlo_object)
        {
            // clear(); ?
            m_type = pnlo_object;
            m_object = std::map<std::string, Pnlo>();
            // std::cout << "Obj初化" << std::endl;
        }
        // std::cout << "Obj已经有了" << std::endl;
        return m_object[key];
    }   // ! ok

    // 重载赋值操作符，用于给 Pnlo 对象赋值
    Pnlo & operator = (const std::string& val) {
        m_type = pnlo_string;
        m_value = val;
        return *this;
    }

    operator std::string() {
        if (m_type != pnlo_string) { throw std::logic_error("function Pnlo::operator (string) requires string value"); }
        return m_value;
    } // ok

    // 将 Pnlo 对象转换为字符串
    std::string str() const {
        std::string result = "";
        switch (m_type)
        {
            case pnlo_null:
                result = "null" ;
                break;
            case pnlo_bool:
                result += m_value;
                break;
            case pnlo_int:
                result += m_value;
                break;
            case pnlo_double:
                result += m_value;
                break;
            case pnlo_string:
                result += "\"" + m_value + "\"";
                break;
            case pnlo_array:
                break;
            case pnlo_object:
                {
                    for (auto it = m_object.begin(); it != m_object.end(); it++) {
                        if (it != m_object.begin()) {
                            // result += " , ";
                        }
                        if (!it->second.m_value.empty()) {
                            result += "\"" + it->first + "\"";
                            result += " = ";
                            result += it->second.str();
                            result += " ; ";
                        } else {
                            result += "\"" + it->first + "\"";
                            result += " > ";
                            result += it->second.str();
                            result += " ~ ";
                        }
                    }
                }
                break;
            default:
                break;
        }
        
        // std::cout << m_type << std::endl;
        return result;
    }

// 私用
private:
    Type m_type;                               // 类型
    std::map<std::string, Pnlo> m_object;      // 链式调用 ok
    std::string m_value;                       // value 值
    
    // ???
    // std::list<Pnlo> m_array;                  
    // bool m_bool;
    // int m_int;
    // double m_double;
};















int main() {
    // API
    Pnlo ptest = Pnlo();
    ptest["1"] = "hello";  // 不许重复键！
    ptest["a"]["b"]["c"]["d"]["ok"] = "ohhhhh!";
    ptest.str();  // 生成pnlo的内容这样
    std::cout << ptest.str() << std::endl;
}
