class Solution {
    public:
       int calculate_power(int n)
{
    int i = 1;
    int counter = -1;
    while (i <= n)
    {
        i = i * 2;
        counter++;
    }
    return counter;
}

int josephus(int n)
{
    int x = calculate_power(n);
    int l = n - pow(2, x);
    return 2 * l + 1;
}
 int solution(int n,int k){
        if(n==1) return 0;
        int x=solution(n-1,k);
        int y=(x+k)%n;
        return y;
    }
    int findTheWinner(int n, int k) {
        if(k==2) return josephus(n);
       int z=solution(n,k);
        return z+1;

    }
};