#include "stats.h"

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>&  data) {
    //Implement statistics here
    
    Stats mystats;
    float sum = 0.0;
    int count = 0;
    
    mystats.m_max = *max_element(data.begin(),data.end());
    mystats.m_min = *min_element(data.begin(),data.end());
    
      for (int i = 0; i < data.size(); i++)
      {
        sum +=data[i];
      }
    count = data.size();
    mystats.m_avg=(sum/count);
    return mystats;
    
}
