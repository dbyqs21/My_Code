import math
def main():
    print('this program finds the real solutions to a quadratic.\n')
    try:
        a,b,c=input("please input the coefficients (a,b,c)")
        discRoot=math.sqrt(b*b-4*a*c)
        root1=(-b+discRoot)/(2*a)
        root2=(-b-discRoot)/(2*a)
        print("\nThe solution are:",root1,root2)
    except ValueError as excObj:
        if str(excObj) == "math domain error":
            print('No real Roots')
        else:
            print("You didn't give me the right number of coefficient")
    except NameError:
        print("\nYou didn't enter three numbers")
    except TypeError:
        printf("\nYou inputs were not all numbers")
    except SyntaxError:
        print("\nYour inputs was not in the correct form Missing comma")
    except:
        print("\nSomething went wrong!")
main()
            
            
        
        
