#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// assume the format is correct
int main (int argc, char* argv[]){

    if (argc < 2 || argc > 3){
        cout << "usage: reduce <in_file><out_file>" << endl;
        exit(1);
    }

    char * inFile = argv[1];
    char * outfile = argv[2];

    ifstream in_file;
    in_file.open(inFile);

    if(!in_file){
        cout << "fail to open in_file" << endl;
        exit(1);
    }

    string content;

    int lineCnt = 0;
    int m = 0;
    int n = 0;

    string result = "";

    int flag = 0;


    //reading data
    while (getline (in_file, content)) {

        if (lineCnt == 0){
            m = stoi(content);
        }else if (lineCnt == 1){
            n = stoi(content);
        }else if ((lineCnt -2 ) < n  ){ //new modify

            result += "(";

            for (int i =0 ; i < m; i ++){

                char tar = i + 65;
                if(tar >= 70){
                    tar ++;
                }
                if (tar >= 84){
                    tar ++;
                }

                if(content.at(i) == '0'){
                    result += "!" ;
                    result += tar;
                }else if (content.at(i) == '1'){
                    result += tar;
                }
                if(i < m-1){
                    result += "^";
                }
                
            }
            
            if((lineCnt -2) < n-1)
                result += ")or";
            else{
                result += ")";
            }

        }
        lineCnt ++;
    }
    in_file.close();

    size_t found = result.find( "^^");
    while(found!=std::string::npos){
        result.replace(found, 2 , "^");
        found = result.find( "^^");
    }

    found = result.find("(^");
    while(found!=std::string::npos){
        result.replace(found, 2 , "(");
        found = result.find("(^");
    }

    found = result.find("^)");
    while(found!=std::string::npos){
        result.replace(found, 2 , ")");
        found = result.find("^)");
    }

    ofstream out_file(outfile);
    out_file << result;
    out_file.close();



    return 0;
}

