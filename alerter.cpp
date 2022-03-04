#include "alerter.h"
#include "stats.h"


    
void StatsAlerter::checkAndAlert(std::vector<float> data)
{
        auto computedStats = Statistics::ComputeStatistics(data);

        if(computedStats.m_max > m_maxThreshold)
        {
            alerter[0]->SetAlerter(1);
            alerter[1]->SetAlerter(1);  
        }
        else
        {
            
        }
     return;   
}
