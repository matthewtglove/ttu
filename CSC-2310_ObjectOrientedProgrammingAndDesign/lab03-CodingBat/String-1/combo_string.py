def combo_string(a, b):
    if(len(a) > len(b)):
        long = a
        short = b
    else:
        long = b
        short = a
    
    return short + long + short