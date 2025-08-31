//
// Created by zach on 8/31/25 using zPc-i2.
//

#ifndef LOGGING_H
#define LOGGING_H

// fresh from stackoverflow
// https://stackoverflow.com/questions/15305310/predefined-macros-for-function-name-func
// enjoj
#ifndef __FUNCTION_NAME__
    #if defined __func__
        // Undeclared
        #define __FUNCTION_NAME__   __func__
    #elif defined __FUNCTION__
        // Undeclared
        #define __FUNCTION_NAME__   __FUNCTION__
    #elif defined __PRETTY_FUNCTION__
        // Undeclared
        #define __FUNCTION_NAME__   __PRETTY_FUNCTION__
    #else
        // Declared
        #define __FUNCTION_NAME__   "N/A"
    #endif // __func__

#endif // __FUNCTION_NAME__

#define FILE_NAME (__FILE__ + std::string(__FILE__).find_last_of("\\/") + 1)
#define GET_LOG_LINE(...) FuckAss::getLog(__FUNCTION_NAME__, FILE_NAME, __LINE__, __VA_ARGS__)

template<typename ... A>
std::string getLog(const char *function, const char *file, const int line, A &&...a) {
    std::ostringstream oss;

    oss << "[" << function << " - " << file << ": " << line << "] ";
    (oss << ... << std::forward<A>(a));
    return oss.str();
}

#endif //FUCKASS_LOGGING_H