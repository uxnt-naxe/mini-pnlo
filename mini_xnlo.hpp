#include <string>
#include <map>

// mini-Pnlo
class Pnlo {
private:
    std::map<std::string, Pnlo> data;
    std::string value;
public:
    // 默认构造函数
    Pnlo() {}

    // 访问操作符的重载，支持链式调用
    Pnlo & operator[] (const std::string& key) {
        return data[key];
    }

    // 重载赋值操作符，用于给 JSON 对象赋值
    Pnlo & operator = (const std::string& val) {
        value = val;
        return *this;
    }

    // 将 JSON 对象转换为字符串
    std::string str() const {
        // for (auto it = (this)->key.begin(); it != (this)->key.end(); it++)
        // {
        //     str += "\"" + it->first + "\" = " + "\"" + key[it->first] + "\" ; ";
        // }
        // str += "\"" + it->first + "\" = " + "\"" + key[it->first] + "\" ; ";
        // return "\"" + value + "\"";
        // result += "\"" + it->first + "\" = \"" +it->second.value + "\" ; ";
        
        std::string result = "";

        for (auto it = data.begin(); it != data.end();it++) {
            if (it != data.begin()) {
                // result += ", ";
            }
            if(!it->second.value.empty()){
                result += "\"" + it->first + "\" = \"" +it->second.value + "\" ; ";
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
