#include <string>
#include <map>

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
