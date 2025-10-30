from scipy.stats import norm
import math

def weekly_order(daily_mean, days, service_level):
    """
    Calculate the number of items to order to meet a desired service level.
    
    Parameters:
    - daily_mean: average number of items sold per day
    - days: number of days in the period
    - service_level: desired probability of not running out (e.g., 0.9)
    
    Returns:
    - number of items to order (rounded up)
    """
    # Step 1: Compute weekly mean and standard deviation (Poisson approximation)
    mu = daily_mean * days
    sigma = math.sqrt(mu)  # variance = mean for Poisson
    
    # Step 2: Find z-score for desired service level
    z = norm.ppf(service_level)
    
    # Step 3: Compute the required number of items
    x = mu + z * sigma
    
    # Round up to nearest whole item
    return math.ceil(x)

# Example usage
daily_mean = 3.75
days = 7
service_level = 0.9

order_quantity = weekly_order(daily_mean, days, service_level)
print(f"Order {order_quantity} items for the week to be {service_level*100:.0f}% sure you don't run out.")
