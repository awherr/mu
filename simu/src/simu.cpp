#include <CLI/CLI.hpp>
#include <iostream>
#include <string>
#include "mu.h"
struct VMAPP : CLI::App{
    VMAPP():CLI::App("Mu Simulator"){
        add_option("-o,--file", m_file_name, "Specify the file location of the input");
    }
    std::string m_file_name; 
};

int main(int argc, char **argv) {
    VMAPP app;
    CLI11_PARSE(app, argc, argv);

 //   auto m = mu();
    return 0;
}