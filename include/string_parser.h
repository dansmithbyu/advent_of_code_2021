#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <string>

bool find_space_in_string(std::string str_in, size_t* index)
{
    size_t found = str_in.find(" ");
    if(found != std::string::npos)
    {
        *index = found;
        return true;
    }
    return false;
}

std::string string_before_space(std::string string_in, size_t space_index)
{
    return string_in.substr(0, space_index);
}

std::string string_after_space(std::string string_in, size_t space_index)
{
    return string_in.substr(space_index + 1, string_in.size() - 1);
}

std::vector<int> substrings_to_ints(std::string string, std::string delimeter)
{
    std::vector<int> ints;
    std::stringstream s_stream(string);
    while(s_stream.good())
    {
        std::string substr;
        std::getline(s_stream, substr, *(delimeter.c_str())); //get first string delimited by comma
        if(substr == "")
            continue;
        ints.push_back(std::stoi(substr));
    }
    return ints;
}

#endif // STRING_PARSER_H