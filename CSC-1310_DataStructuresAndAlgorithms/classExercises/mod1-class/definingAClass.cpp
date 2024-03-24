/*
    Author: Matthew Love
    Date: 2024-01-23, Tue
    Purpose: Practice decalring a class
*/

class Planet
{
private:
    float minSurfaceTemperature = -40;
    float maxSurfaceTemperature = 890;
    float size = 160000;

public:
    float getMinSurfaceTemperature()
    {
        return minSurfaceTemperature;
    }
    void setMinSurfaceTemperature(float value)
    {
        minSurfaceTemperature = value;
    }

    float getMaxSurfaceTemperature()
    {
        return maxSurfaceTemperature;
    }
    void setMaxSurfaceTemperature(float value)
    {
        maxSurfaceTemperature = value;
    }

    float getSize()
    {
        return size;
    }
    void setSize(float value)
    {
        size = value;
    }
};