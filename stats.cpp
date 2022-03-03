#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>&  data) {
    //Implement statistics here
    
    Stats mystats;
    float sum;
    int count;
    
    mystats.m_max = *max_element(data.begin(),data.end());
    mystats.m_min = *min_element(data.begin(),data.end());
    sum=accumulate(data.begin(), data.end() , 0);
    count = data.size();
    mystats.m_avg=(sum/count);
    return mystats;
    
}
