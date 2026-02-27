n=int(input()) 
S=0   
jc=1
for i in range(1,n+1):
    jc*=i  
    S+=jc 
print(S)       