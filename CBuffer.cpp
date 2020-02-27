//
//  CBuffer.cpp
//  CBuffer
//
//  Created by Manoj Kumar Enaganti on 2/25/20.
//  Copyright © 2020 Manoj Kumar Enaganti. All rights reserved.
//

#include <iostream>
#include "CBuffer.h"

CBuffer::CBuffer():
m_bufferCurrentSize(0),
m_readIndex(0),
m_writeIndex(0)
{
    
}

CBuffer::CBuffer(int maxBufferSize):
m_maxBufferSize(maxBufferSize),
m_bufferCurrentSize(0),
m_readIndex(0),
m_writeIndex(0)
{
    m_cBuffer.reserve(maxBufferSize);
}

CBuffer::~CBuffer()
{
    
}

bool CBuffer::writeto(uint8_t byte)
{
    if(isFull())
    {
        return false;
    }
    m_cBuffer[m_writeIndex++] = byte;
    m_bufferCurrentSize++;
    if (m_writeIndex > m_maxBufferSize - 1)
    {
        m_writeIndex = 0;
    }
    return true;
}

bool CBuffer::readfrom(uint8_t &byte)
{
    if (isEmpty())
    {
        return false;
    }
    byte = m_cBuffer[m_readIndex++];
    m_bufferCurrentSize--;
    if (m_readIndex > m_maxBufferSize - 1)
    {
        m_readIndex = 0;
    }
    return true;
}

bool CBuffer::isFull()
{
    return (m_maxBufferSize == m_bufferCurrentSize);
}

bool CBuffer::isEmpty()
{
    return (m_bufferCurrentSize == 0);
}

int CBuffer::getSize()
{
    return (int)m_cBuffer.size();
}

