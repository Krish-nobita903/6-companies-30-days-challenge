#define ll long long int
ll gcd(ll a, ll b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
}   
ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
} 
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll ans = 1e18;
        ll low = 1;
        ll high = 1e18;
        ll d = lcm((ll)divisor1,(ll)divisor2);
        while(low<=high)
        {
            ll mid = (low+high)/2;
            ll a = mid-(mid/divisor1);
            ll b = mid-(mid/divisor2);
            ll c = mid-(mid/divisor1)-(mid/divisor2)+(mid/d);
            //cout<<low<<" "<<high<<" "<<mid<<"\n";
            //cout<<a<<" "<<b<<" "<<c<<" "<<a+b-c<<" "<<uniqueCnt1+uniqueCnt2<<"\n";
            if(a>=uniqueCnt1 && b>=uniqueCnt2 && a+b-c>=uniqueCnt1+uniqueCnt2)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return (int)ans;
    }
};




/*


Logic:

This is one of the classic binary search and number theory problem and set theory

We can binary search to check if it is possible for given mid the answer with the 3 conditions 

we calculate 
i) numbers which are not divisible by divisor1
ii) numbers which are not divisible by divisor2
iii) numbers which are not divisible by divisor1 and divisor2

i) -> mid - (mid/divisor1)
ii)-> mid - (mid/divisor2)
iii)->mid - (mid/divisor1) - (mid/divisor2) + (mid/lcm(divisor1,divisor2))

so if i >= uniquecnt1 and ii >= uniquecnt2 and i+ii-iii>= uniquecnt1+uniquecnt2 so given mid can be part ofthe maximum

*/
