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
        std::cout << "i" << endl;
    }
};

class EmailAlert : public IAlerter
{
    public:
    EmailAlert()
    {
        emailSent = 0;
    }
    void displayEmail()
    {
        std::cout << "DemailSent : " << emailSent << std::endl;
    }
    
    void SetAlerter(int i)
    {
        emailSent = i;
    }
    int emailSent;
};

class LEDAlert : public IAlerter
{
    public:
    LEDAlert()
    {
        ledGlows = 0;
    }
    void displayLed()
    {
        std::cout << "ledGlows : " << ledGlows <<std::endl;
    }
    
    void SetAlerter(int i)
    {
        ledGlows = i;
    }
    
    int ledGlows;
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

