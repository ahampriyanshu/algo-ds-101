#a=starting term , d=difference , n=number of terms
def harmonic_progression(a,d,n):
    for i in range(0,n):
        print("1/"+ str(a+(i*d)), end = "\t")
        
a,d,n = float(input("Enter starting term")),float(input("Enter difference")),int(input("Enter number of terms"))
harmonic_progression(a,d,n)
