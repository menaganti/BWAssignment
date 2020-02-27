//
//  main.cpp
//  CBuffer
//
//  Created by Manoj Kumar Enaganti on 2/25/20.
//  Copyright © 2020 Manoj Kumar Enaganti. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "CBuffer.h"

using namespace std;

int main(int argc, const char * argv[])
{
    CBuffer cBuffer = CBuffer(10);
    
    ifstream myFileReader("/Users/menaganti/Documents/Programming/myReadFile.txt", ios::in | ios::binary);
    ofstream myFileWriter("/Users/menaganti/Documents/Programming/myWriteFile.txt", ios::out | ios::binary);
    char byte;
    //cout<<"Start... "<<"\n";
    while(myFileReader.good())
    {
        myFileReader.read(&byte,1);
        //cout<<"bytefromfile: "<<byte<<"\n";
        if(!cBuffer.writeto((uint8_t)byte))
        {
            //cout<<"Write to buffer successful\n";
            uint8_t byte;
            while(cBuffer.readfrom(byte))
            {
                //cout<<"readfrombuffer: "<<byte<<"\n";
                myFileWriter.write((char*)&byte,1);
            }
        }
    }
    if (!cBuffer.isEmpty())
    {
        uint8_t byte;
        while(cBuffer.readfrom(byte))
        {
            myFileWriter.write((char*)&byte,1);
        }
    }
    return 0;
}
