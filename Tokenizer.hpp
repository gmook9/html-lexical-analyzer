//
// Template by Ali A. Kooshesh on 1/27/21.
// Additional Code by Garret Mook on 02/06/21.


//READER/LEXICAL ANALZYER
// Definition Of Datatype

#ifndef PROJECT1PHASE1_TOKENIZER_HPP
#define PROJECT1PHASE1_TOKENIZER_HPP

#include <string>
#include <fstream> //used for reading writing files
#include "Token.hpp"

class Tokenizer {

public:
    //Operations(functions) that we perform on the datatype
  Tokenizer(std::string);

    Token getToken();

private:
    int lineNumber, charPosition;
    std::string inputFileName;
    std::ifstream inputStream; //declare input-stream variable

    bool charOfInterest(char c);
};

#endif //PROJECT1PHASE1_TOKENIZER_HPP
