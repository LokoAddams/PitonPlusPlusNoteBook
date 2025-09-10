// O(n)
// pr contains prime numbers
// lp[i] == i if i is prime
// else lp[i] is minimum prime factor of i
const int nax = 1e7;
int lp[nax+1];//because lp is an array nax have to be less than 1e7 or change to a vector(nax+1,0)
vector<int> pr; // It can be sped up if change for an array

void sieve(){
  form(i,2,nax){
    if (lp[i] == 0) {
      lp[i] = i; pr.pb(i);
    }
    for (int j=0, mult= i*pr[j]; j<sz(pr) && pr[j]<=lp[i] && mult<nax; ++j, mult= i*pr[j])
      lp[mult] = pr[j];
  }
}
