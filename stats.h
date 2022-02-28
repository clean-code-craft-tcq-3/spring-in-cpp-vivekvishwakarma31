#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


namespace Statistics {
    
    class Stats
    {
      public:
        float m_avg;
        float m_max;
        float m_min;
        Stats()// Default Constructor
        {
            
        }
        Stats(float avg, float max, float min)
        {
          m_avg = avg;
          m_max = max;
          m_min = min; 
        }
    }
    
    Stats ComputeStatistics(const std::vector<float>& );
}
