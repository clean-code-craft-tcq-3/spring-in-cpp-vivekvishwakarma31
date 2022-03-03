#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class IAlerter
{
    public:
    IAlerter()
    {
    
    }
    virtual void SetAlerter(int i)
    {
        
    }
};

class EmailAlert : public IAlerter
{
    public:
    EmailAlert()
    {
        DemailSent = 0;
    }
    void displayEmail()
    {
        std::cout << "DemailSent : " << DemailSent << std::endl;
    }
    
    void SetAlerter(int i)
    {
        DemailSent = i;
    }
    int DemailSent;
};

class LEDAlert : public IAlerter
{
    public:
    LEDAlert()
    {
        DledGlows = 0;
    }
    void displayLed()
    {
        std::cout << "DledGlows : " << DledGlows <<std::endl;
    }
    
    void SetAlerter(int i)
    {
        DledGlows = i;
    }
    
    int DledGlows;
};

class StatsAlerter 
{
    
    public:
    StatsAlerter()
    {
        
    }
    
    StatsAlerter(float f1, std::vector<IAlerter*> palerters)
    {
        m_maxThreshold = f1;
        alerter = palerters;
    }
    
    void checkAndAlert(std::vector<float> data);
    
    float m_maxThreshold;
    std::vector<IAlerter*> alerter;
};

