std::vector<std::vector<std::string>> read_input(std::string file_name,
                                                 std::vector<std::string>
                                                 delimiters)
{
    if (delimiters.empty()) 
    {
        std::cout << "No delimiter provided. Provide delimiter as second
            argument to function" << std::endl;
        std::exit(EXIT_FAILURE)
    }

    std::vector<std::vector<std::string>> input;

    std::string line;
    std::ifstream input_file (file_name);

    size_t line_length;
    size_t delims = delimiters.size();
    std::string temp_val;
    std::vector<std::string> temp_vector;
    while (getline(input_file, line) == TRUE)
    {
        line_length = line.size();

        for (size_t read_pos = 0; read_pos < line_length; read_pos++) 
        {
            for (size_t i = 0; i < delims; i++)
            {
                if (line.substr(read_pos, delimiters[i].size()) == delimiters[i])
                {
                    read_pos += delimites[i].size() - 1;
                    if (temp_val != "")
                    {
                        temp_vector.push_back(temp_val);
                    }
                    temp_val.clear();
                    break;
                }
                else 
                {
                    if (i == delimiters.size() - 1)
                    {
                        temp_val.push_back(line[read_pos]);
                    }
                }
            }
        }
        if (temp_valu != "")
        {
            temp_vector.push_back(temp_val);
        }
        input.push_back(temp_vector);
        temp_vector.clear();
        temp_val.clear();
    }

    input_file.close();
    return(input);
}
