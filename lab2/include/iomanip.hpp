/* Custom manipulators.
 * @file
 * @date 2018-08-05
 * @author Anonymous
 */

#ifndef __IOMANIP_HPP__
#define __IOMANIP_HPP__

#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <cmath>

//{ endm manipulator
inline std::ostream& endm(std::ostream& os) {
    return os << "[eol]\n";
}
//}

//{ sin manipulator
struct SinManipulator {
    // flag
};

class SinWithStream {
    std::ostream* stream;
public:
    SinWithStream(std::ostream* s) : stream(s) {}
    
    std::ostream& operator<<(int value) {
        double result = std::sin(value);
        if (result == 0.0) return *stream << "0.0";
        else return *stream << result;
    }

    std::ostream& operator<<(double value) {
        double result = std::sin(value);
        if (result == 0.0) return *stream << "0.0";
        else return *stream << result;
    }

    std::ostream& operator<<(const std::string& value) {
        if (value == "pi") return *stream << "sin(pi)";
        else return *stream << "ERROR";
    }
};

inline SinWithStream operator<<(std::ostream& os, SinManipulator) {
    return SinWithStream(&os);
}

namespace manip {
    inline SinManipulator sin;
}
//}

//{ add manipulator
class AddManipulator {
    // flag
};

class AddWithStream {
    std::ostream& stream;
public:
    AddWithStream(std::ostream& s) : stream(s) {} // constructor
    
    class AddWithFirst {
        std::ostream& stream;
        
        // Different types
        int first_int;
        double first_double;
        std::string first_str;
        
        enum class Type { INT, DOUBLE, STRING } type;
        
    public: 
        // constructor different types
        AddWithFirst(std::ostream& s, int f) 
            : stream(s), first_int(f), type(Type::INT) {}
        
        AddWithFirst(std::ostream& s, double f) 
            : stream(s), first_double(f), type(Type::DOUBLE) {}
        
        AddWithFirst(std::ostream& s, const std::string& f) 
            : stream(s), first_str(f), type(Type::STRING) {}
        
        // (int)
        std::ostream& operator<<(int second) {
            switch(type) {
                case Type::INT: return stream << (first_int + second);
                case Type::DOUBLE: return stream << (first_double + second);
                case Type::STRING: return stream << (first_str + std::to_string(second)); 
            }
            return stream;
        }
        
        // (double)
        std::ostream& operator<<(double second) {
            switch(type) {
                case Type::INT: return stream << (first_int + second);
                case Type::DOUBLE: return stream << (first_double + second);
                case Type::STRING: return stream << (first_str + std::to_string(second));
            }
            return stream;
        }
        
        // (string)
        std::ostream& operator<<(const std::string& second) {
            switch(type) {
                case Type::INT: return stream << (std::to_string(first_int) + second);
                case Type::DOUBLE: return stream << (std::to_string(first_double) + second);
                case Type::STRING: return stream << (first_str + second);
            }
            return stream;
        }
    };
    
    // operator "AddWithStream << data"
    AddWithFirst operator<<(int first) {
        return AddWithFirst(stream, first);
    }
    
    AddWithFirst operator<<(double first) {
        return AddWithFirst(stream, first);
    }
    
    AddWithFirst operator<<(const std::string& first) {
        return AddWithFirst(stream, first);
    }
};

inline AddWithStream operator<<(std::ostream& os, const AddManipulator&) {
    return AddWithStream(os);
}

// init manipulator
inline AddManipulator add;
//}

#endif // __IOMANIP_HPP__
