#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
           char curr_type = opening_brackets_stack.top().type;
           std::cout<<curr_type<<std::endl;
           bool match = opening_brackets_stack.top().Matchc(curr_type);
        //    if(match == false){
        //        break; 
        //    }
           opening_brackets_stack.pop();
        }
    }

    if(opening_brackets_stack.empty() == true){
        std::cout<<"Success";
    }else{
        std::cout<<text.length();
    }

    return 0;
}
