//
//  CBuffer.h
//  CBuffer
//
//  Created by Manoj Kumar Enaganti on 2/25/20.
//  Copyright © 2020 Manoj Kumar Enaganti. All rights reserved.
//

#ifndef CBuffer_h
#define CBuffer_h

#include <vector>

class CBuffer
{
public:
    CBuffer();
    CBuffer(int maxBufferSize);
    ~CBuffer();
    
    bool writeto(uint8_t byte);
    bool readfrom(uint8_t &byte);
    bool isFull();
    bool isEmpty();
    void setSize(int n);
    int getSize();
private:
    bool m_isFull;
    //bool m_isEmpty;
    int m_readIndex;
    int m_writeIndex;
    int m_maxBufferSize;
    int m_bufferCurrentSize;
    std::vector<uint8_t> m_cBuffer;
};
#endif /* CBuffer_h */
