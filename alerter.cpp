#include <alerter.h>
#include <stats.h>


    
int StatsAlerter::checkAndAlert(std::vector<float> data)
{
        auto computedStats = Statistics::ComputeStatistics(data);

        if(computedStats.m_max > m_maxThreshold)
        {
            alerter[0]->SetAlerter(10);
            alerter[1]->SetAlerter(10);
           return 1;   
        }
        else
        {
           return 0;
        }
        
}
