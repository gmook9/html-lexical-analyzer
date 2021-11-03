//
// Template by Ali A. Kooshesh on 1/27/21.
// Additional Code by Garret Mook on 02/06/21.


#include <iostream>
#include <iomanip>
#include "Token.hpp"

Token::Token(int line, int pos): _isOpenTag{false},
                                 _isCloseTag{false},
                                 _isCloseAngleBracket{false},
                                 _isCloseStandAloneTag{false},
                                 _tagName{""},
                                 _eof{false},
                                 _lineNumber{line},
                                 _charPos{pos},
                                 _eol{false},
                                 _isSlash{false} {}

bool &Token::isOpenTag() { return _isOpenTag; }
bool &Token::isCloseTag() { return _isCloseTag; }

bool &Token::isCloseAngleBracket() { return _isCloseAngleBracket; }

bool &Token::endOfFile() { return _eof; }
bool &Token::isCloseStandAloneTag() { return _isCloseStandAloneTag; }
bool &Token::isSlash() { return _isSlash; }

std::string Token::tagName() { return _tagName; }


bool &Token::eol(){
    return _eol;

}

void Token::makeOpenTag(std::string name) {
    _tagName = name;
    isOpenTag() = true;
}
std::string Token::makeOpenTag() {
    return _tagName;
}
void Token::makeCloseTag(std::string name) {
    _tagName = name;

    isCloseTag() = true;
}
/*
void Token::print() {
    std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";

    if(isOpenTag()) {
        std::cout << "<" << tagName() << std::endl;
    } else if(isCloseStandAloneTag()) {
        std::cout << "/>" << std::endl;
    }  else if(isCloseAngleBracket()) {
       std::cout << ">" << std::endl;
   } else if(isCloseTag()) {
     std::cout << "</" << tagName() << std::endl;
  } else if(isSlash() ) {

    }
    else {// more else if's before this else
        std::cout << "Unknown" << std::endl;
    }
}
*/



void Token::print() {

    if(isOpenTag()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "<" << tagName() << std::endl;
    } else if(isCloseStandAloneTag()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "/>" << std::endl;
    }  else if(isCloseAngleBracket()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << ">" << std::endl;
    } else if(isCloseTag()) {
        std::cout << "[" << std::setw(2) << _lineNumber << ", " <<  std::setw(3) << _charPos << "] ";
        std::cout << "</" << tagName() << std::endl;
    } else if(isSlash() ) {

    }
    else {// more else if's before this else
        std::cout << "Unknown" << std::endl;
    }
}