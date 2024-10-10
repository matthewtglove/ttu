def count_code(str):
    if(len(str) < 4):
        return 0
    count = 0
    for i in range(len(str) - 3):
        if(str[i:i+2] == "co" and str[i+3] == 'e'):
            count = count + 1
        
    return count