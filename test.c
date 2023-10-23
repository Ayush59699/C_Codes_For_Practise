#include <stdio.h>
#include <math.h>
int main(){
    int num,onum,rem,res=0,n=0; 
    printf("Enter an Integer:"); 
    scanf("%d",&num);
    onum=num;
    while(onum!=0){
        rem=onum%10;
        res+= pow(rem,n); 
        onum/=10;
    }
    if(res==num){
        printf("Armstrong\n");
    } 
    else{
        printf("Not\n");
    } 
    return 0;
}



























/*#include <stdio.h>
int main(){
    int n,f=0; 
    printf("Enter an Integer "); 
    scanf("%d",&n); 
    for(int i=2;i<n;i++){
        if(n%i==0){
            f=1;
            break; 
        }
    }
    if(f==1){
        printf(" 1 is not prime not composite");}
    else{
        if(f==0){
            printf("PRIME\n");
        }
        else{
            printf("Not Prime\n");
        }
    }
    return 0;
}
*/

/*#include <stdio.h>
int main(){
    int n,sum=0,rem;
    printf("Enter an Integer:");
    scanf("%d",&n);
    while(n!=0){
        rem=n%10;
        sum=sum+rem;
        n=n/10;
    }
    printf("SUM of digits:",sum);
    return 0;
}
*/
/*#include <stdio.h>
void main()
{
    int n,rev=0,orig,rem;
    printf("Enter the Integer:");
    scanf("%d",&n);
    orig=n;
    while(n!=0){
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;
    }
    if(orig==rev){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    
}
*/

/*#include <stdio.h>
int main(){
    int f=1,n;
    printf("Enter an integer:");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        f=f*i;
    }
    printf("Factorial:%d\n",f);
}*/


/*#include <stdio.h>
int main(){
    int a,b,c;
    printf("Enter 3 numbers:\n");
    scanf("%d %d %d", &a,&b,&c);
    if(a>b && a>c){printf("%d is largest\n",a);}
    if(b>a && b>c){printf("%d is largest\n",b);}
    if(c>a && c>b){printf("%d is largest\n",c);}
    return 0;
}*/

/*#include <stdio.h>
int main(){
    printf("Enter 2 numbers:\n");
    int a,b;
    scanf("%d %d", &a,&b);
    printf("Sum:%d \n",a+b);
    return 0;
}*/