//
// Created by snake0x8 on 2/2/24.
//

#include "HighResolutionTimer.h"


CHighResolutionTimer::CHighResolutionTimer() :
        m_bStarted(false)
{
}

CHighResolutionTimer::~CHighResolutionTimer()
{
}

void CHighResolutionTimer::Start()
{
    m_bStarted = true;
    m_t1 = std::chrono::high_resolution_clock::now();
}

double CHighResolutionTimer::Elapsed()
{
    if (!m_bStarted)
        return 0.0;

    m_t2 = std::chrono::high_resolution_clock::now();

    // Return the elapsed time in seconds
    return std::chrono::duration_cast<std::chrono::duration<double>>(m_t2 - m_t1).count();
}