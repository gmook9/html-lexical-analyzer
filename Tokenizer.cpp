// Template by Ali A. Kooshesh on 1/27/21.
// Additional Code by Garret Mook on 02/06/21.

//READER/LEXICAL ANALYZER
//Implemenation Of Operations

#include <iostream>
#include "Tokenizer.hpp"
#include <string>
#include <vector>
//
#include <cstdio>
#include <cmath>
#include <stdio.h>
#include <ctype.h>

//Initializer List
Tokenizer::Tokenizer(std::string name): lineNumber{1},
                                        charPosition{1},
                                        inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}
//This defines what a Character of interest is to the reader.
bool Tokenizer::charOfInterest(char c) {
    // is c the initial (or the sole) character of a token?
    return c == '<' || c == '>' || c == '/';
}

Token Tokenizer::getToken() {
    char c;
    //Checks to see if the file we are trying to read is open
    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    //GM: This while loop executes until we find a charOfInterest
    while( inputStream.get(c) && ! charOfInterest(c) ) {
        // keep track of the line number and the character position here.
        if (c == '\n') {
           lineNumber++;

       }
        else {
           charPosition++;
       }

    }


    //GM: After loop stops this executes
    Token token(lineNumber, charPosition);

    if( inputStream.eof() ) {
        token.endOfFile() = true;
    }
//  if < is found
    else if( c == '<'  && inputStream.peek() != '/' && inputStream.peek() != '>') {
        if( isalpha(inputStream.peek())  ) {
            charPosition++;
            std::string needthisforPeek;
            while (inputStream.get(c) && isalpha(c) && !isspace(c) && inputStream.peek() != '/') {
                needthisforPeek =  needthisforPeek + c;
                charPosition++;
            }

            inputStream.putback(c);
            token.makeOpenTag(needthisforPeek);
            return token;
        }
    }

    /*
        //  if /> is found
     else if (c == '/' && inputStream.peek() == '>') {
        inputStream.get(c);
        token.isCloseStandAloneTag() = true;
    }
    */


    else if (c == '/')  {
         if (c == '/' && isalpha(inputStream.peek()) ) {
            token.isSlash() = true;
             charPosition++;

        }  else if (c == '/' && inputStream.peek() == '>') {
            inputStream.get(c);
            token.isCloseStandAloneTag() = true;
             charPosition++;
        }


    }







//  if > is found
     else if( c == '>' ) {
        token.isCloseAngleBracket() = true;
        charPosition++;
  }
        //  if <tagname is found then it is NOT a closed standalone tag
  else if (isalpha(inputStream.peek())) {
        token.isCloseStandAloneTag() = false;
        charPosition++;
    }

    //IF </ is found
    else if ( inputStream.good() && c == '<'  && inputStream.peek() == '/') {
        inputStream.get(c);
        charPosition++;
        std::string neededToReadPeek;
        if (c== '/' && isalpha(inputStream.peek())) {
            while (inputStream.good() && inputStream.get(c) && isalpha(c)) {
                neededToReadPeek += c;
                charPosition++;
            }
            inputStream.putback(c);
            token.makeCloseTag(neededToReadPeek);
            charPosition++;
            return token;
        }
    }

    else {
        std::cout << "Unknown Character: " << c;
        exit(1);
}

    return token;

}
