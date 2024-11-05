def xyz_there(str):
    if(len(str) <= 3):
        return (str == 'xyz')
    if(str[0:3] == 'xyz'):
        return True
    for i in range(len(str) - 3):
        if(str[i] != '.' and str[i+1:i+4] == 'xyz'):
            return True
    
    return False