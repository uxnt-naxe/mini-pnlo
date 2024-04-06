#include <string>
#include <map>

class Knlo {
private:
    std::map<std::string, Knlo> m_obj;        // 链式调用 ok
    std::string m_value;                      // value 值
public:
    // 默认构造函数
    Knlo() {}

    // 重载[]运算符以实现链式访问
    Knlo & operator[](const std::string& key) {
        return m_obj[key];
    }
    
    // 重载=运算符以设置值
    // void operator = (const std::string& val) {
    //     // (*m_value) = std::string(val);
    //     m_value = val;
    // }

    // 重载赋值操作符，用于给 Knlo 对象赋值
    Knlo & operator = (const std::string& val) {
        m_value = val;
        return *this;
    }

    operator std::string() {
        return m_value;
    }

    // 转换为字符串
    /*
    std::string toString() const {
        std::string result;
        for (const auto pair : m_obj) {
            result += "\"" + pair.first + "\" > ";
        }
        // result += (*m_obj)->second.toString();//   pair.
        result += "\"" + m_value + "\" ; ~~";
        return result;
    }
    */

    // 将 Knlo 对象转换为字符串
    std::string str() const {
        std::string result = "";
        for (auto it = m_obj.begin(); it != m_obj.end();it++) {
            if (it != m_obj.begin()) {
                // result += ", ";
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

};


// mini-Pnlo
class Pnlo {
private:
    std::map<std::string, Pnlo> m_obj;        // 链式调用 ok
    std::string m_value;                      // value 值
public:
    // 默认构造函数
    Pnlo() {}   // ! ok

    // 访问操作符的重载，支持链式调用
    Pnlo & operator[] (const std::string& key) {
        return m_obj[key];
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
        for (auto it = m_obj.begin(); it != m_obj.end();it++) { 
            if (it != m_obj.begin()) {
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
};















// mini-Xnlo
typedef std::map<std::string, std::string> xValue;
struct Xnlo : std::map<std::string, Xnlo> {
    xValue key;
    std::string str() {
        std::string str = "";
        for (auto it = (this)->key.begin(); it != (this)->key.end(); it++)
        {
            str += "\"" + it->first + "\" = " + "\"" + key[it->first] + "\" ; ";
        }
        for (auto it = (this)->begin(); it != (this)->end(); it++)
        {
            if (it != (this)->begin())
            {
                // str += "\n";
                // std::cout <<  "\"" << it->first << "\":";
            }
            if (it != (this)->end())
            {
                // str += "\n";
                // std::cout <<  "\"" << it->first << "\":";
            }
            // std::cout <<  "\"" << it->first << "\" > ";
            str += "\"" + it->first + "\" > ";
            str += it->second.str();
            str += "~";
            
        }
        return str;
    }
};
