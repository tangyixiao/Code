for _ in range(int(input())):               
    s = input().replace('=', '==')            
    print(eval(s) and 'Right!' or 'Wrong!')   
