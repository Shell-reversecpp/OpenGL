//
// Created by snake0x8 on 2/2/24.
//

#ifndef OPENGL_HIGHRESOLUTIONTIMER_H
#define OPENGL_HIGHRESOLUTIONTIMER_H


#include "common.h"

class CHighResolutionTimer
{
public:
    CHighResolutionTimer();
    ~CHighResolutionTimer();

    void Start();
    double Elapsed();

private:
    chrono::high_resolution_clock::time_point m_t1, m_t2;
    bool m_bStarted;
};

#endif //OPENGL_HIGHRESOLUTIONTIMER_H
