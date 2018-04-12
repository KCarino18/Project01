#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
//Used example by g40 on github.
// TODO: Write your JSON class hierarchy here.
#include <math.h>
#include <cmath>
#include <limits>
#include <float.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>
#include <string>


 namespace JSON {
    char* LargestInt;
    unsigned int LargestUInt;
    int Int;
    unsigned int UInt;

    class Value;

    class Writer
    {
    public:
       virtual ~Writer();
       virtual std::string write( const Value &root ) = 0;
    };

    class FastWriter : public Writer
    {
    public:
       FastWriter();
       virtual ~FastWriter(){}

       void enableYAMLCompatibility();

    public:
       virtual std::string write( const Value &root );

    private:
       void writeValue( const Value &value );

       std::string document_;
       bool yamlCompatiblityEnabled_;
    };

    class StyledWriter: public Writer
    {
    public:
       StyledWriter();
       virtual ~StyledWriter(){}

    public:
       virtual std::string write( const Value &root );

    private:
       void writeValue( const Value &value );
       void writeArrayValue( const Value &value );
       bool isMultineArray( const Value &value );
       void pushValue( const std::string &value );
       void writeIndent();
       void writeWithIndent( const std::string &value );
       void indent();
       void unindent();
       void writeCommentBeforeValue( const Value &root );
       void writeCommentAfterValueOnSameLine( const Value &root );
       bool hasCommentForValue( const Value &value );
       static std::string normalizeEOL( const std::string &text );

       typedef std::vector<std::string> ChildValues;

       ChildValues childValues_;
       std::string document_;
       std::string indentString_;
       int rightMargin_;
       int indentSize_;
       bool addChildValues_;
    };

    class StyledStreamWriter
    {
    public:
       StyledStreamWriter( std::string indentation="\t" );
       ~StyledStreamWriter(){}

    public:
       void write( std::ostream &out, const Value &root );

    private:
       void writeValue( const Value &value );
       void writeArrayValue( const Value &value );
       bool isMultineArray( const Value &value );
       void pushValue( const std::string &value );
       void writeIndent();
       void writeWithIndent( const std::string &value );
       void indent();
       void unindent();
       void writeCommentBeforeValue( const Value &root );
       void writeCommentAfterValueOnSameLine( const Value &root );
       bool hasCommentForValue( const Value &value );
       static std::string normalizeEOL( const std::string &text );

       typedef std::vector<std::string> ChildValues;

       ChildValues childValues_;
       std::ostream* document_;
       std::string indentString_;
       int rightMargin_;
       std::string indentation_;
       bool addChildValues_;
    };


    std::ostream& operator<<( std::ostream&, const Value &root );

 } // namespace Json
