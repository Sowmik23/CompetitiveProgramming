//https://linuxhint.com/regular-expression-basics-cpp/


1. a regular expression “a[a-z]” can have values ‘aa’, ‘ab’,’ ax’ etc.
Here a has a literal meaning and [a-z] denotes any lowercase character from a to z.


Range Specifications:
we can specify a range of lowercase letters from a to z as follows:
[a-z]

This will match exactly one lowercase character.

The following criteria,

[A-Za-z0-9]
The above expression specifies the range containing one single uppercase character, one lowercase character and a digit from 0 to 9.

The brackets ([]) in the above expressions have a special meaning i.e. they are used to specify the range. If you want to include a bracket
as part of an expression, then you will need to escape it.

So the following expression,

[\[0-9]
The above expression indicates an opening bracket and a digit in the range 0 to 9 as a regex.

But note that as we are programming in C++, we need to use the C++ specific escape sequence as follows:

[\\[0-9]


Repeated Pattern:
An expression modifier can be “+” that suggests matching the occurrence of a pattern one or more times or it can be “*” that
suggests matching the occurrence of a pattern zero or more times.An expression modifier can be “+” that suggests matching
the occurrence of a pattern one or more times or it can be “*” that suggests matching the occurrence of a pattern zero or more times.

[a-z]+ matches the strings like a, aaa, abcd, softwaretestinghelp, etc. Note that it will never match a blank string.

The expression,

[a-z]* will match a blank string or any of the above strings.

If you want to specify a group of characters to match one or more times, then you can use the parentheses as follows:

(Xyz)+

The above expression will match Xyz, XyzXyz, and XyzXyzXyz, etc.


C++ regex Example:
Consider a regular expression that matches an MS-DOS filename as shown below.

char regex_filename[] = “[a-zA-Z_] [a-zA-Z_0-9]*\\.[a-zA-Z0-9]+”;

The above regex can be interpreted as follows:

Match a letter (lowercase and then uppercase) or an underscore. Then match zero or more characters, in which each may be a letter,
or an underscore or a digit. Then match a literal dot (.). After the dot, match one or more characters, in which each may be a
letter or digit indicating file extension.


Function Templates Used In C++ Regex:
regex_match()
This function template is used to match the given pattern. This function returns true if the given expression matches the string.
Otherwise, the function returns false.


#include <regex>

if (regex_match ("softwareTesting", regex("(soft)(.*)") ))
      cout << "string:literal => matched\n";

      int main () {

         if (regex_match ("softwareTesting", regex("(soft)(.*)") ))
            cout << "string:literal => matched\n";

         const char mystr[] = "SoftwareTestingHelp";
         string str ("software");
         regex str_expr ("(soft)(.*)");

         if (regex_match (str,str_expr))
            cout << "string:object => matched\n";

         if ( regex_match ( str.begin(), str.end(), str_expr ) )
            cout << "string:range(begin-end)=> matched\n";

         cmatch cm;
         regex_match (mystr,cm,str_expr);

         smatch sm;
         regex_match (str,sm,str_expr);

         regex_match ( str.cbegin(), str.cend(), sm, str_expr);
         cout << "String:range, size:" << sm.size() << " matches\n";


         regex_match ( mystr, cm, str_expr, regex_constants::match_default );

         cout << "the matches are: ";
         for (unsigned i=0; i<sm.size(); ++i) {
            cout << "[" << sm[i] << "] ";
         }

         cout << endl;

         return 0;
      }


regex_search():

int main()
{
    //string to be searched
    string mystr = "She sells_sea shells in the sea shore";

    // regex expression for pattern to be searched
    regex regexp("s[a-z_]+");

    // flag type for determining the matching behavior (in this case on string objects)
     smatch m;

    // regex_search that searches pattern regexp in the string mystr
    regex_search(mystr, m, regexp);

    cout<<"String that matches the pattern:"<<endl;
    for (auto x : m)
        cout << x << " ";
    return 0;
}



regex_replace():

int main()
{
    string mystr = "This is software testing Help portal \n";

    cout<<"Input string: "<<mystr<<endl;

    // regex to match string beginning with 'p'
    regex regexp("p[a-zA-z]+");
    cout<<"Replace the word 'portal' with word 'website' : ";
    // regex_replace() for replacing the match with the word 'website'
    cout << regex_replace(mystr, regexp, "website");

    string result;

    cout<<"Replace the word 'website' back to 'portal': ";
    // regex_replace( ) for replacing the match back with 'portal'
    regex_replace(back_inserter(result), mystr.begin(), mystr.end(),
                  regexp,  "portal");

    cout << result;

    return 0;
}


From linuxhint:

regex reg("man");
Regex is a type, and reg is the regex object

Regexes are usually not that simple. Regular expressions have metacharacters. Metacharacters are characters with special meanings.
A metacharacter is a character about characters. C++ regex metacharacters are:

^ $ \ . * + ? ( ) [ ] { } |
A regex, with or without metacharacters, is a pattern.

Note: The hyphen – is a metacharacter only within square brackets, indicating a range. It is not a metacharacter in the regex,
outside of the square brackets.

Character Classes
Square Brackets:  a particular position in the target string would match any of the square brackets’ characters

regex reg("[cbr]at");
The class, [cbr] in the pattern [cbr], would match several possible characters in the target. It would match ‘c’ or ‘b’ or ‘r’ in the target. If the target does not have any of ‘c’ or ‘b’ or ‘r’, followed by “at”, there would be no match.

The range of uppercase alphabets, A to Z, has 26 possibilities, and the pattern for that is [A-Z]. – is not officially a metacharacter,
but within square brackets, it would indicate a range.


Negation:
This is indicated with the ^ metacharacter at the beginning of the class pattern.
So, [^0-9] means matching the character at the appropriate position in the target, which is not any character in the range, 0 to 9 inclusive.

Matching Whitespaces:
‘ ’ or \t or \r or \n or \f is a whitespace character. In the following code, the regex, “\n” matches ‘\n’ in the target:

Matching any Whitespace Character:
if (regex_search("one two", regex("[ \t\r\n\f]")))

  cout << "matched" << endl;

The period (.) in the Pattern:
The period (.) in the pattern matches any character including itself, except \n, in the target. A match is produced in the following code:
if (regex_search("1234abcd", regex(".")))
  cout << "matched" << endl;


Matching Repetitions:

The metacharacters, ?, *, +, and {} are used to match the repetition in the target.
If x is a character of interest in the target string, then the metacharacters have the following meanings:

x*: means match 'x' 0 or more times, i.e., any number of times

x+: means match 'x' 1 or more times, i.e., at least once

x? : means match 'x' 0 or 1 time

x{n,}: means match 'x' at least n or more times. Note the comma.

x{n} : match 'x' exactly n times

x{n,m}: match 'x' at least n times, but not more than m times.
These metacharacters are called quantifiers.


Matching Beginning or End
Beginning:
If ^ is at the beginning of the regex, then the beginning text of the target string can be matched by the regex. In the following code, the start of the target is “abc”, which is matched:

if (regex_search("abc and def", regex("^abc")))

  cout << "matched" << endl;

End:
If $ is at the end of the regex, then the ending text of the target string can be matched by the regex. In the following code, the end of the target is “xyz”, which is matched:

if (regex_search("uvw and xyz", regex("xyz$")))

  cout << "matched" << endl;

  Grouping:
  Parentheses can be used to group characters in a pattern. Consider the following regex:

  "a concert (pianist)"
  The group here is “pianist” surrounded by the metacharacters ( and ). It is actually a sub-group, while “a concert (pianist)” is the whole group

Sub-strings with Common Parts:

Assume that the programmer’s interest is not to know which of these sentences is in the computer. Still, his interest is to know if “bookshelf” or
“bookkeeper” is present in whatever target string is in the computer. In this case, his regex can be:

"bookshelf|bookkeeper."
Notice that “book”, which is common to both words, has been typed twice, in the two words in the pattern.
To avoid typing “book” twice, the regex would be better written as:
"book(shelf|keeper)"


The icase and multiline regex_constants
icase
Matching is case sensitive by default. However, it can be made case insensitive. To achieve this, use the regex::icase constant, as in the following code:

if (regex_search("Feedback", regex("feed", regex::icase)))
  cout << "matched" << endl;
The output is “matched”. So “Feedback” with uppercase ‘F’ has been matched by “feed” with lowercase ‘f’. “regex::icase” has been made the second
argument of the regex() constructor. Without that, the statement would not produce a match.
