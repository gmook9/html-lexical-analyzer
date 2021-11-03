//
// Template by Ali A. Kooshesh on 1/27/21.
// Additional Code by Garret Mook on 02/06/21.

#ifndef PROJECT1PHASE1_TOKEN_HPP
#define PROJECT1PHASE1_TOKEN_HPP

#include <string>

class Token {
public:
    Token(int, int);
    bool &isOpenTag();
    bool &isCloseTag();

    bool &isCloseAngleBracket();

    bool &endOfFile();
    bool &isCloseStandAloneTag();


    std::string tagName();
    //Self Added

    void makeOpenTag(std::string);
    void makeCloseTag(std::string);
    //Self Added
    std::string makeOpenTag();
    bool &isSlash();

    void print();



    bool &eol();

private:
    bool _isOpenTag, _isCloseTag, _isCloseAngleBracket,
            _eof, _isCloseStandAloneTag, _eol, _isSlash;
    std::string _tagName;
    int _lineNumber, _charPos;


};


#endif //PROJECT1PHASE1_TOKEN_HPP
