
#include <fstream>
#include <vector>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include "pessoa.h"
#include <iostream>

using namespace std;

class ReadCsv{
    public:
    ReadCsv();
    vector<pessoa> read_csv(string filename);
};

ReadCsv::ReadCsv(){}
vector<pessoa> read_csv(string filename){
    // Reads a CSV file into a vector of <string, vector<int>> pairs where
    // each pair represents <column name, column values>

    // Create a vector of <string, int vector> pairs to store the result
    vector<pessoa> result;

    // Create an input filestream
    ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    // Helper vars
    stringstream colname;
    string line;
    //sstring line, colname;1
    string val;

    // Read data, line by line
    int cont = 0;
    while(std::getline(myFile, line))
    {
        
        pessoa p;
        // Create a stringstream of the current line
        stringstream ss(line);
        string token;
        
        int i = 0;
       while(std::getline(ss, token, ',')) {
           
            if(i == 0){
                string temp = token.substr(0,3) + token.substr(4,3) + token.substr(8,3) + token.substr(12,2)  ;
                p.cpf = temp;
            }
            else if(i == 1){
                p.nome = token;
            }
            else if(i == 2){
                p.snome = token;
            }
            else if(i == 3){
                p.nasc = token;
            }
            else if(i == 4){
                p.cidade = token;  
            }
            i++;
            if(i > 4)
                i = 0;  
                  
        }
            if(cont != 0)
                result.push_back(p);
            cont++;        

       
    }


    // Close file
    myFile.close();

    return result;
}

